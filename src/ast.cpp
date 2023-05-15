#include "ast.hpp"
#include "parser.hpp"
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

// we distguish global context and global context use C/context

llvm::Type* getLLvmType(string type){
    if(type == "int")
        return llvm::Type::getInt32Ty(Context);
    else if(type == "float")
        return llvm::Type::getFloatTy(Context);
    else if(type == "char")
        return llvm::Type::getInt8Ty(Context);
    else
        return llvm::Type::getVoidTy(Context);
}

// return the ptr type of llvm
llvm::Type* getPtrLLvmType(string type){
    if(type == "int")
        return llvm::Type::getInt32PtrTy(Context);
    else if(type == "float")
        return llvm::Type::getFloatPtrTy(Context);
    else if(type == "char")
        return llvm::Type::getInt8PtrTy(Context);
    else
        return llvm::Type::getVoidTy(Context);
}

// return the array type of llvm
llvm::Type* getArrayLLvmType(string type,int size){
    if(type == "int")
        return llvm::ArrayType::get(llvm::Type::getInt32Ty(Context), size);
    else if(type == "float")
        return llvm::ArrayType::get(llvm::Type::getFloatTy(Context), size);
    else if(type == "char")
        return llvm::ArrayType::get(llvm::Type::getInt8Ty(Context), size);
    else
        return nullptr;
}

llvm::Instruction::CastOps getCastInst(llvm::Type* src, llvm::Type* dst) {
    if (src == llvm::Type::getFloatTy(Context) && dst == llvm::Type::getInt32Ty(Context)) {
        return llvm::Instruction::FPToSI;  
    }
    else if (src == llvm::Type::getInt32Ty(Context) && dst == llvm::Type::getFloatTy(Context)) {
        return llvm::Instruction::SIToFP;
    }
    else if (src == llvm::Type::getInt8Ty(Context) && dst == llvm::Type::getFloatTy(Context)) {
        return llvm::Instruction::UIToFP;
    }
    else if (src == llvm::Type::getInt8Ty(Context) && dst == llvm::Type::getInt32Ty(Context)) {
        return llvm::Instruction::ZExt;
    }
    else if (src == llvm::Type::getInt32Ty(Context) && dst == llvm::Type::getInt8Ty(Context)) {
        return llvm::Instruction::Trunc;
    }
    else {
        throw logic_error("[ERROR] Wrong typecast");
    }
}

llvm::Value* typeCast(llvm::Value* src, llvm::Type* dst) {
    llvm::Instruction::CastOps op = getCastInst(src->getType(), dst);
    return IRBuilder.CreateCast(op, src, dst, "tmptypecast");
}

llvm::Value* Integer::codeGen(CodeGenerator& context) {
    cout << "INT: " << value << endl;
    return IRBuilder.getInt32(value);
}

llvm::Value* Double::codeGen(CodeGenerator& context) {
    cout << "DOUBLE: " << value << endl;
    return llvm::ConstantFP::get(IRBuilder.getDoubleTy(), value);
}

llvm::Value* Char::codeGen(CodeGenerator& context) {
    cout << "CHAR: " << value << endl;
    return IRBuilder.getInt8(value);
}

llvm::Value* String::codeGen(CodeGenerator& context) {
    cout << "STRING: " << value << endl;
    return IRBuilder.CreateGlobalStringPtr(value.c_str());
}


llvm::Value* Identifier::codeGen(CodeGenerator& context) {
    cout << "IDENTIFIER: " << name << endl;

    llvm::Value* var = context.FindVariable(name);
    if(var == nullptr){
        std::cerr << "undeclared variable " << name << endl;
        return nullptr;
    }

    llvm::Type* tp = var->getType()->getPointerElementType();
    llvm::outs() << "identifier type:" << *tp << "\n";

    llvm::Value* res = nullptr;
    /*
    // if array
    if(tp->isArrayTy()) {
        // 2-dimension
        vector<llvm::Value*> indexList;
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(IRBuilder.getInt32(0));
        // the first argument is a pointer to the base address of the array, and the remaining arguments are the indices of the element to access.
        res = IRBuilder.CreateInBoundsGEP(var, llvm::ArrayRef<llvm::Value*>(indexList), "arrayPtr");
    }
    else {
    */
    res = new llvm::LoadInst(tp, var, "LoadInst", false, IRBuilder.GetInsertBlock());

    return res;
}

