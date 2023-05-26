
llvm::Value* ReturnStatement::codeGen(CodeGenerator &context)
其中拿到return type yjj使用Func->GetReturnType(), 这是否意味着在创建函数的时候就要将某个地方设置一下, 在哪里, function declaration 是否应该改.

解释: 
在FunctionDeclaration里, 这一段

```c++
// get function type
// 3rd argument is whether arg has ...
llvm::FunctionType* FuncType = llvm::FunctionType::get(RetType, ArgTypes, false);

// create function
llvm::Function* Func = llvm::Function::Create(FuncType, llvm::GlobalValue::ExternalLinkage, this->id.name, context.Module);
context.AddFunction(this->id.name, Func);
```

可以看到在FucnType里就已经定义RetType与ArgTypes. 

