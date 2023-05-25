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
        std::vector<llvm::Value*> indices = {IRBuilder.getInt32(0), IRBuilder.getInt32(0)};
        res = IRBuilder.CreateConstGEP2_32(tp, var, 0, 0, "arrayPtr");
    }
    else {
        res = IRBuilder.CreateLoad(tp, var, "LoadInst");
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




// 利用yacc中的EQUAL来代表赋值操作
// 形式如：变量 = 表达式
llvm::Value* Assign::codeGen(CodeGenerator &context){
    std::cout << "处理赋值操作，变量名为：" << ident.name << std::endl;

    // 查找变量并获取其值，如果找不到该变量则抛出错误
    llvm::Value* targetValue = context.FindVariable(ident.name);
    if(targetValue == nullptr){
        std::cerr << "尝试赋值给未声明的变量 " << ident.name << std::endl;
		return nullptr;
    }

    // 打印变量的类型信息
    llvm::Type* targetType = targetValue->getType();
    typePrint(targetValue);

    // 生成表达式的代码并获取其值
    llvm::Value* exprValue = expr.codeGen(context);
    std::cout << "表达式的值为：";
    typePrint(exprValue);

    // 获取当前的代码块
    auto CurrentBlock = IRBuilder.GetInsertBlock();

    // 如果表达式的值与目标变量的类型不同，则进行类型转换
    if (exprValue->getType() != targetValue->getType()->getPointerElementType())
        exprValue = typeCast(exprValue, targetValue->getType()->getPointerElementType());

    // 如果无法进行类型转换，则抛出错误
    if (exprValue == nullptr) {
		throw std::domain_error("无法将表达式的值转换为目标变量的类型。");
		return nullptr;
	}

    // 在 LLVM IR 中创建一个 store 指令，将表达式的值存储到目标变量中
    IRBuilder.CreateStore(exprValue, targetValue);

    return exprValue;
}

// 对应如 a[2] 的数组元素访问
llvm::Value* ArrayElement::codeGen(CodeGenerator &context){
    std::cout << "正在访问数组元素，数组名为：" << identifier.name << "[]" << std::endl;

    // 查找数组并获取其值，如果找不到该数组则报错
    llvm::Value* arrayValue = context.FindVariable(identifier.name);
    if(arrayValue == nullptr){
        std::cerr << "尝试访问未声明的数组 " << identifier.name << std::endl;
		return nullptr;
    }

    std::cout << "访问的数组索引为：" << std::endl;
    llvm::Value* indexValue = index.codeGen(context);

    // 检查索引值是否为整数类型
    if (!indexValue->getType()->isIntegerTy()) {
        std::cerr << "数组索引值不是整数类型" << std::endl;
        return nullptr;
    }

    vector<llvm::Value*> indexList;

    // 打印数组变量的类型信息
    typePrint(arrayValue);

    // 如果 arrayValue 的类型是指针类型，则载入指针所指向的值
    if(arrayValue->getType()->getPointerElementType()->isPointerTy()) {
        arrayValue = IRBuilder.CreateLoad(arrayValue->getType()->getPointerElementType(), arrayValue);
        indexList = {indexValue};    
    }
    // 如果 arrayValue 的类型是数组类型，则添加索引值
    else if(arrayValue->getType()->getPointerElementType()->isArrayTy()) {
        indexList = {IRBuilder.getInt32(0),indexValue};
    }
    // 如果 arrayValue 的类型既不是指针类型也不是数组类型，则报错
    else{
        std::cerr << "[] 只能用于指针或数组" << std::endl;
        return nullptr;
    }

    // 创建一个 GEP 指令来计算元素的地址
    llvm::Value* elePtr = IRBuilder.CreateInBoundsGEP(arrayValue->getType()->getPointerElementType(), arrayValue, llvm::ArrayRef<llvm::Value*>(indexList), "tmparray");

    // 载入并返回元素的值
    return IRBuilder.CreateLoad(elePtr->getType()->getPointerElementType(), elePtr, "tmpvar");
}


// 该函数获取 array[index] 的地址以用于函数参数传递
llvm::Value* ArrayElement::getAddr(CodeGenerator &context){
    std::cout << "正在获取数组元素地址，目标数组：" << identifier.name << "[]" << std::endl;

    // 在上下文中寻找数组变量，如果找不到，返回错误
    llvm::Value* arrVal = context.FindVariable(identifier.name);
    if(!arrVal){
        std::cerr << "无法找到数组 " << identifier.name << std::endl;
		return nullptr;
    }
    // 生成数组索引
    llvm::Value* idxVal = index.codeGen(context);
    vector<llvm::Value*> idxVec;
    // 如果 arrVal 是指针类型
    if(arrVal->getType()->getPointerElementType()->isPointerTy()) {
        arrVal = IRBuilder.CreateLoad(arrVal->getType()->getPointerElementType(), arrVal);
        idxVec.push_back(idxVal);    
    }
    // 如果 arrVal 是数组类型
    else {
        idxVec.push_back(IRBuilder.getInt32(0));
        idxVec.push_back(idxVal);    
    }
    // 生成 GEP 指令以计算元素地址，然后返回
    llvm::Value* elementPtr = IRBuilder.CreateInBoundsGEP(arrVal->getType()->getPointerElementType(), arrVal, llvm::ArrayRef<llvm::Value*>(idxVec), "tmparray");
    return elementPtr;
}

// ArrayAssign 函数用于对数组元素进行赋值操作，例如 a[2] = 5;
llvm::Value* ArrayAssign::codeGen(CodeGenerator &context){
    std::cout << "正在进行数组元素赋值操作，目标数组：" << identifier.name << "[]" << std::endl;

    // 在上下文中寻找数组变量，如果找不到，返回错误
    llvm::Value* arrVal = context.FindVariable(identifier.name);
    if(!arrVal){
        std::cerr << "无法找到数组 " << identifier.name << std::endl;
		return nullptr;
    }

    // 生成数组索引
    llvm::Value* idxVal = index.codeGen(context);
    vector<llvm::Value*> idxVec;

    // 打印目标数组的类型
    llvm::errs() << "目标数组的类型为：";
    arrVal->getType()->print(llvm::errs());
    llvm::errs() << '\n';

    // 如果 arrVal 是指针类型
    if(arrVal->getType()->getPointerElementType()->isPointerTy()) {
        arrVal = IRBuilder.CreateLoad(arrVal->getType()->getPointerElementType(), arrVal);
        idxVec = {idxVal};    
    }
    // 如果 arrVal 是数组类型
    else {
        idxVec = {IRBuilder.getInt32(0),idxVal};
    }

    // 使用 GEP 指令计算左值（待赋值元素）的地址
    llvm::Value* left =  IRBuilder.CreateInBoundsGEP(arrVal->getType()->getPointerElementType(), arrVal, llvm::ArrayRef<llvm::Value*>(idxVec), "tmpvar");
    
    // 生成右值（即赋值表达式）
    llvm::Value* right = rhs.codeGen(context);

    // 检查类型，并在需要时进行类型转换
    if (right->getType() != left->getType()->getPointerElementType())
        right = typeCast(right, left->getType()->getPointerElementType());

    // 执行赋值操作并返回结果
    return IRBuilder.CreateStore(right, left);
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
    std::cout << "正在取得数组元素地址：" << rhs.name << "[]" << std::endl;

    llvm::Value* arrayVal = context.FindVariable(rhs.name);
    if(arrayVal == nullptr){
        std::cerr << "未声明的数组 " << rhs.name << std::endl;
		return nullptr;
    }

    llvm::Value* indexVal = index.codeGen(context);
    std::vector<llvm::Value*> idxList;

    // 如果目标是指针
    if(arrayVal->getType()->getPointerElementType()->isPointerTy()) {
        arrayVal = IRBuilder.CreateLoad(arrayVal->getType()->getPointerElementType(), arrayVal);
        idxList = {indexVal};
    }
    // 如果目标是数组 
    else {
        idxList = {IRBuilder.getInt32(0),indexVal};
    }

    // 获取元素指针
    llvm::Value* elePtr = IRBuilder.CreateInBoundsGEP(arrayVal->getType()->getPointerElementType(), arrayVal, llvm::ArrayRef<llvm::Value*>(idxList), "elePtr");
    return elePtr;
}


llvm::Value* Block::codeGen(CodeGenerator &context){
    // 将新的符号表压入符号表栈中，为这个块创建新的作用域
    context.PushSymbolTable();
    
    std::cout << "语句列表大小为：" << statementList.size() << std::endl;
    
    llvm::Value* tmp = NULL;
    
    // 遍历语句列表，对每个语句调用其 codeGen 方法生成对应的 IR
    for(auto stmt : statementList){
        std::cout << "正在为 " << typeid(*stmt).name() << " 生成代码" << std::endl;
        
        // 检查当前函数是否存在，并且是否已经有一个终结器（例如 return 语句）
        // 如果已经有了终结器，就无需处理余下的语句，因此跳出循环
        if (context.GetCurrentFunction() != NULL && IRBuilder.GetInsertBlock()->getTerminator()) {  
             break;
        }
        // 如果语句存在，则调用它的 codeGen 方法生成代码
        else if (stmt){
            stmt->codeGen(context);
        }
    }
    std::cout << std::endl;
    
    // 语句块已经处理完毕，将符号表从符号表栈中弹出，恢复到原先的作用域
    context.PopSymbolTable();
    
    // 由于块语句本身没有值，所以返回 NULL
    return NULL;
}


// VariableDeclaration 的 codeGen 方法负责生成变量声明的 LLVM IR 代码
llvm::Value* VariableDeclaration::codeGen(CodeGenerator &context){
    // 首先从变量声明中获取对应的 LLVM 类型
    llvm::Type* VarType = type.getLLVMType();

    llvm::outs() << "变量声明：类型 ";
    VarType->print(llvm::outs());
    llvm::outs() << "\n";

    if(context.CurrFunction == NULL){
        // 全局变量
        std::cout << "声明全局变量 " << id.name << std::endl;

        context.ChangeToGlobalBB();

        // 检查全局变量是否重复定义
        if(context.Module->getGlobalVariable(id.name, true) != nullptr){
            throw std::logic_error("全局变量重复定义: " + id.name);
            return NULL;
        }

        // 创建全局变量
        auto Alloc = new llvm::GlobalVariable(*(context.Module), VarType, false, llvm::Function::ExternalLinkage, 0, id.name);

        llvm::Constant* Initializer;
        // 如果是数组类型
        if(VarType->isArrayTy()){
            Initializer = createArrayInitializer(VarType);
        }
        // 不是数组类型
        else{
            Initializer = createVariableInitializer(VarType, context, assignmentExpr);
        }

        Alloc->setInitializer(Initializer);
        context.ChangeToTmpBB();

        return Alloc;
    }
    else{
        // 局部变量
        std::cout << "声明局部变量 " << id.name << std::endl;
        llvm::Function *Func = context.CurrFunction;

        // 在函数的入口块创建 alloca 指令来为变量分配空间
        llvm::IRBuilder<> TmpB(&Func->getEntryBlock(), Func->getEntryBlock().begin());
        llvm::AllocaInst* Alloc = TmpB.CreateAlloca(VarType, 0, id.name);

        // 检查变量是否在当前作用域内重复定义
        if(!context.AddVariable(id.name, Alloc)) {
            Alloc->eraseFromParent();
            throw std::logic_error("局部变量重复定义: " + id.name);
            return NULL;
        }

        // 如果存在赋值表达式，那么就生成对应的赋值代码
        if (assignmentExpr) {
            Assign ass(id, *assignmentExpr);
            ass.codeGen(context);
        }

        return Alloc;
    }
}

// 创建数组的初始化常量
llvm::Constant* VariableDeclaration::createArrayInitializer(llvm::Type* VarType){
    llvm::Type *eleType = VarType->getArrayElementType();

    std::vector<llvm::Constant*> constArrayEle;
    llvm::Constant* constEle = llvm::ConstantInt::get(eleType, 0);
    int size = VarType->getArrayNumElements();
    for (int i = 0; i < size; i++) {
        constArrayEle.push_back(constEle);
    }

    return llvm::ConstantArray::get(llvm::ArrayType::get(eleType, size), constArrayEle);
}

// 创建变量的初始化常量
llvm::Constant* VariableDeclaration::createVariableInitializer(llvm::Type* VarType, CodeGenerator& context, Expression* assignmentExpr){
    llvm::Constant* Initializer = llvm::ConstantInt::get(VarType, 0);
    if (assignmentExpr) {
        Assign ass(id, *assignmentExpr);
        Initializer = static_cast<llvm::Constant *>(typeCast(static_cast<llvm::Value *>(ass.codeGen(context)), VarType));
    }

    return Initializer;
}

// FunctionDeclaration的codeGen方法负责生成函数声明的LLVM IR代码
llvm::Value* FunctionDeclaration::codeGen(CodeGenerator& context) {
    // 从函数声明中获取参数类型
    std::vector<llvm::Type*> ArgTypes = getArgTypes(context);

    // 获取返回类型
    llvm::Type* RetType = this->type.getLLVMType();

    // 获取函数类型
    llvm::FunctionType* FuncType = llvm::FunctionType::get(RetType, ArgTypes, false);

    // 创建函数
    llvm::Function* Func = llvm::Function::Create(FuncType, llvm::GlobalValue::ExternalLinkage, this->id.name, context.Module);

    // 创建一个新的基本块作为函数体的入口
    llvm::BasicBlock* FuncBlock = llvm::BasicBlock::Create(Context, "entry", Func);
    IRBuilder.SetInsertPoint(FuncBlock);

    // 创建参数对应的存储空间
    createArgAllocs(context, Func, ArgTypes);

    // 生成函数体的代码
    generateFuncBody(context, Func);

    return NULL;
}

// 从函数声明中获取参数类型
std::vector<llvm::Type*> FunctionDeclaration::getArgTypes(CodeGenerator& context) {
    std::vector<llvm::Type*> ArgTypes;
    for(auto i: this->arguments) {
        llvm::Type* tp = i->type.getLLVMType();
        if (!tp) {
            throw std::logic_error("使用未知类型定义函数 " + i->id.name);
            return {};
        }
        if (tp->isVoidTy()){
            if(arguments.size() > 1){
                throw std::logic_error("函数有多个参数类型为void.");
                return {};
            }
            else{
                break;
            }
        }
        // 如果函数参数类型为数组类型，则传递指向其元素的指针，而不是整个数组
        if (tp->isArrayTy()){  
            tp = tp->getArrayElementType()->getPointerTo();
        }
        ArgTypes.push_back(tp);
    }
    return ArgTypes;
}

// 创建函数参数对应的存储空间
void FunctionDeclaration::createArgAllocs(CodeGenerator& context, llvm::Function* Func, std::vector<llvm::Type*>& ArgTypes) {
    context.PushSymbolTable();
    size_t Index = 0;
    for (auto ArgIter = Func->arg_begin(); ArgIter < Func->arg_end(); ArgIter++, Index++) {
        // 在函数的入口块创建 alloca 指令来为参数分配空间
        llvm::IRBuilder<> TmpB(&Func->getEntryBlock(), Func->getEntryBlock().begin());
        auto Alloc = TmpB.CreateAlloca(ArgTypes[Index], 0, this->arguments[Index]->id.name);

        IRBuilder.CreateStore(ArgIter, Alloc);

        context.AddVariable(this->arguments[Index]->id.name, Alloc);
    }
}

// 生成函数体的代码
void FunctionDeclaration::generateFuncBody(CodeGenerator& context, llvm::Function* Func) {
    context.EnterFunction(Func);
    context.PushSymbolTable();
    this->block.codeGen(context);
    context.PopSymbolTable();
    context.LeaveFunction();
}

// ExpressionStatement的codeGen方法负责生成表达式语句的LLVM IR代码
llvm::Value* ExpressionStatement::codeGen(CodeGenerator &context){
    // 在控制台打印出当前正在生成的语句类型，帮助调试
    cout << "Generate Expression Statement" << endl;
    // 生成表达式的代码
    return expression.codeGen(context);
}

// ReturnStatement的codeGen方法负责生成返回语句的LLVM IR代码
llvm::Value* ReturnStatement::codeGen(CodeGenerator &context){
    // 在控制台打印出当前正在生成的语句类型，帮助调试
    cout << "Generate Return Statement" << endl;

    // 获取当前的函数上下文，如果没有就报错
    llvm::Function* Func = context.GetCurrentFunction();
    if(Func == nullptr){
        throw std::logic_error("Return statement with no function body");
        return NULL;
    }

    // 如果没有表达式（即没有返回值），则生成返回void的代码；如果有表达式，则生成返回该表达式值的代码
    if(expression == nullptr){
        if (Func->getReturnType()->isVoidTy()){
            return IRBuilder.CreateRetVoid();
        }else{
            throw std::logic_error("should return void");
            return NULL;
        }
    }else{
        // 生成表达式的代码，并进行类型转换，确保返回的类型与函数声明的返回类型匹配
        llvm::Value *ret = this->expression->codeGen(context);
        llvm::Value *RetVal = typeCast(ret, Func->getReturnType());
        if (RetVal == NULL) {
            throw std::logic_error("The type of return value doesn't match");
            return NULL;
        }else{
            return IRBuilder.CreateRet(RetVal);
        }
    }
}


// TerminateBlockByBr方法用于在当前基本块（如果它还没有终止符）的末尾创建一个无条件分支到给定的基本块BB
// 这个方法比直接使用IRBuilder.CreateBr(llvm::BasicBlock* BB)更安全，因为如果当前块已经有一个终止符，它不会做任何事情
// 例如，在生成if语句时，我们创建了三个块：ThenBB，ElseBB和MergeBB
// 在ThenBB和ElseBB的末尾，需要分别创建一个到MergeBB的无条件分支，除非ThenBB或ElseBB已经终止
// 如：
//	if (i) break;
//	else continue;
// 在这种情况下，ThenBB和ElseBB都已经有了终止符，所以不需要再添加分支
llvm::BranchInst* TerminateBlockByBr(llvm::BasicBlock* BB) {
	//如果当前插入块没有终止符，那么创建一个到目标块BB的无条件分支
	if (!IRBuilder.GetInsertBlock()->getTerminator())
		return IRBuilder.CreateBr(BB);
	else
		return NULL;
}



/*
llvm::Value* LoopStatement::codeGen(CodeGenerator &context){ }
*/

// IfStatement::codeGen函数用于生成LLVM中间代码，表示if语句
// 其首先对条件进行求值，并创建对应的Then、Else和Merge基本块
// 然后在Then和Else基本块中分别生成相应的代码
llvm::Value* IfStatement::codeGen(CodeGenerator &context){
    // 打印一条消息，说明正在生成if语句
    cout << "create if statement " << endl;
    // 在这里，我们首先计算条件的值
    llvm::Value* Condition = this->condition.codeGen(context);
    // 然后我们检查条件是否可以转换为布尔值
    // 如果不能转换，我们抛出一个异常并返回NULL
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }
    // 然后我们创建三个基本块：ThenBB，ElseBB和MergeBB
    // 这三个基本块分别用于存放if语句中的then部分，else部分，以及if语句结束后的代码
    llvm::Function* CurrentFunc = context.GetCurrentFunction();
    llvm::BasicBlock* ThenBB = llvm::BasicBlock::Create(Context, "Then");
    llvm::BasicBlock* ElseBB = llvm::BasicBlock::Create(Context, "Else");
    llvm::BasicBlock* MergeBB = llvm::BasicBlock::Create(Context, "Merge");

    // 然后我们创建一个条件分支指令，如果条件为真，就跳转到ThenBB，否则跳转到ElseBB
    IRBuilder.CreateCondBr(Condition, ThenBB, ElseBB);
    // 在ThenBB中生成then部分的代码
    CurrentFunc->getBasicBlockList().push_back(ThenBB);
    IRBuilder.SetInsertPoint(ThenBB);
    context.PushSymbolTable();
    this->next.codeGen(context);
    context.PopSymbolTable();
    TerminateBlockByBr(MergeBB);

    // 在ElseBB中生成else部分的代码，如果有的话
    CurrentFunc->getBasicBlockList().push_back(ElseBB);
    IRBuilder.SetInsertPoint(ElseBB);
    if(else_next){
        context.PushSymbolTable();
        this->else_next->codeGen(context);
        context.PopSymbolTable();
    }
    TerminateBlockByBr(MergeBB);

    // 如果MergeBB有至少一个前驱（即，它被使用了），我们就需要生成MergeBB的代码
    if (MergeBB->hasNPredecessorsOrMore(1)) {
        CurrentFunc->getBasicBlockList().push_back(MergeBB);
        IRBuilder.SetInsertPoint(MergeBB);
    }
    return NULL;
}