llvm::Value* Call::codeGen(CodeGenerator& context){
    // find the same name function in module
    llvm::Function *func = context.Module->getFunction(id.name.c_str());
    if (func == NULL) {
		std::cerr << "no such function " << id.name << endl;
	}

    // !! no type upgrade or type check

    vector<llvm::Value*> tmp;
    // vector<Expression*>::iterator i;

    // generate all the arg val
    for(auto i: arguments){
        tmp.push_back((*i).codeGen(context));
    }
    // llvm::CallInst *call = IRBuilder.CreateCall(Func, ArgList);
    llvm::CallInst *call = llvm::CallInst::Create(func, llvm::makeArrayRef(tmp),"",IRBuilder.GetInsertBlock());
    cout << "Creating method call: " << id.name << endl;
	return call;
}


llvm::Value* BinaryOp::codeGen(CodeGenerator& context){
    cout << "BinaryOp: " << op << endl;
    llvm::Value* left = lhs.codeGen(context);
    llvm::Value* right = rhs.codeGen(context);
    llvm::Instruction::BinaryOps bi_op;

    // bit calculate
    if(op == AND){
        if (left->getType() != llvm::Type::getInt1Ty(Context) || right->getType() != llvm::Type::getInt1Ty(Context)) {
            throw logic_error("can not use types other than bool in and exp");
        }
        return IRBuilder.CreateAnd(left, right, "tmpAnd");
    }
    else if (op == OR) {
        if (left->getType() != llvm::Type::getInt1Ty(Context) || right->getType() != llvm::Type::getInt1Ty(Context)) {
            throw logic_error("cannot use types other than bool in and exp");
        }
        return IRBuilder.CreateOr(left, right, "tmpOR");
    }
    else{
    // ADD SUB MUL DIV
    // LT、GT、EQ、NEQ、LE、GE
        // same type 
        if (left->getType() != right->getType()) {
            // left or right is float
            if (left->getType() == llvm::Type::getFloatTy(Context)) {
                right = typeCast(right, llvm::Type::getFloatTy(Context));
            } else if (right->getType() == llvm::Type::getFloatTy(Context)) {
                left = typeCast(left, llvm::Type::getFloatTy(Context));
            } else {
                // if left or right is int
                if (left->getType() == llvm::Type::getInt32Ty(Context)) {
                    right = typeCast(right, llvm::Type::getInt32Ty(Context));
                } else if(right->getType() == llvm::Type::getInt32Ty(Context)) {
                    left = typeCast(left, llvm::Type::getInt32Ty(Context));
                } else {
                    throw logic_error("cann't use bool in + - * / == != >= <= < >");
                }
            }
        }
        if(op == PLUS || op == MINUS || op == MUL || op ==  DIV){
            if(op == PLUS){
                bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FAdd : llvm::Instruction::Add;
            } else if(op == MINUS){
                bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FSub : llvm::Instruction::Sub;
            } else if(op == MUL){
                bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FMul : llvm::Instruction::Mul;
            } else if(op == DIV){ 
                bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FDiv : llvm::Instruction::SDiv;
            } 
            return llvm::BinaryOperator::Create(bi_op, left, right, "", IRBuilder.GetInsertBlock());
        }
        if (op == CEQ) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpOEQ(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpEQ(left, right, "icmptmp");
        }
        else if (op == CGE) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpOGE(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpSGE(left, right, "icmptmp");
        }
        else if (op == CLE) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpOLE(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpSLE(left, right, "icmptmp");
        }
        else if (op == CGT) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpOGT(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpSGT(left, right, "icmptmp");
        }
        else if (op == CLT) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpOLT(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpSLT(left, right, "icmptmp");
        }
        else if (op == CNE) {
            if(left->getType() == llvm::Type::getFloatTy(Context))
                return IRBuilder.CreateFCmpONE(left, right, "fcmptmp");
            else 
                return IRBuilder.CreateICmpNE(left, right, "icmptmp");
        }
        else{
            cerr << "unknown operator " << op << endl;
            return NULL;
        }
    }
}

// idk but in yacc ASSIGN is EQUAL
// identifier = expression
llvm::Value* Assign::codeGen(CodeGenerator &context){
    cout << "ASSIGN: lhs " << ident.name << endl;
    
    llvm::Value* result = context.FindVariable(ident.name);
    if(result == nullptr){
        cerr << "undeclared variable " << ident.name << endl;
		return nullptr;
    }

    llvm::Value* right = expr.codeGen(context);

    auto CurrentBlock = IRBuilder.GetInsertBlock();

    // why getPointerElementType ?
    if (right->getType() != result->getType()->getPointerElementType())
        right = typeCast(right, result->getType()->getPointerElementType());

    return new llvm::StoreInst(right, result, false, CurrentBlock);
}

