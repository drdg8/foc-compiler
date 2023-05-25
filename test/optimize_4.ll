; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [40 x i8] c"Fibonacci number at position %d is: %d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @fibonacci(i32 %0) {
entry:
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  %LoadInst = load i32, i32* %n, align 4
  %icmptmp = icmp sle i32 %LoadInst, 1
  br i1 %icmptmp, label %Then, label %Else

Then:                                             ; preds = %entry
  %LoadInst1 = load i32, i32* %n, align 4
  ret i32 %LoadInst1

Else:                                             ; preds = %entry
  %LoadInst2 = load i32, i32* %n, align 4
  %1 = sub i32 %LoadInst2, 1
  %2 = call i32 @fibonacci(i32 %1)
  %LoadInst3 = load i32, i32* %n, align 4
  %3 = sub i32 %LoadInst3, 2
  %4 = call i32 @fibonacci(i32 %3)
  %5 = add i32 %2, %4
  ret i32 %5
}

define i32 @main() {
entry:
  %n = alloca i32, align 4
  store i32 10, i32* %n, align 4
  %LoadInst = load i32, i32* %n, align 4
  %LoadInst1 = load i32, i32* %n, align 4
  %0 = call i32 @fibonacci(i32 %LoadInst1)
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([40 x i8], [40 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst, i32 %0)
  ret i32 0
}
