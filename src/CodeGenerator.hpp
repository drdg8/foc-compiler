#ifndef CODEGEN_H
#define CODEGEN_H

#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Value.h>
#include <map>
#include <stack>
#include <string>
#include <typeinfo>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/Support/raw_ostream.h>

#include "ast.hpp"
using namespace std;

extern llvm::LLVMContext Context; //定义全局context
extern llvm::IRBuilder<> IRBuilder; //定义全局IRbuilder

//symbol 的定义
class Symbol{
public:
    Symbol(void) : Content(NULL), Type(UNDEFINED) {}
    Symbol(llvm::Function* Func) : Content(Func), Type(FUNCTION) {}
    Symbol(llvm::Value* Value) : Content(Value), Type(VARIABLE) {}
    llvm::Value* GetVariable(void) { return this->Type == VARIABLE ? (llvm::Value*)Content : NULL; }
    llvm::Function* GetFunction(void) { return this->Type == FUNCTION ? (llvm::Function*)Content : NULL; }
public:
    llvm::Value* Content;
    enum{
        FUNCTION,
        VARIABLE,
        UNDEFINED
    } Type;   
    // llvm::Type* Type;   
};

class CodeGenerator{
    public:
        using SymbolTable = std::map<std::string, Symbol>;

        llvm::Module* Module;
        std::vector<SymbolTable*> SymbolTableStack;
        llvm::Function* CurrFunction;	
        llvm::BasicBlock* returnBB;
        llvm::Value* returnVal;
    public:
        CodeGenerator(void);
        //sizeof() 空位，待实现

        void PushSymbolTable(void);

        void PopSymbolTable(void);

        llvm::Function* FindFunction(std::string Name);

        bool AddFunction(std::string Name, llvm::Function* Function);

        llvm::Value* FindVariable(std::string Name);

        bool AddVariable(std::string Name, llvm::Value* Variable);

        llvm::Function* GetCurrentFunction(void);

        void GenIR(Block* programBlock,const string& filename);

};


#endif