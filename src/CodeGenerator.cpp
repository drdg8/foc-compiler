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

llvm::LLVMContext Context; // 全局上下文
llvm::IRBuilder<> IRBuilder(Context); // 全局 IR 构建器

// 构造函数
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

// 查找变量
llvm::Value* CodeGenerator::FindVariable(std::string Name) {
    if (this->SymbolTableStack.size() == 0) return NULL;
    for (auto TableIter = this->SymbolTableStack.end() - 1; TableIter >= this->SymbolTableStack.begin(); TableIter--) {
        auto PairIter = (**TableIter).find(Name);
        if (PairIter != (**TableIter).end())
            return PairIter->second;
    }
    return this->Module->getGlobalVariable(Name, true);
}

// 添加变量到当前符号表
bool CodeGenerator::AddVariable(std::string Name, llvm::Value* Variable){
    if (this->SymbolTableStack.size() == 0) return false;
    auto& TopTable = *(this->SymbolTableStack.back());
    auto PairIter = TopTable.find(Name);
    if (PairIter != TopTable.end())
        return false;
    TopTable[Name] = Variable;
    return true;
}

// 创建并推入一个空的符号表
void CodeGenerator::PushSymbolTable(void) {
    this->SymbolTableStack.push_back(new SymbolTable);
}

// 移除最后一个符号表
void CodeGenerator::PopSymbolTable(void) {
    if (this->SymbolTableStack.size() == 0) return;
    delete this->SymbolTableStack.back();
    this->SymbolTableStack.pop_back();
}


// 设置当前函数
void CodeGenerator::EnterFunction(llvm::Function* Func) {
	this->CurrFunction = Func;
}

// 移除当前函数
void CodeGenerator::LeaveFunction(void) {
	this->CurrFunction = NULL;
}

// 获取当前函数
llvm::Function* CodeGenerator::GetCurrentFunction(void){
	return this->CurrFunction;
}

// 进入循环
void CodeGenerator::EnterLoop(llvm::BasicBlock* ConditionBB, llvm::BasicBlock* EndBB){
	this->ConditionBlockStack.push_back(ConditionBB);
	this->EndBlockStack.push_back(EndBB);
}

// 离开循环
void CodeGenerator::LeaveLoop(void){
	if (this->ConditionBlockStack.size() != 0)
		this->ConditionBlockStack.pop_back();
	if (this->EndBlockStack.size() != 0)
		this->EndBlockStack.pop_back();
}

// 获取条件块
llvm::BasicBlock* CodeGenerator::GetConditionBlock(void){
	if (this->ConditionBlockStack.size())
		return this->ConditionBlockStack.back();
	else
		return NULL;
}

// 获取结束块
llvm::BasicBlock* CodeGenerator::GetEndBlock(void){
	if (this->EndBlockStack.size())
		return this->EndBlockStack.back();
	else
		return NULL;
}

// 切换到全局基本块
void CodeGenerator::ChangeToGlobalBB(){
	auto Tmp = IRBuilder.GetInsertBlock();
	this->TmpBB = Tmp;
	IRBuilder.SetInsertPoint(this->GlobalBB);
}

// 切换到临时基本块
void CodeGenerator::ChangeToTmpBB(){
	IRBuilder.SetInsertPoint(this->TmpBB);
	this->TmpBB = NULL;
}

// 生成代码
void CodeGenerator::GenerateCode(Block *Root){
	this->PushSymbolTable();

	this->GlobalFunc = llvm::Function::Create(llvm::FunctionType::get(IRBuilder.getVoidTy(), false), llvm::GlobalValue::InternalLinkage, "0Global", this->Module);
	this->GlobalBB = llvm::BasicBlock::Create(Context, "Temp", this->GlobalFunc);
    Root->codeGen(*this);

	std::cout << "Gen Successfully" << std::endl;

	this->GlobalBB->eraseFromParent();
	this->GlobalFunc->eraseFromParent();

	this->PopSymbolTable();
}

// 生成 IR
void CodeGenerator::GenIR(const string& filename ){
	llvm::verifyModule(*this->Module, &llvm::outs());
	
	std::error_code EC;
	llvm::raw_fd_ostream dest(filename, EC);
	if (EC) {
        llvm::errs() << "Could not open file: " << EC.message();
        return;
    }
    this->Module->print(dest, nullptr);
}

// 生成 printf 函数
llvm::Function* CodeGenerator::GenPrintf(){
    std::vector<llvm::Type*> printf_arg_types;
    printf_arg_types.push_back(IRBuilder.getInt8PtrTy());

    llvm::FunctionType* printf_type = 
    llvm::FunctionType::get(IRBuilder.getInt32Ty(), printf_arg_types, true);
    llvm::Function* printf_func = 
    llvm::Function::Create(printf_type, llvm::Function::ExternalLinkage, llvm::Twine("printf"), this->Module);

    printf_func->setCallingConv(llvm::CallingConv::C);
    return printf_func;
}

// 生成 scanf 函数
llvm::Function* CodeGenerator::GenScanf(){
    llvm::FunctionType* scanf_type = 
    llvm::FunctionType::get(IRBuilder.getInt32Ty(), true);
    llvm::Function* scanf_func = 
    llvm::Function::Create(scanf_type, llvm::Function::ExternalLinkage, llvm::Twine("scanf"), this->Module);

    scanf_func->setCallingConv(llvm::CallingConv::C);
    return scanf_func;
}
