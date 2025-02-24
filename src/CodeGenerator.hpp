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

class CodeGenerator{
    public:
        using SymbolTable = std::map<std::string, llvm::Value*>;
        llvm::Module* Module;
        std::vector<SymbolTable*> SymbolTableStack;
        llvm::Function* CurrFunction;	
        // condition block, when "continue;" jump here
        std::vector<llvm::BasicBlock*> ConditionBlockStack;
        // end block, when "break;" and "continue;" jump here
        std::vector<llvm::BasicBlock*> EndBlockStack;
        llvm::BasicBlock* TmpBB;
        llvm::BasicBlock* GlobalBB;
        llvm::Function* GlobalFunc;
        llvm::Function *printf,*scanf;

    public:
        CodeGenerator(void);

        void PushSymbolTable(void);

        void PopSymbolTable(void);

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

        void ChangeToGlobalBB();

        void ChangeToTmpBB();

        void GenerateCode(Block *Root);

        void GenIR(const string& filename);
        
        llvm::Function* GenPrintf(); //得到llvm形式的printf函数
        
        llvm::Function* GenScanf();  //得到llvm形式的scanf函数
};


#endif