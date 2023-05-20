; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [3 x i8] c"%d\00"
@_Const_String_.1 = private constant [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @add(i32 %0, i32 %1) {
entry:
  %res = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 %0, i32* %a, align 4
  store i32 %1, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %LoadInst1 = load i32, i32* %b, align 4
  %2 = add i32 %LoadInst, %LoadInst1
  store i32 %2, i32* %res, align 4
  %LoadInst2 = load i32, i32* %res, align 4
  ret i32 %LoadInst2
}

define i32 @main() {
entry:
  %e = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  %d = alloca double, align 8
  store double 1.100000e+00, double* %d, align 8
  store i32 1, i32* %a, align 4
  %0 = call i32 @add(i32 3, i32 4)
  store i32 %0, i32* %a, align 4
  store i32 1, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %icmptmp = icmp eq i32 %LoadInst, 3
  br i1 %icmptmp, label %Then, label %Else

Then:                                             ; preds = %entry
  %LoadInst1 = load i32, i32* %b, align 4
  %1 = add i32 %LoadInst1, 1
  store i32 %1, i32* %b, align 4
  br label %Merge

Else:                                             ; preds = %entry
  %LoadInst2 = load i32, i32* %b, align 4
  %2 = sub i32 %LoadInst2, 1
  store i32 %2, i32* %b, align 4
  br label %Merge

Merge:                                            ; preds = %Else, %Then
  store i32 0, i32* %e, align 4
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0), i32* %e)
  %LoadInst3 = load i32, i32* %e, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %LoadInst3)
  ret i32 0
}
