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

//symbol table的定义
class Symbol{
public:
    Symbol(void) : _Value(NULL),_Function(NULL), Type(UNDEFINED) {}
    Symbol(llvm::Function* Func) : _Value(NULL),_Function(Func), Type(FUNCTION) {}
    Symbol(llvm::Value* Value) : _Function(Value), Type(VARIABLE) {}
    llvm::Value* GetVariable(void) { return this->Type == VARIABLE ? _Value : NULL; }
    llvm::Function* GetFunction(void) { return this->Type == FUNCTION ? _Function : NULL; }
public:
    llvm::Value* _Value;
    llvm::Function* _Function;
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
        // condition block, when "continue;" jump here
        std::vector<llvm::BasicBlock*> ConditionBlockStack;
        // end block, when "break;" jump here
        std::vector<llvm::BasicBlock*> EndBlockStack;

        // llvm::BasicBlock* returnBB;
        // llvm::Value* returnVal;

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

        void EnterFunction(llvm::Function* Func);

        void LeaveFunction(void);

        void EnterLoop(llvm::BasicBlock* ConditionBB, llvm::BasicBlock* EndBB);

        // called when leave a loop
        void LeaveLoop(void);

        // get the destination block for "continue" statements
        llvm::BasicBlock* GetConditionBlock(void);

        // get the destination block for "break" statements
        llvm::BasicBlock* GetEndBlock(void);

        void GenIR(Block* programBlock,const string& filename);

};


#endif