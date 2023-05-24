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
#include <typeinfo>

using namespace std;

// we distguish global context and code use C/context
//我们用C/context来区分上下文和codegenerator

// 这个函数是用来获取VarType类型对应的LLVM类型。LLVM类型包括Int32，Int8，Double，Void等基本类型，
// 并且也处理了数组类型。数组类型是通过llvm::ArrayType来实现的。
llvm::Type* VarType::getLLVMType(){
    // 创建一个llvm::Type指针LLVMType
    llvm::Type *LLVMType;
    // 判断变量的类型
    switch (type) {
        case _Int: LLVMType = IRBuilder.getInt32Ty(); break;
        case _Char: LLVMType = IRBuilder.getInt8Ty(); break;
        case _Double: LLVMType = IRBuilder.getDoubleTy(); break;
        case _Void: LLVMType = IRBuilder.getVoidTy(); break;
        default: break;
    }
    // 如果变量有大小（可能是数组）
    if(this->size > 0){
        // 使用llvm::ArrayType::get生成数组类型，并赋值给LLVMType
        LLVMType = llvm::ArrayType::get(LLVMType, this->size); 
    }
    // 返回LLVMType
    return LLVMType;
}





// 这个函数用于打印LLVM Value的类型。
// 如果这个Value是一个指针类型，它还会打印这个指针所指向的元素的类型。输出的结果将直接打印到标准输出设备（例如控制台）。
// 打印信息用于调试
void typePrint(llvm::Value *var){
    // Assign: Type of left %res = alloca i32, align 4 is: i32* ,eleType is: i32
    llvm::Type* type = var->getType();
    llvm::outs() << "Type of variable " << *var << " is: ";
    type->print(llvm::outs());
    if(type->isPointerTy()){
        llvm::Type* eletype = var->getType()->getPointerElementType();
        llvm::outs() << " ,eleType is: ";
        eletype->print(llvm::outs());
    }
    llvm::outs() << "\n";
}


//根据源数据类型和目标数据类型确定适当的转换操作类型。它处理不同的类型之间的转换，例如，从 float 到 int32，从 int32 到 float 等等。
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

//执行类型转换。它首先打印出源数据类型和目标数据类型，然后根据源数据类型和目标数据类型调用适当的转换函数。
llvm::Value* typeCast(llvm::Value* src, llvm::Type* dst) {
    llvm::Type* type = src->getType();
    llvm::outs() << "TypeCast: Type of value " << *src << " is: ";
    type->print(llvm::outs());
    llvm::outs() << ", casting to " << *dst;
    llvm::outs() << "\n";

    if(src->getType() == dst){
        return src;
    }
    //如果目标类型（dst）是 1-bit 整型（对应于布尔类型），执行相应的类型转换。
    if (dst == llvm::Type::getInt1Ty(Context)){
        if (src->getType() == IRBuilder.getInt1Ty()){
            return src;
        }
        else if (src->getType()->isIntegerTy()){
            return IRBuilder.CreateICmpNE(src, llvm::ConstantInt::get(src->getType(), 0, true));
        }
        else if (src->getType()->isFloatingPointTy()){
            return IRBuilder.CreateFCmpONE(src, llvm::ConstantFP::get(src->getType(), 0.0));
        }
        else if (src->getType()->isPointerTy()){
            return IRBuilder.CreateICmpNE(IRBuilder.CreatePtrToInt(src, IRBuilder.getInt64Ty()), IRBuilder.getInt64(0));
        }
        else {
            throw std::logic_error("Cannot cast to bool type.");
            return NULL;
        }
    }
    llvm::Instruction::CastOps op = getCastInst(src->getType(), dst);
    return IRBuilder.CreateCast(op, src, dst, "tmptypecast");
}

// Integer 类型的代码生成函数。在控制台输出 "INT: 值"，并返回一个 int32 常量值。
llvm::Value* Integer::codeGen(CodeGenerator& context) {
    cout << "INT: " << value << endl;
    return IRBuilder.getInt32(value);
}

// Double 类型的代码生成函数。在控制台输出 "DOUBLE: 值"，并返回一个 double 常量值。
llvm::Value* Double::codeGen(CodeGenerator& context) {
    cout << "DOUBLE: " << value << endl;
    return llvm::ConstantFP::get(IRBuilder.getDoubleTy(), value);
}

// Char 类型的代码生成函数。在控制台输出 "CHAR: 值"，并返回一个 int8（字符型）常量值。
llvm::Value* Char::codeGen(CodeGenerator& context) {
    cout << "CHAR: " << value << endl;
    return IRBuilder.getInt8(value);
}

