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

llvm::Function*  CodeGenerator::FindFunction(std::string Name){
	if (this->SymbolTableStack.size() == 0) return NULL;
	for (auto TableIter = this->SymbolTableStack.end() - 1; TableIter >= this->SymbolTableStack.begin(); TableIter--) {
		auto PairIter = (**TableIter).find(Name);
		if (PairIter != (**TableIter).end())
			return PairIter->second.GetFunction();
	}
	return NULL;
}

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
llvm::Value* CodeGenerator::FindVariable(std::string Name){
	//先找局部变量
	if (this->SymbolTableStack.size() == 0) return NULL;
	for (auto TableIter = this->SymbolTableStack.end() - 1; TableIter >= this->SymbolTableStack.begin(); TableIter--) {
		auto PairIter = (**TableIter).find(Name);
		if (PairIter != (**TableIter).end())
			return PairIter->second.GetVariable();
	}
	//再找全局变量
	return this->Module->getGlobalVariable(Name, true);
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

llvm::Function* CodeGenerator::GetCurrentFunction(void){
	return this->CurrFunction;
}