// WhileStatement::codeGen方法用于将while语句转换为LLVM IR代码。
// 首先，它会创建一个条件检查块（WhileCondBB）、一个循环体块（WhileLoopBB）和一个循环结束块（WhileEndBB）。
// 然后，它会在WhileCondBB中生成对应于循环条件的代码，并在WhileLoopBB中生成对应于循环体的代码。
llvm::Value* WhileStatement::codeGen(CodeGenerator &context){
    // 获得当前函数
    llvm::Function* CurrentFunc = context.GetCurrentFunction();

    // 创建WhileCondBB、WhileLoopBB和WhileEndBB基本块
    llvm::BasicBlock* WhileCondBB = llvm::BasicBlock::Create(Context, "WhileCond");
    llvm::BasicBlock* WhileLoopBB = llvm::BasicBlock::Create(Context, "WhileLoop");
    llvm::BasicBlock* WhileEndBB = llvm::BasicBlock::Create(Context, "WhileEnd");

    // 创建一个无条件跳转至WhileCondBB的分支
    IRBuilder.CreateBr(WhileCondBB);

    // 在WhileCondBB中生成条件代码
    CurrentFunc->getBasicBlockList().push_back(WhileCondBB);
    IRBuilder.SetInsertPoint(WhileCondBB);
    llvm::Value* Condition = this->condition.codeGen(context);

    // 检查条件是否可以转换为布尔值
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }

    // 创建一个条件分支，如果条件为真，则跳转至WhileLoopBB，否则跳转至WhileEndBB
    IRBuilder.CreateCondBr(Condition, WhileLoopBB, WhileEndBB);

    // 在WhileLoopBB中生成循环体的代码
    CurrentFunc->getBasicBlockList().push_back(WhileLoopBB);
    IRBuilder.SetInsertPoint(WhileLoopBB);
    context.EnterLoop(WhileCondBB, WhileEndBB);
    context.PushSymbolTable();
    this->LoopBody.codeGen(context);
    context.PopSymbolTable();
    context.LeaveLoop();

    // 如果当前块未终止，则创建一个无条件跳转至WhileCondBB的分支
    TerminateBlockByBr(WhileCondBB);

    // 在WhileEndBB中生成后续代码
    CurrentFunc->getBasicBlockList().push_back(WhileEndBB);
    IRBuilder.SetInsertPoint(WhileEndBB);

    return NULL;
}