// String 类型的代码生成函数。首先在控制台输出 "STRING: 值"，然后处理字符串中的 "\n"（换行符）。
// 创建一个 LLVM 常量数据数组来存储处理后的字符串，并将其设置为全局变量。
// 最后，创建一个全局变量指针，并返回该指针。
llvm::Value* String::codeGen(CodeGenerator& context) {
    std::cout << "STRING: " << value << std::endl;
    
    std::string processedStr = value.substr(1, value.length() - 2);
    const std::string newLine = "\n";
    size_t newlinePos = processedStr.find("\\n");

    while(newlinePos != std::string::npos) {
        processedStr.replace(newlinePos, 2, newLine);
        newlinePos = processedStr.find("\\n");
    }

    llvm::Constant *constStr = llvm::ConstantDataArray::getString(Context, processedStr);

    llvm::GlobalVariable *globalStrVar = new llvm::GlobalVariable(*(context.Module), 
                                                                   constStr->getType(), 
                                                                   true, 
                                                                   llvm::GlobalValue::PrivateLinkage, 
                                                                   constStr, 
                                                                   "_Const_String_");
    
    std::vector<llvm::Value*> indices = {IRBuilder.getInt32(0), IRBuilder.getInt32(0)};
    llvm::PointerType* ptrType = llvm::cast<llvm::PointerType>(globalStrVar->getType());
    llvm::Type* elementType = ptrType->getPointerElementType();

    llvm::Value *strPointer = IRBuilder.CreateInBoundsGEP(elementType, globalStrVar, indices, "tmpstring");

    return strPointer;
}

// 此函数通过名字查找变量并返回其 LLVM IR 代码。
// 如果变量是数组类型，会获取数组元素的指针。
// 如果变量不是数组，会从内存中加载其值。
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
    if(tp->isArrayTy()) {
        vector<llvm::Value*> indexList;
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(IRBuilder.getInt32(0));
        // the first argument is a pointer to the base address of the array, and the remaining arguments are the indices of the element to access.
        res = IRBuilder.CreateInBoundsGEP(var->getType()->getPointerElementType(), var, llvm::ArrayRef<llvm::Value*>(indexList), "arrayPtr");
    }
    else {
        res = new llvm::LoadInst(tp, var, "LoadInst", false, IRBuilder.GetInsertBlock());
    }

    return res;
}

// 为scanf函数生成参数
vector<llvm::Value *> *getScanfArgs(CodeGenerator& context,vector<Expression*> args){
    vector<llvm::Value *> *scanf_args = new vector<llvm::Value *>;
    for(auto it: args){
        llvm::Value* tmp = it->codeGen(context);
        scanf_args->push_back(tmp);
    }
    return scanf_args;
}

// 为printf函数生成参数
vector<llvm::Value *> *getPrintfArgs(CodeGenerator& context,vector<Expression*> args){
    vector<llvm::Value *> *printf_args = new vector<llvm::Value *>;
    for(auto it: args){
        llvm::Value* tmp = it->codeGen(context);
        if (tmp->getType() == llvm::Type::getFloatTy(Context))
            tmp = IRBuilder.CreateFPExt(tmp, llvm::Type::getDoubleTy(Context), "tmpdouble");
        printf_args->push_back(tmp);
    }
    return printf_args;
}


// 调用printf函数，生成printf调用的代码
llvm::Value* call_printf(CodeGenerator& context,vector<Expression*> args){
    vector<llvm::Value *> *printf_args = getPrintfArgs(context, args);    
    return IRBuilder.CreateCall(context.printf, *printf_args, "printf");
}

// 调用scanf函数，生成scanf调用的代码
llvm::Value* call_scanf(CodeGenerator& context,vector<Expression*> args){
    //vector<llvm::Value *> *scanf_args = getScanfArgsAddr(emitContext, args);    
    vector<llvm::Value *> *scanf_args = getScanfArgs(context, args);    
    return IRBuilder.CreateCall(context.scanf, *scanf_args, "scanf");
}
llvm::Value* Call::generatePrintfCall(CodeGenerator& context, std::vector<Expression*>& args){
    std::cout << "Generating call to printf" << std::endl;
    return call_printf(context, args);
}

llvm::Value* Call::generateScanfCall(CodeGenerator& context, std::vector<Expression*>& args){
    std::cout << "Generating call to scanf" << std::endl;
    return call_scanf(context, args);
}

// 这是 Call 类的 codeGen 函数，它负责生成调用函数的 LLVM IR 代码
llvm::Value* Call::codeGen(CodeGenerator& context){
    llvm::Value* result = nullptr;
    
    // 特别处理 printf 和 scanf 函数
    if(id.name == "printf"){
        result = generatePrintfCall(context, arguments);
    } else if(id.name == "scanf"){
        result = generateScanfCall(context, arguments);
    }
    
    // 如果不是 printf 或 scanf，就在模块中查找函数
    if (result == nullptr) {
        llvm::Function* function = context.Module->getFunction(id.name.c_str());
        if (function == nullptr) {
            std::cerr << "Function not found: " << id.name << std::endl;
            return nullptr;
        }

        std::cout << "Generating call to function: " << id.name << std::endl;

        std::vector<llvm::Value*> argValues;
        for(auto& arg : arguments){
            argValues.push_back(arg->codeGen(context));
        }

        result = llvm::CallInst::Create(function, llvm::makeArrayRef(argValues), "", IRBuilder.GetInsertBlock());
        std::cout << "Created call to function: " << id.name << std::endl;
    }
    
    return result;
}

