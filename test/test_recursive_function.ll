; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [21 x i8] c"Factorial of %d: %d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @factorial(i32 %0) {
entry:
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  %LoadInst = load i32, i32* %n, align 4
  %icmptmp = icmp eq i32 %LoadInst, 0
  br i1 %icmptmp, label %Then, label %Else

Then:                                             ; preds = %entry
  ret i32 1

Else:                                             ; preds = %entry
  %LoadInst1 = load i32, i32* %n, align 4
  %LoadInst2 = load i32, i32* %n, align 4
  %1 = sub i32 %LoadInst2, 1
  %2 = call i32 @factorial(i32 %1)
  %3 = mul i32 %LoadInst1, %2
  ret i32 %3
}

define i32 @main() {
entry:
  %num = alloca i32, align 4
  store i32 5, i32* %num, align 4
  %LoadInst = load i32, i32* %num, align 4
  %LoadInst1 = load i32, i32* %num, align 4
  %0 = call i32 @factorial(i32 %LoadInst1)
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst, i32 %0)
  ret i32 0
}