// ForStatement::codeGen方法用于将for语句转换为LLVM IR代码。
// 首先，它会创建一个条件检查块（ForCondBB）、一个循环体块（ForLoopBB）、一个循环尾部块（ForTailBB）和一个循环结束块（ForEndBB）。
// 然后，它会在ForCondBB中生成对应于循环条件的代码，在ForLoopBB中生成对应于循环体的代码，以及在ForTailBB中生成对应于循环尾部的代码。
llvm::Value* ForStatement::codeGen(CodeGenerator &context){
    // 获得当前函数
    llvm::Function* CurrentFunc = context.GetCurrentFunction();

    // 创建ForCondBB、ForLoopBB、ForTailBB和ForEndBB基本块
    llvm::BasicBlock* ForCondBB = llvm::BasicBlock::Create(Context, "ForCond");
    llvm::BasicBlock* ForLoopBB = llvm::BasicBlock::Create(Context, "ForLoop");
    llvm::BasicBlock* ForTailBB = llvm::BasicBlock::Create(Context, "ForTail");
    llvm::BasicBlock* ForEndBB = llvm::BasicBlock::Create(Context, "ForEnd");

    // 在ForCondBB中生成初始化代码
    context.PushSymbolTable();
    this->Initial.codeGen(context);
    TerminateBlockByBr(ForCondBB);

    // 在ForCondBB中生成条件代码
    CurrentFunc->getBasicBlockList().push_back(ForCondBB);
    IRBuilder.SetInsertPoint(ForCondBB);
    llvm::Value* Condition = this->condition.codeGen(context);

    // 检查条件是否可以转换为布尔值
    if (( Condition = typeCast(Condition, IRBuilder.getInt1Ty()) ) == NULL) {
        throw std::logic_error("condition type can not cast to bool");
        return NULL;
    }

    // 创建一个条件分支，如果条件为真，则跳转至ForLoopBB，否则跳转至ForEndBB
    IRBuilder.CreateCondBr(Condition, ForLoopBB, ForEndBB);

    // 在ForLoopBB中生成循环体的代码
    CurrentFunc->getBasicBlockList().push_back(ForLoopBB);
    IRBuilder.SetInsertPoint(ForLoopBB);
    context.EnterLoop(ForCondBB, ForEndBB);
    context.PushSymbolTable();
    this->LoopBody.codeGen(context);
    context.PopSymbolTable();
    context.LeaveLoop();

    // 如果当前块未终止，则创建一个无条件跳转至ForTailBB的分支
    TerminateBlockByBr(ForTailBB);

    // 在ForTailBB中生成循环尾部的代码，并跳转至ForCondBB
    CurrentFunc->getBasicBlockList().push_back(ForTailBB);
    IRBuilder.SetInsertPoint(ForTailBB);
    this->Tail.codeGen(context);
    IRBuilder.CreateBr(ForCondBB);

    // 在ForEndBB中生成后续代码
    CurrentFunc->getBasicBlockList().push_back(ForEndBB);
    IRBuilder.SetInsertPoint(ForEndBB);
    context.PopSymbolTable();

    return NULL;
}


