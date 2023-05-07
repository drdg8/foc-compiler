#include"ast.hpp"
//#include "parsing.hpp"
#include "CodeGenerator.hpp"
#include <llvm/IR/BasicBlock.h>
#include <llvm/ADT/ArrayRef.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <string>
#include <vector>
using namespace std;
llvm::Value* NBinaryOperator::codeGen(CodeGenContext& context){
    cout << "BinaryOpNode : " << op << endl;
    llvm::Value* left = lhs.codeGen(context);
    llvm::Value* right = rhs.codeGen(context);
    llvm::Instruction::BinaryOps bi_op;

    if(op == TPLUS || op == TMINUS || op == TMUL || op == TDIV){
        if (left->getType() != right->getType()) {
            if (left->getType() == llvm::Type::getFloatTy(myContext)) {
                right = typeCast(right, llvm::Type::getFloatTy(myContext));
            } else {
                if (right->getType() == llvm::Type::getFloatTy(myContext)) {
                    left = typeCast(left, llvm::Type::getFloatTy(myContext));
                } else {
                    if (left->getType() == llvm::Type::getInt32Ty(myContext)) {
                        right = typeCast(right, llvm::Type::getInt32Ty(myContext));
                    } else if(right->getType() == llvm::Type::getInt32Ty(myContext)) {
                        left = typeCast(left, llvm::Type::getInt32Ty(myContext));
                    } else {
                        throw logic_error("cann't use bool in +-*/");
                    }
                }
            }
        }
        if(op == TPLUS){bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FAdd : llvm::Instruction::Add;}
        else if(op == TMINUS){bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FSub : llvm::Instruction::Sub;}
        else if(op == TMUL){bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FMul : llvm::Instruction::Mul;}
        else if(op == TDIV){bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FDiv : llvm::Instruction::SDiv;}
        return llvm::BinaryOperator::Create(bi_op,left,right,"", myBuilder.GetInsertBlock());
    }
    else if(op == AND){
        if (left->getType() != llvm::Type::getInt1Ty(myContext) || right->getType() != llvm::Type::getInt1Ty(myContext)) {
                    throw logic_error("cannot use types other than bool in and exp");
                }
                return myBuilder.CreateAnd(left, right, "tmpAnd");
    }
    else if (op == OR) {
        if (left->getType() != llvm::Type::getInt1Ty(myContext) || right->getType() != llvm::Type::getInt1Ty(myContext)) {
                    throw logic_error("cannot use types other than bool in and exp");
                }
                return myBuilder.CreateOr(left, right, "tmpOR");
    }
    else{  //LT、GT、EQ、NEQ、LE、GE
        if (left->getType() != right->getType()) { //若左右的type类型不一致
            if (left->getType() == llvm::Type::getFloatTy(myContext)) 
            { right = typeCast(right, llvm::Type::getFloatTy(myContext));} 
            else {
                if (right->getType() == llvm::Type::getFloatTy(myContext)) 
                {
                    left = typeCast(left, llvm::Type::getFloatTy(myContext));
                } 
                else {
                    if (left->getType() == llvm::Type::getInt32Ty(myContext)) {
                        right = typeCast(right, llvm::Type::getInt32Ty(myContext));
                    } else if(right->getType() == llvm::Type::getInt32Ty(myContext)) {
                        left = typeCast(left, llvm::Type::getInt32Ty(myContext));
                    } else {
                        throw logic_error("cann't use bool in == != >= <= < >");
                    }
                }
            }
        }
        else if (op == TEQUAL) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpOEQ(left, right, "fcmptmp") : myBuilder.CreateICmpEQ(left, right, "icmptmp");
        }
        else if (op == TCGE) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpOGE(left, right, "fcmptmp") : myBuilder.CreateICmpSGE(left, right, "icmptmp");
        }
        else if (op == TCLE) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpOLE(left, right, "fcmptmp") : myBuilder.CreateICmpSLE(left, right, "icmptmp");
        }
        else if (op == TCGT) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpOGT(left, right, "fcmptmp") : myBuilder.CreateICmpSGT(left, right, "icmptmp");
        }
        else if (op == TCLT) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpOLT(left, right, "fcmptmp") : myBuilder.CreateICmpSLT(left, right, "icmptmp");
        }
        else if (op == TCNE) {
            return (left->getType() == llvm::Type::getFloatTy(myContext)) ? myBuilder.CreateFCmpONE(left, right, "fcmptmp") : myBuilder.CreateICmpNE(left, right, "icmptmp");
        }
        return NULL;
    }
}
int main()
{

}