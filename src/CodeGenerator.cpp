#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/Type.h>
#include <llvm/ADT/Twine.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <string>
#include <vector>
#include "CodeGenerator.hpp"

llvm::LLVMContext Context; //定义全局context
llvm::IRBuilder<> IRBuilder(Context); //定义全局IRbuilder

//Constructor
CodeGenerator::CodeGenerator(void) :
	Module(new llvm::Module("main", Context)),
	CurrFunction(NULL),
	SymbolTableStack()
	ConditionBlockStack(),
	EndBlockStack()
{}

//Create and push an empty symbol table
void CodeGenerator::PushSymbolTable(void) {
	this->SymbolTableStack.push_back(new SymbolTable);
}

//Remove the last symbol table
void CodeGenerator::PopSymbolTable(void) {
	if (this->SymbolTableStack.size() == 0) return;
	delete this->SymbolTableStack.back();
	this->SymbolTableStack.pop_back();
}

llvm::Function* CodeGenerator::FindFunction(std::string Name){
	if (this->SymbolTableStack.size() == 0) return NULL;
	for (auto TableIter = this->SymbolTableStack.end() - 1; TableIter >= this->SymbolTableStack.begin(); TableIter--) {
		auto PairIter = (**TableIter).find(Name);
		if (PairIter != (**TableIter).end())
			return PairIter->second.GetFunction();
	}
	return NULL;
}

// Add a function to the current symbol table
// If an old value exists (i.e., conflict), return false
bool CodeGenerator::AddFunction(std::string Name, llvm::Function* Function){
	if (this->SymbolTableStack.size() == 0) return false;
	auto& TopTable = *(this->SymbolTableStack.back());
	auto PairIter = TopTable.find(Name);
	if (PairIter != TopTable.end())
		return false;
	TopTable[Name] = Symbol(Function);
	return true;
}

// std::vector<SymbolTable*> SymbolTableStack;
// iter is iterator to symboltable stack
// *iter is the element of symboltable stack, which is pointer to symboltable
// **iter is symboltable
// using SymbolTable = std::map<std::string, Symbol>;
// so return iter->second.GetVariable() which is (llvm::Value*)Content, that is the poiter to value

//Add a variable to the current symbol table
//If an old value exists (i.e., conflict), return false
llvm::Value* CodeGenerator::FindVariable(std::string Name){
	//先找局部变量
	if (this->SymbolTableStack.size() == 0) return NULL;
	for (auto TableIter = this->SymbolTableStack.end() - 1; TableIter >= this->SymbolTableStack.begin(); TableIter--) {
		auto PairIter = (**TableIter).find(Name);
		if (PairIter != (**TableIter).end())
			return PairIter->second.GetVariable();
	}

	return NULL;
	// //再找全局变量
	// return this->Module->getGlobalVariable(Name, true);
}

bool CodeGenerator::AddVariable(std::string Name, llvm::Value* Variable){
	if (this->SymbolTableStack.size() == 0) return false;
	auto& TopTable = *(this->SymbolTableStack.back());
	auto PairIter = TopTable.find(Name);
	if (PairIter != TopTable.end())
		return false;
	TopTable[Name] = Symbol(Variable);
	return true;
}

//Set current function
void CodeGenerator::EnterFunction(llvm::Function* Func) {  //为了降重可以直接把body复制到caller的地方
	this->CurrFunction = Func;
}

//Remove current function
void CodeGenerator::LeaveFunction(void) { //为了降重可以直接把body复制到caller的地方
	this->CurrFunction = NULL;
}

llvm::Function* CodeGenerator::GetCurrentFunction(void){ //为了降重可以直接把body复制到caller的地方
	return this->CurrFunction;
}

void CodeGenerator::EnterLoop(llvm::BasicBlock* ConditionBB, llvm::BasicBlock* EndBB){
	this->ConditionBlockStack.push_back(ConditionBB);
	this->EndBlockStack.push_back(EndBB);
}

void CodeGenerator::LeaveLoop(void){
	if (this->ConditionBlockStack.size() != 0)
		this->ConditionBlockStack.pop_back();
	if (this->EndBlockStack.size() != 0)
		this->EndBlockStack.pop_back();
}

llvm::BasicBlock* CodeGenerator::GetConditionBlock(void){
	if (this->ConditionBlockStack.size())
		return this->ConditionBlockStack.back();
	else
		return NULL;
}

llvm::BasicBlock* CodeGenerator::GetEndBlock(void){
	if (this->EndBlockStack.size())
		return this->EndBlockStack.back();
	else
		return NULL;
}


void CodeGenerator:: GenIR(Block* programBlock,const string& filename ){
	program->codeGen(*this);
	llvm::verifyModule(*this->Module, &llvm::outs());
    std::error_code EC;
    llvm::raw_fd_ostream dest(filename, EC, llvm::sys::fs::F_None);
	if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return;
    }
    this->Module->print(dest, nullptr);
}