// 函数功能：将两个llvm::Value*转换为相同的类型。如果两者类型不同，则转换为较高的类型（整数->浮点数）。
std::pair<llvm::Value*, llvm::Value*> CastToSameType(llvm::Value* left, llvm::Value* right) {
    if (left->getType() != right->getType()) {
        llvm::Type* leftType = left->getType();
        llvm::Type* rightType = right->getType();
        if (leftType == llvm::Type::getFloatTy(Context) || rightType == llvm::Type::getFloatTy(Context)) {
            // 如果有一个是浮点类型，则两个都转换为浮点类型
            left = typeCast(left, llvm::Type::getFloatTy(Context));
            right = typeCast(right, llvm::Type::getFloatTy(Context));
        } else if (leftType == llvm::Type::getInt32Ty(Context) || rightType == llvm::Type::getInt32Ty(Context)) {
            // 如果有一个是整型，则两个都转换为整型
            left = typeCast(left, llvm::Type::getInt32Ty(Context));
            right = typeCast(right, llvm::Type::getInt32Ty(Context));
        } else {
            throw logic_error("cann't use bool in cmp");
        }
    }
    return std::make_pair(left, right);
}

// 函数功能：创建一个比较两个llvm::Value*是否相等的表达式。如果两者类型不同，则自动进行类型转换。
llvm::Value* CreateCmpEQ(llvm::Value* left, llvm::Value* right) {
    std::tie(left, right) = CastToSameType(left, right);
    return left->getType() == llvm::Type::getFloatTy(Context) ? 
           IRBuilder.CreateFCmpOEQ(left, right, "fcmptmp") :  // 如果是浮点类型，则使用CreateFCmpOEQ
           IRBuilder.CreateICmpEQ(left, right, "icmptmp");    // 如果是整型，则使用CreateICmpEQ
}

