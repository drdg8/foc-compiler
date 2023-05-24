; ModuleID = 'main'
source_filename = "main"

@f = global [100 x i32] zeroinitializer
@h = global i32 0
@_Const_String_ = private constant [4 x i8] c"%d\0A\00"
@_Const_String_.1 = private constant [4 x i8] c"%d\0A\00"
@_Const_String_.2 = private constant [4 x i8] c"%d\0A\00"

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
  %g = alloca [100 x i32], align 4
  %i = alloca i32, align 4
  %e = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  %d = alloca double, align 8
  store double 1.100000e+00, double* %d, align 8
  store i32 1, i32* %a, align 4
  %0 = call i32 @add(i32 3, i32 4)
  store i32 %0, i32* %a, align 4
  %LoadInst = load i32, i32* %a, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst)
  store i32 1, i32* %b, align 4
  store i32 5, i32* %e, align 4
  br label %WhileCond

WhileCond:                                        ; preds = %Merge, %entry
  %LoadInst1 = load i32, i32* %e, align 4
  %icmptmp = icmp slt i32 %LoadInst1, 6
  br i1 %icmptmp, label %WhileLoop, label %WhileEnd

WhileLoop:                                        ; preds = %WhileCond
  %LoadInst2 = load i32, i32* %e, align 4
  %icmptmp3 = icmp eq i32 %LoadInst2, 5
  br i1 %icmptmp3, label %Then, label %Else

Then:                                             ; preds = %WhileLoop
  br label %WhileEnd

Else:                                             ; preds = %WhileLoop
  br label %Merge

Merge:                                            ; preds = %Else
  %LoadInst4 = load i32, i32* %e, align 4
  %1 = add i32 %LoadInst4, 1
  store i32 %1, i32* %e, align 4
  br label %WhileCond

WhileEnd:                                         ; preds = %Then, %WhileCond
  %LoadInst5 = load i32, i32* %b, align 4
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %LoadInst5)
  %LoadInst7 = load i32, i32* %e, align 4
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.2, i32 0, i32 0), i32 %LoadInst7)
  %tmpvar = load i32, i32* getelementptr inbounds ([100 x i32], [100 x i32]* @f, i32 0, i32 4), align 4
  store i32 %tmpvar, i32* @h, align 4
  %LoadInst9 = load i32, i32* %e, align 4
  store i32 %LoadInst9, i32* getelementptr inbounds ([100 x i32], [100 x i32]* @f, i32 0, i32 2), align 4
  ret i32 0
}
