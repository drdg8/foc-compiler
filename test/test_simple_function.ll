; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [20 x i8] c"Sum of a and b: %d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @add(i32 %0, i32 %1) {
entry:
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 %0, i32* %a, align 4
  store i32 %1, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %LoadInst1 = load i32, i32* %b, align 4
  %2 = add i32 %LoadInst, %LoadInst1
  ret i32 %2
}

define i32 @main() {
entry:
  %sum = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 10, i32* %a, align 4
  store i32 5, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %LoadInst1 = load i32, i32* %b, align 4
  %0 = call i32 @add(i32 %LoadInst, i32 %LoadInst1)
  store i32 %0, i32* %sum, align 4
  %LoadInst2 = load i32, i32* %sum, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([20 x i8], [20 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst2)
  ret i32 0
}
