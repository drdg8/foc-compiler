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
	SymbolTableStack(),
	ConditionBlockStack(),
	EndBlockStack(),
	GlobalBB(),
	GlobalFunc()
{
	this->printf = GenPrintf();
    this->scanf = GenScanf();

}

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

	// return NULL;
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

void CodeGenerator::ChangeToGlobalBB(){
	auto Tmp = IRBuilder.GetInsertBlock();
	this->TmpBB = Tmp;
	IRBuilder.SetInsertPoint(this->GlobalBB);
}

void CodeGenerator::ChangeToTmpBB(){
	IRBuilder.SetInsertPoint(this->TmpBB);
	this->TmpBB = NULL;
}

void CodeGenerator::GenerateCode(Block *Root){
	// initialize symbol table
	this->PushSymbolTable();

	this->GlobalFunc = llvm::Function::Create(llvm::FunctionType::get(IRBuilder.getVoidTy(), false), llvm::GlobalValue::InternalLinkage, "0Global", this->Module);
	this->GlobalBB = llvm::BasicBlock::Create(Context, "Temp", this->GlobalFunc);
    Root->codeGen(*this);

	std::cout << "Gen Successfully" << std::endl;

	//Delete GlobalBB and GlobalFunc
	this->GlobalBB->eraseFromParent();
	this->GlobalFunc->eraseFromParent();

	//Delete symbol table
	this->PopSymbolTable();

}

void CodeGenerator:: GenIR(const string& filename ){
	llvm::verifyModule(*this->Module, &llvm::outs());
	
	std::error_code EC;
	llvm::raw_fd_ostream dest(filename, EC);
	if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return;
    }
    this->Module->print(dest, nullptr);
}

llvm::Function* CodeGenerator::GenPrintf(){
    vector<llvm::Type*> printf_arg_types; //printf内参数的类型
    printf_arg_types.push_back(IRBuilder.getInt8PtrTy()); //8位代表void*

    llvm::FunctionType* printf_type = 
    llvm::FunctionType::get(IRBuilder.getInt32Ty(),printf_arg_types,true);
    llvm::Function* printf_func = 
    llvm::Function::Create(printf_type,llvm::Function::ExternalLinkage,llvm::Twine("printf"),this->Module);

    printf_func->setCallingConv(llvm::CallingConv::C);
    return printf_func;
}

llvm::Function* CodeGenerator::GenScanf(){
    llvm::FunctionType* scanf_type = 
    llvm::FunctionType::get(IRBuilder.getInt32Ty(),true);
    llvm::Function* scanf_func = 
    llvm::Function::Create(scanf_type,llvm::Function::ExternalLinkage,llvm::Twine("scanf"),this->Module);

    scanf_func->setCallingConv(llvm::CallingConv::C);
    return scanf_func;
}