llvm::Value* Block::codeGen(CodeGenerator &context){
    llvm::Value* tmp = NULL;
    for(auto i : statementList){
        cout << "Generating code for " << typeid(*i).name() << endl;
        tmp = (*i).codeGen(context);

        // 若当前语句为 reutrn , 则后面的语句需要截断
        // if(context.hasReturn == true)
        //     break;
    }
    cout << endl;
	return tmp;
}

// e.g a[2];
llvm::Value* ArrayElement::codeGen(CodeGenerator &context){
    cout << "ArrayElement: " << identifier.name << "[]" << endl;

    llvm::Value* arrayValue = context.FindVariable(identifier.name);
    if(arrayValue == nullptr){
        cerr << "undeclared array " << identifier.name << endl;
		return nullptr;
    }

    llvm::Value* indexValue = index.codeGen(context);
    vector<llvm::Value*> indexList;

    // here dont understand
    // if pointer
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList.push_back(indexValue);    
    }
    // if array 
    else {
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(indexValue);    
    }

    llvm::Value* elePtr =  IRBuilder.CreateInBoundsGEP(arrayValue->getType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmparray");
    return IRBuilder.CreateLoad(elePtr->getType()->getPointerElementType(), elePtr, "tmpvar");
    //return IRBuilder.CreateAlignedLoad(elePtr, 4);
}

// 返回数组 array[index]的地址用来函数传参
llvm::Value* ArrayElement::getAddr(CodeGenerator &context){
    cout << "getArrayElementAddr : " << identifier.name << "[]" << endl;

    llvm::Value* arrayValue = context.FindVariable(identifier.name);
    if(arrayValue == nullptr){
        cerr << "undeclared array " << identifier.name << endl;
		return nullptr;
    }

    llvm::Value* indexValue = index.codeGen(context);
    vector<llvm::Value*> indexList;

    // 如果是一个指针
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList.push_back(indexValue);    
    }
    // 如果是一个数组 
    else {
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(indexValue);    
    }

    llvm::Value* elePtr =  IRBuilder.CreateInBoundsGEP(arrayValue->getType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmparray");
    return elePtr;
    //return IRBuilder.CreateAlignedLoad(elePtr, 4);
}

llvm::Value* ArrayAssign::codeGen(CodeGenerator &context){
    cout << "ArrayAssign: " << identifier.name << "[]" << endl;

    llvm::Value* arrayValue = context.FindVariable(identifier.name);
    if(arrayValue == nullptr){
        cerr << "undeclared array " << identifier.name << endl;
		return nullptr;
    }
    // llvm::Value* arrayValue = context.getTop()[identifier.name];
    llvm::Value* indexValue = index.codeGen(context);
    vector<llvm::Value*> indexList;


    llvm::outs()<<"arrayIdentifier type:"<<*(arrayValue->getType());
    cout<<endl;

    // 如果是一个指针
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList.push_back(indexValue);    
    }
    // 如果是一个数组 
    else {
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(indexValue);    
    }
    llvm::Value* left =  IRBuilder.CreateInBoundsGEP(arrayValue->getType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar");
    llvm::Value *right = rhs.codeGen(context);

    llvm::outs()<<*(left->getType()->getPointerElementType());

    if (right->getType() != left->getType()->getPointerElementType())
        right = typeCast(right, left->getType()->getPointerElementType());

    return IRBuilder.CreateStore(right, left);
    //return nullptr;
}

llvm::Value* GetAddr::codeGen(CodeGenerator &context){
    cout << "GetAddr : " << rhs.name << endl;
    // 在符号表和全局变量中查找
    llvm::Value* result = context.FindVariable(rhs.name);
    if(result == nullptr){
        cerr << "undeclared variable " << rhs.name << endl;
		return nullptr;
    }
    return result;
}

llvm::Value* GetArrayAddr::codeGen(CodeGenerator &context){
    cout<<"get arrayElement Addr:"<<rhs.name<<"[]"<<endl;

    llvm::Value* arrayValue = context.FindVariable(rhs.name);
    if(arrayValue == nullptr){
        cerr << "undeclared array " << rhs.name << endl;
		return nullptr;
    }
    // llvm::Value* arrayValue = context.getTop()[identifier.name];
    llvm::Value* indexValue = index.codeGen(context);
    vector<llvm::Value*> indexList;


    // 如果是一个指针
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList.push_back(indexValue);    
    }
    // 如果是一个数组 
    else {
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(indexValue);    
    }

    llvm::Value* elePtr = IRBuilder.CreateInBoundsGEP(arrayValue->getType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "elePtr");
    return elePtr;
    //return nullptr;
}

