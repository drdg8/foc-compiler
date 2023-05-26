; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [16 x i8] c"Integer array:\0A\00"
@_Const_String_.1 = private constant [4 x i8] c"%d \00"
@_Const_String_.2 = private constant [2 x i8] c"\0A\00"
@_Const_String_.3 = private constant [18 x i8] c"Character array:\0A\00"
@_Const_String_.4 = private constant [4 x i8] c"%c \00"
@_Const_String_.5 = private constant [2 x i8] c"\0A\00"
@_Const_String_.6 = private constant [15 x i8] c"Double array:\0A\00"
@_Const_String_.7 = private constant [5 x i8] c"%lf \00"
@_Const_String_.8 = private constant [2 x i8] c"\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @main() {
entry:
  %doubleArr = alloca [5 x double], align 8
  %charArr = alloca [5 x i8], align 1
  %intArr = alloca [5 x i32], align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  br label %ForCond

ForCond:                                          ; preds = %ForTail, %entry
  %LoadInst = load i32, i32* %i, align 4
  %icmptmp = icmp slt i32 %LoadInst, 5
  br i1 %icmptmp, label %ForLoop, label %ForEnd

ForLoop:                                          ; preds = %ForCond
  %LoadInst1 = load i32, i32* %i, align 4
  %tmpvar = getelementptr inbounds [5 x i32], [5 x i32]* %intArr, i32 0, i32 %LoadInst1
  %LoadInst2 = load i32, i32* %i, align 4
  %0 = add i32 %LoadInst2, 1
  store i32 %0, i32* %tmpvar, align 4
  br label %ForTail

ForTail:                                          ; preds = %ForLoop
  %LoadInst3 = load i32, i32* %i, align 4
  %1 = add i32 %LoadInst3, 1
  store i32 %1, i32* %i, align 4
  br label %ForCond

ForEnd:                                           ; preds = %ForCond
  %tmpvar4 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 0
  store i8 97, i8* %tmpvar4, align 1
  %tmpvar5 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 1
  store i8 98, i8* %tmpvar5, align 1
  %tmpvar6 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 2
  store i8 99, i8* %tmpvar6, align 1
  %tmpvar7 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 3
  store i8 100, i8* %tmpvar7, align 1
  %tmpvar8 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 4
  store i8 101, i8* %tmpvar8, align 1
  %tmpvar9 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 0
  store double 1.100000e+00, double* %tmpvar9, align 8
  %tmpvar10 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 1
  store double 2.200000e+00, double* %tmpvar10, align 8
  %tmpvar11 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 2
  store double 3.300000e+00, double* %tmpvar11, align 8
  %tmpvar12 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 3
  store double 4.400000e+00, double* %tmpvar12, align 8
  %tmpvar13 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 4
  store double 5.500000e+00, double* %tmpvar13, align 8
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @_Const_String_, i32 0, i32 0))
  store i32 0, i32* %i, align 4
  br label %ForCond14

ForCond14:                                        ; preds = %ForTail21, %ForEnd
  %LoadInst15 = load i32, i32* %i, align 4
  %icmptmp16 = icmp slt i32 %LoadInst15, 5
  br i1 %icmptmp16, label %ForLoop17, label %ForEnd23

ForLoop17:                                        ; preds = %ForCond14
  %LoadInst18 = load i32, i32* %i, align 4
  %tmparray = getelementptr inbounds [5 x i32], [5 x i32]* %intArr, i32 0, i32 %LoadInst18
  %tmpvar19 = load i32, i32* %tmparray, align 4
  %printf20 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %tmpvar19)
  br label %ForTail21

ForTail21:                                        ; preds = %ForLoop17
  %LoadInst22 = load i32, i32* %i, align 4
  %2 = add i32 %LoadInst22, 1
  store i32 %2, i32* %i, align 4
  br label %ForCond14

ForEnd23:                                         ; preds = %ForCond14
  %printf24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @_Const_String_.2, i32 0, i32 0))
  %printf25 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @_Const_String_.3, i32 0, i32 0))
  store i32 0, i32* %i, align 4
  br label %ForCond26

ForCond26:                                        ; preds = %ForTail34, %ForEnd23
  %LoadInst27 = load i32, i32* %i, align 4
  %icmptmp28 = icmp slt i32 %LoadInst27, 5
  br i1 %icmptmp28, label %ForLoop29, label %ForEnd36

ForLoop29:                                        ; preds = %ForCond26
  %LoadInst30 = load i32, i32* %i, align 4
  %tmparray31 = getelementptr inbounds [5 x i8], [5 x i8]* %charArr, i32 0, i32 %LoadInst30
  %tmpvar32 = load i8, i8* %tmparray31, align 1
  %printf33 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @_Const_String_.4, i32 0, i32 0), i8 %tmpvar32)
  br label %ForTail34

ForTail34:                                        ; preds = %ForLoop29
  %LoadInst35 = load i32, i32* %i, align 4
  %3 = add i32 %LoadInst35, 1
  store i32 %3, i32* %i, align 4
  br label %ForCond26

ForEnd36:                                         ; preds = %ForCond26
  %printf37 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @_Const_String_.5, i32 0, i32 0))
  %printf38 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @_Const_String_.6, i32 0, i32 0))
  store i32 0, i32* %i, align 4
  br label %ForCond39

ForCond39:                                        ; preds = %ForTail47, %ForEnd36
  %LoadInst40 = load i32, i32* %i, align 4
  %icmptmp41 = icmp slt i32 %LoadInst40, 5
  br i1 %icmptmp41, label %ForLoop42, label %ForEnd49

ForLoop42:                                        ; preds = %ForCond39
  %LoadInst43 = load i32, i32* %i, align 4
  %tmparray44 = getelementptr inbounds [5 x double], [5 x double]* %doubleArr, i32 0, i32 %LoadInst43
  %tmpvar45 = load double, double* %tmparray44, align 8
  %printf46 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.7, i32 0, i32 0), double %tmpvar45)
  br label %ForTail47

ForTail47:                                        ; preds = %ForLoop42
  %LoadInst48 = load i32, i32* %i, align 4
  %4 = add i32 %LoadInst48, 1
  store i32 %4, i32* %i, align 4
  br label %ForCond39

ForEnd49:                                         ; preds = %ForCond39
  %printf50 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @_Const_String_.8, i32 0, i32 0))
  ret i32 0
}
