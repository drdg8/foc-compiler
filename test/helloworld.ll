; ModuleID = 'main'
source_filename = "main"

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
  %1 = add i32 %LoadInst2, 1
  store i32 %1, i32* %e, align 4
  %LoadInst3 = load i32, i32* %e, align 4
  %icmptmp4 = icmp eq i32 %LoadInst3, 6
  br i1 %icmptmp4, label %Then, label %Else

Then:                                             ; preds = %WhileLoop
  br label %WhileEnd

Else:                                             ; preds = %WhileLoop
  br label %Merge

Merge:                                            ; preds = %Else
  %LoadInst5 = load i32, i32* %b, align 4
  %2 = add i32 %LoadInst5, 1
  store i32 %2, i32* %b, align 4
  br label %WhileCond

WhileEnd:                                         ; preds = %Then, %WhileCond
  store i32 0, i32* %i, align 4
  br label %ForCond

ForCond:                                          ; preds = %ForTail, %WhileEnd
  %LoadInst6 = load i32, i32* %i, align 4
  %icmptmp7 = icmp slt i32 %LoadInst6, 2
  br i1 %icmptmp7, label %ForLoop, label %ForEnd

ForLoop:                                          ; preds = %ForCond
  %LoadInst8 = load i32, i32* %e, align 4
  %LoadInst9 = load i32, i32* %i, align 4
  %3 = add i32 %LoadInst8, %LoadInst9
  store i32 %3, i32* %e, align 4
  br label %ForTail

ForTail:                                          ; preds = %ForLoop
  %LoadInst10 = load i32, i32* %i, align 4
  %4 = add i32 %LoadInst10, 1
  store i32 %4, i32* %i, align 4
  br label %ForCond

ForEnd:                                           ; preds = %ForCond
  %LoadInst11 = load i32, i32* %b, align 4
  %printf12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %LoadInst11)
  %LoadInst13 = load i32, i32* %e, align 4
  %printf14 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.2, i32 0, i32 0), i32 %LoadInst13)
  ret i32 0
}
