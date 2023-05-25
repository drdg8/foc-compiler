; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [16 x i8] c"The sum is: %d\0A\00"

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

define i32 @compute_sum(i32 %0) {
entry:
  %i = alloca i32, align 4
  %sum = alloca i32, align 4
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  store i32 0, i32* %sum, align 4
  store i32 0, i32* %i, align 4
  br label %ForCond

ForCond:                                          ; preds = %ForTail, %entry
  %LoadInst = load i32, i32* %i, align 4
  %LoadInst1 = load i32, i32* %n, align 4
  %icmptmp = icmp slt i32 %LoadInst, %LoadInst1
  br i1 %icmptmp, label %ForLoop, label %ForEnd

ForLoop:                                          ; preds = %ForCond
  %LoadInst2 = load i32, i32* %sum, align 4
  %LoadInst3 = load i32, i32* %i, align 4
  %1 = call i32 @add(i32 %LoadInst2, i32 %LoadInst3)
  store i32 %1, i32* %sum, align 4
  br label %ForTail

ForTail:                                          ; preds = %ForLoop
  %LoadInst4 = load i32, i32* %i, align 4
  %2 = add i32 %LoadInst4, 1
  store i32 %2, i32* %i, align 4
  br label %ForCond

ForEnd:                                           ; preds = %ForCond
  %LoadInst5 = load i32, i32* %sum, align 4
  ret i32 %LoadInst5
}

define i32 @main() {
entry:
  %n = alloca i32, align 4
  store i32 100, i32* %n, align 4
  %LoadInst = load i32, i32* %n, align 4
  %0 = call i32 @compute_sum(i32 %LoadInst)
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @_Const_String_, i32 0, i32 0), i32 %0)
  ret i32 0
}
