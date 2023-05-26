; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [24 x i8] c"For loop iteration: %d\0A\00"
@_Const_String_.1 = private constant [26 x i8] c"While loop iteration: %d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @main() {
entry:
  %count = alloca i32, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  br label %ForCond

ForCond:                                          ; preds = %ForTail, %entry
  %LoadInst = load i32, i32* %i, align 4
  %icmptmp = icmp slt i32 %LoadInst, 5
  br i1 %icmptmp, label %ForLoop, label %ForEnd

ForLoop:                                          ; preds = %ForCond
  %LoadInst1 = load i32, i32* %i, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst1)
  br label %ForTail

ForTail:                                          ; preds = %ForLoop
  %LoadInst2 = load i32, i32* %i, align 4
  %0 = add i32 %LoadInst2, 1
  store i32 %0, i32* %i, align 4
  br label %ForCond

ForEnd:                                           ; preds = %ForCond
  store i32 0, i32* %count, align 4
  br label %WhileCond

WhileCond:                                        ; preds = %WhileLoop, %ForEnd
  %LoadInst3 = load i32, i32* %count, align 4
  %icmptmp4 = icmp slt i32 %LoadInst3, 5
  br i1 %icmptmp4, label %WhileLoop, label %WhileEnd

WhileLoop:                                        ; preds = %WhileCond
  %LoadInst5 = load i32, i32* %count, align 4
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %LoadInst5)
  %LoadInst7 = load i32, i32* %count, align 4
  %1 = add i32 %LoadInst7, 1
  store i32 %1, i32* %count, align 4
  br label %WhileCond

WhileEnd:                                         ; preds = %WhileCond
  ret i32 0
}
