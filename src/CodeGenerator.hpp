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
class CodeGenerator{
    public:
        llvm::Module* Module;
    
}


#endif