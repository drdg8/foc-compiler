; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [3 x i8] c"%d\00"
@_Const_String_.1 = private constant [3 x i8] c"%d\00"
@_Const_String_.2 = private constant [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define void @quicksort(i32* %0, i32 %1, i32 %2) {
entry:
  %y = alloca i32, align 4
  %x = alloca i32, align 4
  %j = alloca i32, align 4
  %i = alloca i32, align 4
  %right = alloca i32, align 4
  %left = alloca i32, align 4
  %A = alloca i32*, align 8
  store i32* %0, i32** %A, align 8
  store i32 %1, i32* %left, align 4
  store i32 %2, i32* %right, align 4
  %LoadInst = load i32, i32* %left, align 4
  store i32 %LoadInst, i32* %i, align 4
  %LoadInst1 = load i32, i32* %right, align 4
  store i32 %LoadInst1, i32* %j, align 4
  %LoadInst2 = load i32, i32* %left, align 4
  %LoadInst3 = load i32, i32* %right, align 4
  %3 = add i32 %LoadInst2, %LoadInst3
  %4 = sdiv i32 %3, 2
  %5 = load i32*, i32** %A, align 8
  %tmparray = getelementptr inbounds i32, i32* %5, i32 %4
  %tmpvar = load i32, i32* %tmparray, align 4
  store i32 %tmpvar, i32* %x, align 4
  br label %WhileCond

WhileCond:                                        ; preds = %Merge, %entry
  %LoadInst4 = load i32, i32* %i, align 4
  %LoadInst5 = load i32, i32* %j, align 4
  %icmptmp = icmp sle i32 %LoadInst4, %LoadInst5
  br i1 %icmptmp, label %WhileLoop, label %WhileEnd39

WhileLoop:                                        ; preds = %WhileCond
  br label %WhileCond6

WhileCond6:                                       ; preds = %WhileLoop12, %WhileLoop
  %LoadInst7 = load i32, i32* %i, align 4
  %6 = load i32*, i32** %A, align 8
  %tmparray8 = getelementptr inbounds i32, i32* %6, i32 %LoadInst7
  %tmpvar9 = load i32, i32* %tmparray8, align 4
  %LoadInst10 = load i32, i32* %x, align 4
  %icmptmp11 = icmp slt i32 %tmpvar9, %LoadInst10
  br i1 %icmptmp11, label %WhileLoop12, label %WhileEnd

WhileLoop12:                                      ; preds = %WhileCond6
  %LoadInst13 = load i32, i32* %i, align 4
  %7 = add i32 %LoadInst13, 1
  store i32 %7, i32* %i, align 4
  br label %WhileCond6

WhileEnd:                                         ; preds = %WhileCond6
  br label %WhileCond14

WhileCond14:                                      ; preds = %WhileLoop20, %WhileEnd
  %LoadInst15 = load i32, i32* %x, align 4
  %LoadInst16 = load i32, i32* %j, align 4
  %8 = load i32*, i32** %A, align 8
  %tmparray17 = getelementptr inbounds i32, i32* %8, i32 %LoadInst16
  %tmpvar18 = load i32, i32* %tmparray17, align 4
  %icmptmp19 = icmp slt i32 %LoadInst15, %tmpvar18
  br i1 %icmptmp19, label %WhileLoop20, label %WhileEnd22

WhileLoop20:                                      ; preds = %WhileCond14
  %LoadInst21 = load i32, i32* %j, align 4
  %9 = sub i32 %LoadInst21, 1
  store i32 %9, i32* %j, align 4
  br label %WhileCond14

WhileEnd22:                                       ; preds = %WhileCond14
  %LoadInst23 = load i32, i32* %i, align 4
  %LoadInst24 = load i32, i32* %j, align 4
  %icmptmp25 = icmp sle i32 %LoadInst23, %LoadInst24
  br i1 %icmptmp25, label %Then, label %Else

Then:                                             ; preds = %WhileEnd22
  %LoadInst26 = load i32, i32* %i, align 4
  %10 = load i32*, i32** %A, align 8
  %tmparray27 = getelementptr inbounds i32, i32* %10, i32 %LoadInst26
  %tmpvar28 = load i32, i32* %tmparray27, align 4
  store i32 %tmpvar28, i32* %y, align 4
  %LoadInst29 = load i32, i32* %i, align 4
  %11 = load i32*, i32** %A, align 8
  %tmpvar30 = getelementptr inbounds i32, i32* %11, i32 %LoadInst29
  %LoadInst31 = load i32, i32* %j, align 4
  %12 = load i32*, i32** %A, align 8
  %tmparray32 = getelementptr inbounds i32, i32* %12, i32 %LoadInst31
  %tmpvar33 = load i32, i32* %tmparray32, align 4
  store i32 %tmpvar33, i32* %tmpvar30, align 4
  %LoadInst34 = load i32, i32* %j, align 4
  %13 = load i32*, i32** %A, align 8
  %tmpvar35 = getelementptr inbounds i32, i32* %13, i32 %LoadInst34
  %LoadInst36 = load i32, i32* %y, align 4
  store i32 %LoadInst36, i32* %tmpvar35, align 4
  %LoadInst37 = load i32, i32* %i, align 4
  %14 = add i32 %LoadInst37, 1
  store i32 %14, i32* %i, align 4
  %LoadInst38 = load i32, i32* %j, align 4
  %15 = sub i32 %LoadInst38, 1
  store i32 %15, i32* %j, align 4
  br label %Merge

Else:                                             ; preds = %WhileEnd22
  br label %Merge

Merge:                                            ; preds = %Else, %Then
  br label %WhileCond

WhileEnd39:                                       ; preds = %WhileCond
  %LoadInst40 = load i32, i32* %left, align 4
  %LoadInst41 = load i32, i32* %j, align 4
  %icmptmp42 = icmp slt i32 %LoadInst40, %LoadInst41
  br i1 %icmptmp42, label %Then43, label %Else47

Then43:                                           ; preds = %WhileEnd39
  %LoadInst44 = load i32*, i32** %A, align 8
  %LoadInst45 = load i32, i32* %left, align 4
  %LoadInst46 = load i32, i32* %j, align 4
  call void @quicksort(i32* %LoadInst44, i32 %LoadInst45, i32 %LoadInst46)
  br label %Merge48

Else47:                                           ; preds = %WhileEnd39
  br label %Merge48

Merge48:                                          ; preds = %Else47, %Then43
  %LoadInst49 = load i32, i32* %i, align 4
  %LoadInst50 = load i32, i32* %right, align 4
  %icmptmp51 = icmp slt i32 %LoadInst49, %LoadInst50
  br i1 %icmptmp51, label %Then52, label %Else56

Then52:                                           ; preds = %Merge48
  %LoadInst53 = load i32*, i32** %A, align 8
  %LoadInst54 = load i32, i32* %i, align 4
  %LoadInst55 = load i32, i32* %right, align 4
  call void @quicksort(i32* %LoadInst53, i32 %LoadInst54, i32 %LoadInst55)
  br label %Merge57

Else56:                                           ; preds = %Merge48
  br label %Merge57

Merge57:                                          ; preds = %Else56, %Then52
  ret void
}

define i32 @main() {
entry:
  %right = alloca i32, align 4
  %left = alloca i32, align 4
  %i = alloca i32, align 4
  %N = alloca i32, align 4
  %B = alloca [1000000 x i32], align 4
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_, i32 0, i32 0), i32* %N)
  store i32 0, i32* %i, align 4
  br label %WhileCond