// 函数功能：生成Switch语句的代码
llvm::Value* SwitchStatement::codeGen(CodeGenerator &context){
    // 初始化
    llvm::Function* CurrentFunc = context.GetCurrentFunction();
    llvm::Value* Matches = this->matches.codeGen(context);

    // 为每个case和对比准备blocks
    std::vector<llvm::BasicBlock*> CaseBB(this->caseList.size() + 1);
    std::vector<llvm::BasicBlock*> ComparisonBB(this->caseList.size() + 1);
    for (int i = 0; i < this->caseList.size(); i++) {
        CaseBB[i] = llvm::BasicBlock::Create(Context, "Case" + std::to_string(i));
        ComparisonBB[i] = i ? llvm::BasicBlock::Create(Context, "Comparison" + std::to_string(i)) : IRBuilder.GetInsertBlock();
    }
    CaseBB.back() = llvm::BasicBlock::Create(Context, "SwitchEnd");
    ComparisonBB.back() = CaseBB.back();

    // 为每个case生成代码
    context.PushSymbolTable();
    for (int i = 0; i < this->caseList.size(); i++) {
        // 准备分支
        CurrentFunc->getBasicBlockList().push_back(ComparisonBB[i]);
        IRBuilder.SetInsertPoint(ComparisonBB[i]);
        IRBuilder.CreateCondBr(
            CreateCmpEQ(Matches, this->caseList[i]->condition->codeGen(context)),
            CaseBB[i],
            ComparisonBB[i + 1]
        );

        // 生成case代码
        CurrentFunc->getBasicBlockList().push_back(CaseBB[i]);
        IRBuilder.SetInsertPoint(CaseBB[i]);
        context.EnterLoop(CaseBB[i + 1], CaseBB.back());
        this->caseList[i]->codeGen(context);
        context.LeaveLoop();
    }
    context.PopSymbolTable();

    // 完成"SwitchEnd"块
    if (CaseBB.back()->hasNPredecessorsOrMore(1)) {
        CurrentFunc->getBasicBlockList().push_back(CaseBB.back());
        IRBuilder.SetInsertPoint(CaseBB.back());
    }
    return NULL;
}

// 函数功能：生成Case语句的代码
llvm::Value* CaseStatement::codeGen(CodeGenerator &context){
    this->body.codeGen(context);
    TerminateBlockByBr(context.GetConditionBlock());
    return NULL;
}

// 函数功能：生成Break语句的代码
llvm::Value* BreakStatement::codeGen(CodeGenerator &context){
    cout << "break,codegen" << endl;
    llvm::BasicBlock* BreakPoint = context.GetEndBlock();
    if (BreakPoint)
        IRBuilder.CreateBr(BreakPoint);
    else
        throw std::logic_error("Break statement should only be used in loops or switch statements.");
    return NULL;
}

// 函数功能：生成Continue语句的代码
llvm::Value* ContinueStatement::codeGen(CodeGenerator &context){
		llvm::BasicBlock* ContinuePoint = context.GetEndBlock();
		if (ContinuePoint)
			IRBuilder.CreateBr(ContinuePoint);
		else
			throw std::logic_error("Continue statement should only be used in loops or switch statements.");
		return NULL;
}