// 确保两个操作数的类型相同，如果不同则进行转换
void unifyOperandTypes(llvm::Value*& left, llvm::Value*& right){
    if (left->getType() == llvm::Type::getFloatTy(Context)) {
        right = typeCast(right, llvm::Type::getFloatTy(Context));
    } else if (right->getType() == llvm::Type::getFloatTy(Context)) {
        left = typeCast(left, llvm::Type::getFloatTy(Context));
    } else {
        if (left->getType() == llvm::Type::getInt32Ty(Context)) {
            right = typeCast(right, llvm::Type::getInt32Ty(Context));
        } else if(right->getType() == llvm::Type::getInt32Ty(Context)) {
            left = typeCast(left, llvm::Type::getInt32Ty(Context));
        } else {
            throw std::logic_error("Both operands should be int or float for arithmetic operations.");
        }
    }
}

// 根据操作符和操作数类型，确定应使用的 LLVM IR 指令
llvm::Instruction::BinaryOps determineBinOpInstruction(int op, llvm::Type* type){
    switch (op)
    {
        case PLUS:
            return type->isFloatTy() ? llvm::Instruction::FAdd : llvm::Instruction::Add;
        case MINUS:
            return type->isFloatTy() ? llvm::Instruction::FSub : llvm::Instruction::Sub;
        case MUL:
            return type->isFloatTy() ? llvm::Instruction::FMul : llvm::Instruction::Mul;
        case DIV:
            return type->isFloatTy() ? llvm::Instruction::FDiv : llvm::Instruction::SDiv;
        default:
            throw std::invalid_argument("Invalid operator for binary operation instruction.");
    }
}
// 生成比较操作的指令
llvm::Value* generateComparisonInstruction(int op, llvm::Value* left, llvm::Value* right){
    bool isFloat = left->getType() == llvm::Type::getFloatTy(Context);
    switch (op)
    {
        case CEQ:
            return isFloat ? IRBuilder.CreateFCmpOEQ(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpEQ(left, right, "icmptmp");
        case CGE:
            return isFloat ? IRBuilder.CreateFCmpOGE(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpSGE(left, right, "icmptmp");
        case CLE:
            return isFloat ? IRBuilder.CreateFCmpOLE(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpSLE(left, right, "icmptmp");
        case CGT:
            return isFloat ? IRBuilder.CreateFCmpOGT(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpSGT(left, right, "icmptmp");
        case CLT:
            return isFloat ? IRBuilder.CreateFCmpOLT(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpSLT(left, right, "icmptmp");
        case CNE:
            return isFloat ? IRBuilder.CreateFCmpONE(left, right, "fcmptmp")
                           : IRBuilder.CreateICmpNE(left, right, "icmptmp");
        default:
            throw std::invalid_argument("Invalid operator for comparison instruction.");
    }
}



// BinaryOp 的 codeGen 函数用于生成二元运算的 LLVM IR 代码
llvm::Value* BinaryOp::codeGen(CodeGenerator& context){
    std::cout << "Processing Binary Operation: " << op << std::endl;
    llvm::Value* leftOperand = lhs.codeGen(context);
    llvm::Value* rightOperand = rhs.codeGen(context);
    llvm::Instruction::BinaryOps binOpInstr;

    // 如果是逻辑与或逻辑或运算
    if(op == AND || op == OR){
        // 检查类型是否为布尔型
        if (leftOperand->getType() != llvm::Type::getInt1Ty(Context) || rightOperand->getType() != llvm::Type::getInt1Ty(Context)) {
            throw std::logic_error("Both operands should be of type bool for 'AND'/'OR' operations.");
        }
        return (op == AND) ? IRBuilder.CreateAnd(leftOperand, rightOperand, "tmpAnd")
                           : IRBuilder.CreateOr(leftOperand, rightOperand, "tmpOR");
    }
    // 否则，处理其他类型的运算
    else{
        // 保证左右操作数类型一致
        if (leftOperand->getType() != rightOperand->getType()) {
            unifyOperandTypes(leftOperand, rightOperand);
        }
        // 处理算术运算
        if(op == PLUS || op == MINUS || op == MUL || op == DIV){
            binOpInstr = determineBinOpInstruction(op, leftOperand->getType());
            return llvm::BinaryOperator::Create(binOpInstr, leftOperand, rightOperand, "", IRBuilder.GetInsertBlock());
        }
        // 处理比较运算
        else {
            return generateComparisonInstruction(op, leftOperand, rightOperand);
        }
    }
}



// llvm::Value* BinaryOp::codeGen(CodeGenerator& context){
//     cout << "BinaryOp: " << op << endl;
//     llvm::Value* left = lhs.codeGen(context);
//     llvm::Value* right = rhs.codeGen(context);
//     llvm::Instruction::BinaryOps bi_op;

//     // bit calculate
//     if(op == AND){
//         if (left->getType() != llvm::Type::getInt1Ty(Context) || right->getType() != llvm::Type::getInt1Ty(Context)) {
//             throw logic_error("can not use types other than bool in and exp");
//         }
//         return IRBuilder.CreateAnd(left, right, "tmpAnd");
//     }
//     else if (op == OR) {
//         if (left->getType() != llvm::Type::getInt1Ty(Context) || right->getType() != llvm::Type::getInt1Ty(Context)) {
//             throw logic_error("cannot use types other than bool in and exp");
//         }
//         return IRBuilder.CreateOr(left, right, "tmpOR");
//     }
//     else{
//     // ADD SUB MUL DIV
//     // LT、GT、EQ、NEQ、LE、GE
//         // same type 
//         if (left->getType() != right->getType()) {
//             // left or right is float
//             if (left->getType() == llvm::Type::getFloatTy(Context)) {
//                 right = typeCast(right, llvm::Type::getFloatTy(Context));
//             } else if (right->getType() == llvm::Type::getFloatTy(Context)) {
//                 left = typeCast(left, llvm::Type::getFloatTy(Context));
//             } else {
//                 // if left or right is int
//                 if (left->getType() == llvm::Type::getInt32Ty(Context)) {
//                     right = typeCast(right, llvm::Type::getInt32Ty(Context));
//                 } else if(right->getType() == llvm::Type::getInt32Ty(Context)) {
//                     left = typeCast(left, llvm::Type::getInt32Ty(Context));
//                 } else {
//                     throw logic_error("cann't use bool in + - * / == != >= <= < >");
//                 }
//             }
//         }
//         if(op == PLUS || op == MINUS || op == MUL || op ==  DIV){
//             if(op == PLUS){
//                 bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FAdd : llvm::Instruction::Add;
//             } else if(op == MINUS){
//                 bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FSub : llvm::Instruction::Sub;
//             } else if(op == MUL){
//                 bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FMul : llvm::Instruction::Mul;
//             } else if(op == DIV){ 
//                 bi_op = left->getType()->isFloatTy() ? llvm::Instruction::FDiv : llvm::Instruction::SDiv;
//             } 
//             return llvm::BinaryOperator::Create(bi_op, left, right, "", IRBuilder.GetInsertBlock());
//         }
//         if (op == CEQ) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpOEQ(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpEQ(left, right, "icmptmp");
//         }
//         else if (op == CGE) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpOGE(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpSGE(left, right, "icmptmp");
//         }
//         else if (op == CLE) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpOLE(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpSLE(left, right, "icmptmp");
//         }
//         else if (op == CGT) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpOGT(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpSGT(left, right, "icmptmp");
//         }
//         else if (op == CLT) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpOLT(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpSLT(left, right, "icmptmp");
//         }
//         else if (op == CNE) {
//             if(left->getType() == llvm::Type::getFloatTy(Context))
//                 return IRBuilder.CreateFCmpONE(left, right, "fcmptmp");
//             else 
//                 return IRBuilder.CreateICmpNE(left, right, "icmptmp");
//         }
//         else{
//             cerr << "unknown operator " << op << endl;
//             return NULL;
//         }
//     }
// }

// idk but in yacc ASSIGN is EQUAL
// identifier = expression
llvm::Value* Assign::codeGen(CodeGenerator &context){
    cout << "Assign: " << ident.name << endl;

    llvm::Value* result = context.FindVariable(ident.name);
    if(result == nullptr){
        cerr << "undeclared variable " << ident.name << endl;
		return nullptr;
    }

    // Assign: Type of left %res = alloca i32, align 4 is: i32* ,eleType is: i32
    llvm::Type* type = result->getType();
    typePrint(result);

    llvm::Value* right = expr.codeGen(context);
    cout << "right: ";
    typePrint(right);

    auto CurrentBlock = IRBuilder.GetInsertBlock();
    // cout << (IRBuilder.GetInsertBlock() == NULL) << endl;

    // use chatgpt
    // if Value *src, what's the difference between src->getType() and src->getType()->getPointerElementType()? give a e.g
    // in all, if src is pointer to int, getType() return llvm::Type *, which is a pointer to int, ->getPointerElementType() is same
    // if src is pointer to array int, getType() return pointer to llvm::Type array, ->getPointerElementType() return pointer to llvm::Type int 

    if (right->getType() != result->getType()->getPointerElementType())
        right = typeCast(right, result->getType()->getPointerElementType());

    if (right == NULL) {
		throw std::domain_error("Assignment with values that cannot be cast to the target type.");
		return NULL;
	}
    IRBuilder.CreateStore(right, result);
    /*
    Note that AllocaInst is a subclass of Instruction, which is a subclass of Value, so the cast from AllocaInst* to Value* is safe. This allows you to use the resulting Value* pointer in other parts of your LLVM code that expect a Value*, such as passing it as an argument to a function.
    */
    // maybe wrong here !!!

    // return result;
    return right;
}

// e.g a[2];
llvm::Value* ArrayElement::codeGen(CodeGenerator &context){
    cout << "ArrayElement: " << identifier.name << "[]" << endl;

    llvm::Value* arrayValue = context.FindVariable(identifier.name);
    if(arrayValue == nullptr){
        cerr << "undeclared array " << identifier.name << endl;
		return nullptr;
    }

    cout << "ArrayElement: index: " << endl;
    llvm::Value* indexValue = index.codeGen(context);

    // Check that the index value is an integer type
    if (!indexValue->getType()->isIntegerTy()) {
        cerr << "index value is not an integer type" << endl;
        return nullptr;
    }

    vector<llvm::Value*> indexList;

    // type of variable @f = global [100 x i32] zeroinitializer is: [100 x i32]* ,eleType is: [100 x i32]
    typePrint(arrayValue);

    // if arrayValue->getType() is i32**
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList.push_back(indexValue);    
    }
    // if array 
    else if(arrayValue->getType()->getPointerElementType()->isArrayTy()) {
        indexList.push_back(IRBuilder.getInt32(0));
        indexList.push_back(indexValue);    
    }
    else{
        cerr << "[] can just be used to pointer or array" << endl;
        return nullptr;
    }

    llvm::Value* elePtr = IRBuilder.CreateInBoundsGEP(arrayValue->getType()->getPointerElementType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmparray");

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

    llvm::Value* elePtr =  IRBuilder.CreateInBoundsGEP(arrayValue->getType()->getPointerElementType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmparray");
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
    llvm::Value* left =  IRBuilder.CreateInBoundsGEP(arrayValue->getType()->getPointerElementType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmpvar");
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
    cout << "get arrayElement Addr:" << rhs.name << "[]" << endl;

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

    // get element pointer
    llvm::Value* elePtr = IRBuilder.CreateInBoundsGEP(arrayValue->getType()->getPointerElementType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "elePtr");
    return elePtr;
    //return nullptr;
}

llvm::Value* Block::codeGen(CodeGenerator &context){
    context.PushSymbolTable();
    cout << "statementList:" << statementList.size()  << endl;
    llvm::Value* tmp = NULL;
    for(auto stmt : statementList){
        cout << "Generating code for " << typeid(*stmt).name() << endl;
        if (context.GetCurrentFunction() != NULL && IRBuilder.GetInsertBlock()->getTerminator())
         {  
             break;
         }
        else if (stmt){
            stmt->codeGen(context);
        }
    }
    cout << endl;
    context.PopSymbolTable();
	return NULL;
}

//已检查
llvm::Value* VariableDeclaration::codeGen(CodeGenerator &context){
    llvm::Type* VarType = type.getLLVMType();
    llvm::outs() << "Var Decl: Type ";
    VarType->print(llvm::outs());
    llvm::outs() << "\n";

    if(context.CurrFunction == NULL){
        // global variable
        cout << "declaration global variable " << id.name << endl;

        context.ChangeToGlobalBB();

        // if redefine
        llvm::Value *tmp = context.Module->getGlobalVariable(id.name, true);
        if(tmp != nullptr){
            throw logic_error("Redefined Global Variable: " + id.name);
            return NULL;
        }

        // 3rd argument is const or not, which we don't implement
        auto Alloc = new llvm::GlobalVariable(
            *(context.Module),
            VarType,
            false,
            llvm::Function::ExternalLinkage,
            0,
            id.name
        );

        llvm::Constant* Initializer;
        // array
        if(VarType->isArrayTy()){
            llvm::Type *eleType = VarType->getArrayElementType();

            std::vector<llvm::Constant*> constArrayEle;
            // create the constant initializer
            llvm::Constant* constEle = llvm::ConstantInt::get(eleType, 0);
            int size = VarType->getArrayNumElements();
            for (int i = 0; i < size; i++) {
                constArrayEle.push_back(constEle);
            }
            Initializer = llvm::ConstantArray::get(llvm::ArrayType::get(eleType, size), constArrayEle);
        }
        // not an array
        else{
            // if global we check no currfunction
            // so we use GlobalBB to do Assign
            Initializer = llvm::ConstantInt::get(VarType, 0);
            if (assignmentExpr) {
                Assign ass(id, *assignmentExpr);
                Initializer = (llvm::Constant *)typeCast((llvm::Value *)ass.codeGen(context), VarType);
            }
        }

        Alloc->setInitializer(Initializer);

        context.ChangeToTmpBB();

        return Alloc;
    }
    else{
        // local variable
        cout << "declaration local variable " << id.name << endl;
        llvm::Function *Func = context.CurrFunction;

        // declaration in function
        // create an alloca instruction in the entry block of the current function,
        // wherever the variable declaration is.
        llvm::IRBuilder<> TmpB(&Func->getEntryBlock(), Func->getEntryBlock().begin());
        llvm::AllocaInst* Alloc = TmpB.CreateAlloca(VarType, 0, id.name);
        if(context.AddVariable(id.name, Alloc) == false) {
            // 当前域中有该变量, 重复定义
            Alloc->eraseFromParent();
            throw logic_error("Redefined Local Variable: " + id.name);
            return NULL;
        }

        // not a array
        if (assignmentExpr) {
            Assign ass(id, *assignmentExpr);
            ass.codeGen(context);
        }

        return Alloc;
        /*
        //Assign the initial value by "store" instruction.
        if (NewVar->_InitialExpr) {
            llvm::Value* Initializer = TypeCasting(NewVar->_InitialExpr->codeGen(context), VarType);
            if (Initializer == NULL) {
                throw std::logic_error("Initializing variable " + NewVar->_Name + " with value of different type.");
                return NULL;
            }
            IRBuilder.CreateStore(Initializer, Alloc);
        }
        */
    }
}

/*
// to be implement
llvm::Value* ExternDeclaration::codeGen(CodeGenerator& context){
    return NULL;
}
*/

llvm::Value* FunctionDeclaration::codeGen(CodeGenerator& context){
    // get the ArgTypes
    std::vector<llvm::Type*> ArgTypes;
    for(auto i: (this->arguments)){
        llvm::Type* tp = i->type.getLLVMType();
        // std::cout << "arg_type:"<< i->type.type <<std::endl;
        if (!tp) {
            throw std::logic_error("Defining a function " + i->id.name + " using unknown type(s).");
            return NULL;
        }

        // check if it is a "void" type
        if (tp->isVoidTy()){
            if(arguments.size() > 1){
                throw std::logic_error("function has more than one arguemnt with void type.");
                return NULL;
            }
            else{
                // no arguments
                break;
            }
        }

        // when the function argument type is an array type, we don't pass the entire array.
        // we just pass a pointer pointing to its elements
        if (tp->isArrayTy()){  
            tp = tp->getArrayElementType()->getPointerTo();
        }

        ArgTypes.push_back(tp);
    }
    // std::cout << "ArgTypes_size:" << ArgTypes.size()  << std::endl;

    // get return type
    // array or pointer need to change in parser.y
    llvm::Type* RetType = this->type.getLLVMType();

    // get function type
    // 3rd argument is whether arg has ...
    llvm::FunctionType* FuncType = llvm::FunctionType::get(RetType, ArgTypes, false);

    // create function
    llvm::Function* Func = llvm::Function::Create(FuncType, llvm::GlobalValue::ExternalLinkage, this->id.name, context.Module);
    // context.AddFunction(this->id.name, Func);

    // implement function block

    // create a new basic block to start insertion into. global Context
    llvm::BasicBlock* FuncBlock = llvm::BasicBlock::Create(Context, "entry", Func);
    IRBuilder.SetInsertPoint(FuncBlock);

    // create allocated space for arguments.
	// this variable table is only used to store the arguments of the function
    context.PushSymbolTable();
    size_t Index = 0;
    for (auto ArgIter = Func->arg_begin(); ArgIter < Func->arg_end(); ArgIter++, Index++) {
        // Create alloc
        llvm::IRBuilder<> TmpB(&Func->getEntryBlock(), Func->getEntryBlock().begin());
        auto Alloc = TmpB.CreateAlloca(ArgTypes[Index], 0, this->arguments[Index]->id.name);

        //Create alloca
        // auto Alloc = CreateEntryBlockAlloca(Func, this->arguments[Index]->id.name, ArgTypes[Index]);
        // //Assign the value by "store" instruction
        // IRBuilder.CreateStore(ArgIter, Alloc);

        // Assign the value by "store" instruction
        //  cout << "1111" <<endl;

        IRBuilder.CreateStore(ArgIter, Alloc);
        // Add to the symbol table
        context.AddVariable(this->arguments[Index]->id.name, Alloc);
        //   cout << this->arguments[Index]->id.name <<endl;
    }
    //Generate code of the function body
    context.EnterFunction(Func);
    context.PushSymbolTable();
    this->block.codeGen(context);
    context.PopSymbolTable();
    context.LeaveFunction();
    context.PopSymbolTable();	// why we need to pop out an extra variable table?

    return NULL;
}

llvm::Value* ExpressionStatement::codeGen(CodeGenerator &context){
    cout << "Generate Expression Statement" << endl;
    return expression.codeGen(context);
}

llvm::Value* ReturnStatement::codeGen(CodeGenerator &context){
    cout << "Generate Return Statement" << endl;
    llvm::Function* Func = context.GetCurrentFunction();
    if(Func == nullptr){
        throw std::logic_error("Return statement with no function body");
        return NULL;
    }
    if(expression == nullptr){
        // here in minic use a bool var hasReturn 
        if (Func->getReturnType()->isVoidTy()){
            return IRBuilder.CreateRetVoid();
        }
        else{
            throw std::logic_error("should return void");
            return NULL;
        }
    }else{
        llvm::Value *ret = this->expression->codeGen(context);
        llvm::Value *RetVal = typeCast(ret, Func->getReturnType());
        if (RetVal == NULL) {
            throw std::logic_error("The type of return value doesn't match");
            return NULL;
        }
        else{
            return IRBuilder.CreateRet(RetVal);
        }
    }
}

// Create an unconditional branch if the current block doesn't have a terminator.
// This function is safer than IRBuilder.CreateBr(llvm::BasicBlock* BB),
// because if the current block already has a terminator, it does nothing.
// For example, when generating if-statement, we create three blocks: ThenBB, ElseBB, MergeBB.
// At the end of ThenBB and ElseBB, an unconditional branch to MergeBB needs to be created respectively,
// UNLESS ThenBB or ElseBB is already terminated.
// e.g.
//	if (i) break;
//	else continue;
llvm::BranchInst* TerminateBlockByBr(llvm::BasicBlock* BB) {
	//If not terminated, jump to the target block
	if (!IRBuilder.GetInsertBlock()->getTerminator())
		return IRBuilder.CreateBr(BB);
	else
		return NULL;
}

/*
llvm::Value* LoopStatement::codeGen(CodeGenerator &context){ }
*/

llvm::Value* IfStatement::codeGen(CodeGenerator &context){
    cout << "create if statement " << endl;
    // evaluate condition
    llvm::Value* Condition = this->condition.codeGen(context);

    // check condition
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }

    //Create "Then", "Else" and "Merge" block
    llvm::Function* CurrentFunc = context.GetCurrentFunction();
    llvm::BasicBlock* ThenBB = llvm::BasicBlock::Create(Context, "Then");
    llvm::BasicBlock* ElseBB = llvm::BasicBlock::Create(Context, "Else");
    llvm::BasicBlock* MergeBB = llvm::BasicBlock::Create(Context, "Merge");

    //Create a branch instruction corresponding to this if statement
    IRBuilder.CreateCondBr(Condition, ThenBB, ElseBB);

    //Generate code in the "Then" block
    CurrentFunc->getBasicBlockList().push_back(ThenBB);
    IRBuilder.SetInsertPoint(ThenBB);
    context.PushSymbolTable();
    this->next.codeGen(context);
    context.PopSymbolTable();
    TerminateBlockByBr(MergeBB);

    //Generate code in the "Else" block
    CurrentFunc->getBasicBlockList().push_back(ElseBB);
    IRBuilder.SetInsertPoint(ElseBB);
    if(else_next){
        context.PushSymbolTable();
        this->else_next->codeGen(context);
        context.PopSymbolTable();
    }
    TerminateBlockByBr(MergeBB);

    //Finish "Merge" block
    /* The hasNPredecessorsOrMore() method is used to determine if the Merge block has at least one predecessor (i.e., if it was actually used).  */
    if (MergeBB->hasNPredecessorsOrMore(1)) {
        CurrentFunc->getBasicBlockList().push_back(MergeBB);
        IRBuilder.SetInsertPoint(MergeBB);
    }
    return NULL;
}

llvm::Value* WhileStatement::codeGen(CodeGenerator &context){
    llvm::Function* CurrentFunc = context.GetCurrentFunction();

    llvm::BasicBlock* WhileCondBB = llvm::BasicBlock::Create(Context, "WhileCond");
    llvm::BasicBlock* WhileLoopBB = llvm::BasicBlock::Create(Context, "WhileLoop");
    llvm::BasicBlock* WhileEndBB = llvm::BasicBlock::Create(Context, "WhileEnd");

    // we need a unconditional branch to get in the loop
    IRBuilder.CreateBr(WhileCondBB);

    CurrentFunc->getBasicBlockList().push_back(WhileCondBB);
    IRBuilder.SetInsertPoint(WhileCondBB);

    // evaluate condition
    llvm::Value* Condition = this->condition.codeGen(context);

    // check condition
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }

    IRBuilder.CreateCondBr(Condition, WhileLoopBB, WhileEndBB);
    //Generate code in the "WhileLoop" block
    CurrentFunc->getBasicBlockList().push_back(WhileLoopBB);
    IRBuilder.SetInsertPoint(WhileLoopBB);

    context.EnterLoop(WhileCondBB, WhileEndBB);
    context.PushSymbolTable();
    this->LoopBody.codeGen(context);
    context.PopSymbolTable();
    context.LeaveLoop();

    // point: end in while condBB
    TerminateBlockByBr(WhileCondBB);

    //Finish "WhileEnd" block
    CurrentFunc->getBasicBlockList().push_back(WhileEndBB);
    IRBuilder.SetInsertPoint(WhileEndBB);
    return NULL;
}

llvm::Value* ForStatement::codeGen(CodeGenerator &context){
    cout << "ForStatement"<< endl;

    llvm::Function* CurrentFunc = context.GetCurrentFunction();

    llvm::BasicBlock* ForCondBB = llvm::BasicBlock::Create(Context, "ForCond");
    llvm::BasicBlock* ForLoopBB = llvm::BasicBlock::Create(Context, "ForLoop");
    llvm::BasicBlock* ForTailBB = llvm::BasicBlock::Create(Context, "ForTail");
    llvm::BasicBlock* ForEndBB = llvm::BasicBlock::Create(Context, "ForEnd");

    // if (this->Initial) {
    context.PushSymbolTable();
    cout << "For init" << endl;
    this->Initial.codeGen(context);
    cout << "For end" << endl;
    TerminateBlockByBr(ForCondBB);

    //Generate code in the "ForCond" block
    CurrentFunc->getBasicBlockList().push_back(ForCondBB);
    IRBuilder.SetInsertPoint(ForCondBB);


    // evaluate condition
    llvm::Value* Condition = this->condition.codeGen(context);

    // check condition
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }

    IRBuilder.CreateCondBr(Condition, ForLoopBB, ForEndBB);

    //Otherwise, it is an unconditional loop condition (always returns true)
    // IRBuilder.CreateBr(ForLoopBB);

    //Generate code in the "ForLoop" block
    CurrentFunc->getBasicBlockList().push_back(ForLoopBB);
    IRBuilder.SetInsertPoint(ForLoopBB);

    // here in yjj continue goes to ForTailBB, which maybe wrong
    // if a "continue" in "for", tha last part of "for" will not be executed
    context.EnterLoop(ForCondBB, ForEndBB);
    context.PushSymbolTable();
    this->LoopBody.codeGen(context);
    context.PopSymbolTable();
    context.LeaveLoop();

    //If not terminated, jump to "ForTail"
    TerminateBlockByBr(ForTailBB);

    //Generate code in the "ForTail" block
    CurrentFunc->getBasicBlockList().push_back(ForTailBB);
    IRBuilder.SetInsertPoint(ForTailBB);
    this->Tail.codeGen(context);
    IRBuilder.CreateBr(ForCondBB);

    //Finish "ForEnd" block
    CurrentFunc->getBasicBlockList().push_back(ForEndBB);
    IRBuilder.SetInsertPoint(ForEndBB);
    // if (this->Initial) {
        context.PopSymbolTable();
    return NULL;
}

// copy in BianaryOp
llvm::Value* CreateCmpEQ(llvm::Value* left, llvm::Value* right) {
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
                throw logic_error("cann't use bool in cmp");
            }
        }
    }
    if(left->getType() == llvm::Type::getFloatTy(Context))
        return IRBuilder.CreateFCmpOEQ(left, right, "fcmptmp");
    else 
        return IRBuilder.CreateICmpEQ(left, right, "icmptmp");
}

// just copy yjj
llvm::Value* SwitchStatement::codeGen(CodeGenerator &context){
    llvm::Function* CurrentFunc = context.GetCurrentFunction();
    llvm::Value* Matches = this->matches.codeGen(context);

    //Create one block for each case statement.
    std::vector<llvm::BasicBlock*> CaseBB;
    for (int i = 0; i < this->caseList.size(); i++){
        CaseBB.push_back(llvm::BasicBlock::Create(Context, "Case" + std::to_string(i)));
    }
    //Create an extra block for SwitchEnd
    CaseBB.push_back(llvm::BasicBlock::Create(Context, "SwitchEnd"));

    //Create one block for each comparison.
    std::vector<llvm::BasicBlock*> ComparisonBB;
    ComparisonBB.push_back(IRBuilder.GetInsertBlock());
    for (int i = 1; i < this->caseList.size(); i++){
        ComparisonBB.push_back(llvm::BasicBlock::Create(Context, "Comparison" + std::to_string(i)));
    }
    ComparisonBB.push_back(CaseBB.back());

    //Generate branches
    for (int i = 0; i < this->caseList.size(); i++) {
        if (i) {
            CurrentFunc->getBasicBlockList().push_back(ComparisonBB[i]);
            IRBuilder.SetInsertPoint(ComparisonBB[i]);
        }
        if (this->caseList[i]->condition)	//Have condition
            IRBuilder.CreateCondBr(
                CreateCmpEQ(Matches, this->caseList[i]->condition->codeGen(context)),
                CaseBB[i],
                ComparisonBB[i + 1]
            );
        else									//Default
            IRBuilder.CreateBr(CaseBB[i]);
    }

    //Generate code for each case statement
    context.PushSymbolTable();
    for (int i = 0; i < this->caseList.size(); i++) {
        CurrentFunc->getBasicBlockList().push_back(CaseBB[i]);
        IRBuilder.SetInsertPoint(CaseBB[i]);
        context.EnterLoop(CaseBB[i + 1], CaseBB.back());
        this->caseList[i]->codeGen(context);
        context.LeaveLoop();
    }
    context.PopSymbolTable();

    //Finish "SwitchEnd" block
    if (CaseBB.back()->hasNPredecessorsOrMore(1)) {
        CurrentFunc->getBasicBlockList().push_back(CaseBB.back());
        IRBuilder.SetInsertPoint(CaseBB.back());
    }
    return NULL;
}

llvm::Value* CaseStatement::codeGen(CodeGenerator &context){
    // //Generate the statements, one by one.
    // for (auto& stmt : this->body.statementList){
    //     if (IRBuilder.GetInsertBlock()->getTerminator())
    //         break;
    //     else if (stmt)
    //         stmt->codeGen(context);
    // }

    body.codeGen(context);

    //If not terminated, jump to the next case block
    TerminateBlockByBr(context.GetConditionBlock());
    return NULL;
}

llvm::Value* BreakStatement::codeGen(CodeGenerator &context){
    cout << "break,codegen" << endl;
    llvm::BasicBlock* BreakPoint = context.GetEndBlock();
    if (BreakPoint)
        IRBuilder.CreateBr(BreakPoint);
    else
        throw std::logic_error("Break statement should only be used in loops or switch statements.");
    return NULL;
}

llvm::Value* ContinueStatement::codeGen(CodeGenerator &context){
		llvm::BasicBlock* ContinuePoint = context.GetEndBlock();
		if (ContinuePoint)
			IRBuilder.CreateBr(ContinuePoint);
		else
			throw std::logic_error("Continue statement should only be used in loops or switch statements.");
		return NULL;
}