WhileCond:                                        ; preds = %WhileLoop, %entry
  %LoadInst = load i32, i32* %i, align 4
  %LoadInst1 = load i32, i32* %N, align 4
  %icmptmp = icmp slt i32 %LoadInst, %LoadInst1
  br i1 %icmptmp, label %WhileLoop, label %WhileEnd

WhileLoop:                                        ; preds = %WhileCond
  %LoadInst2 = load i32, i32* %i, align 4
  %elePtr = getelementptr inbounds [1000000 x i32], [1000000 x i32]* %B, i32 0, i32 %LoadInst2
  %scanf3 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0), i32* %elePtr)
  %LoadInst4 = load i32, i32* %i, align 4
  %0 = add i32 %LoadInst4, 1
  store i32 %0, i32* %i, align 4
  br label %WhileCond

WhileEnd:                                         ; preds = %WhileCond
  store i32 0, i32* %left, align 4
  %LoadInst5 = load i32, i32* %N, align 4
  %1 = sub i32 %LoadInst5, 1
  store i32 %1, i32* %right, align 4
  store i32 0, i32* %i, align 4
  br label %WhileCond6

WhileCond6:                                       ; preds = %WhileLoop10, %WhileEnd
  %LoadInst7 = load i32, i32* %i, align 4
  %LoadInst8 = load i32, i32* %N, align 4
  %icmptmp9 = icmp slt i32 %LoadInst7, %LoadInst8
  br i1 %icmptmp9, label %WhileLoop10, label %WhileEnd13

WhileLoop10:                                      ; preds = %WhileCond6
  %LoadInst11 = load i32, i32* %i, align 4
  %tmparray = getelementptr inbounds [1000000 x i32], [1000000 x i32]* %B, i32 0, i32 %LoadInst11
  %tmpvar = load i32, i32* %tmparray, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.2, i32 0, i32 0), i32 %tmpvar)
  %LoadInst12 = load i32, i32* %i, align 4
  %2 = add i32 %LoadInst12, 1
  store i32 %2, i32* %i, align 4
  br label %WhileCond6

WhileEnd13:                                       ; preds = %WhileCond6
  ret i32 0
}
