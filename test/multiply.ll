; ModuleID = 'main'
source_filename = "main"

@A = global [200000 x i32] zeroinitializer
@B = global [200000 x i32] zeroinitializer
@C = global [200000 x i32] zeroinitializer
@input = global [100000 x i8] zeroinitializer
@_Const_String_ = private constant [7 x i8] c"%d %d\0A\00"
@_Const_String_.1 = private constant [3 x i8] c"%d\00"
@_Const_String_.2 = private constant [6 x i8] c"%d %d\00"
@_Const_String_.3 = private constant [3 x i8] c"%d\00"
@_Const_String_.4 = private constant [25 x i8] c"Incompatible Dimensions\0A\00"
@_Const_String_.5 = private constant [5 x i8] c"%10d\00"
@_Const_String_.6 = private constant [2 x i8] c"\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @main() {
entry:
  %k = alloca i32, align 4
  %j = alloca i32, align 4
  %i = alloca i32, align 4
  %B_N = alloca i32, align 4
  %B_M = alloca i32, align 4
  %A_N = alloca i32, align 4
  %A_M = alloca i32, align 4
  %scanf = call i32 (...) @scanf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @_Const_String_, i32 0, i32 0), i32* %A_M, i32* %A_N)
  store i32 0, i32* %i, align 4
  store i32 0, i32* %j, align 4
  br label %WhileCond

WhileCond:                                        ; preds = %WhileEnd, %entry
  %LoadInst = load i32, i32* %i, align 4
  %LoadInst1 = load i32, i32* %A_M, align 4
  %icmptmp = icmp slt i32 %LoadInst, %LoadInst1
  br i1 %icmptmp, label %WhileLoop, label %WhileEnd13

WhileLoop:                                        ; preds = %WhileCond
  store i32 0, i32* %j, align 4
  br label %WhileCond2

WhileCond2:                                       ; preds = %WhileLoop6, %WhileLoop
  %LoadInst3 = load i32, i32* %j, align 4
  %LoadInst4 = load i32, i32* %A_N, align 4
  %icmptmp5 = icmp slt i32 %LoadInst3, %LoadInst4
  br i1 %icmptmp5, label %WhileLoop6, label %WhileEnd

WhileLoop6:                                       ; preds = %WhileCond2
  %LoadInst7 = load i32, i32* %i, align 4
  %LoadInst8 = load i32, i32* %A_N, align 4
  %0 = mul i32 %LoadInst7, %LoadInst8
  %LoadInst9 = load i32, i32* %j, align 4
  %1 = add i32 %0, %LoadInst9
  %elePtr = getelementptr inbounds [200000 x i32], [200000 x i32]* @A, i32 0, i32 %1
  %scanf10 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.1, i32 0, i32 0), i32* %elePtr)
  %LoadInst11 = load i32, i32* %j, align 4
  %2 = add i32 %LoadInst11, 1
  store i32 %2, i32* %j, align 4
  br label %WhileCond2

WhileEnd:                                         ; preds = %WhileCond2
  %LoadInst12 = load i32, i32* %i, align 4
  %3 = add i32 %LoadInst12, 1
  store i32 %3, i32* %i, align 4
  br label %WhileCond

WhileEnd13:                                       ; preds = %WhileCond
  %scanf14 = call i32 (...) @scanf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @_Const_String_.2, i32 0, i32 0), i32* %B_M, i32* %B_N)
  store i32 0, i32* %i, align 4
  store i32 0, i32* %j, align 4
  br label %WhileCond15

WhileCond15:                                      ; preds = %WhileEnd31, %WhileEnd13
  %LoadInst16 = load i32, i32* %i, align 4
  %LoadInst17 = load i32, i32* %B_M, align 4
  %icmptmp18 = icmp slt i32 %LoadInst16, %LoadInst17
  br i1 %icmptmp18, label %WhileLoop19, label %WhileEnd33

WhileLoop19:                                      ; preds = %WhileCond15
  store i32 0, i32* %j, align 4
  br label %WhileCond20

WhileCond20:                                      ; preds = %WhileLoop24, %WhileLoop19
  %LoadInst21 = load i32, i32* %j, align 4
  %LoadInst22 = load i32, i32* %B_N, align 4
  %icmptmp23 = icmp slt i32 %LoadInst21, %LoadInst22
  br i1 %icmptmp23, label %WhileLoop24, label %WhileEnd31

WhileLoop24:                                      ; preds = %WhileCond20
  %LoadInst25 = load i32, i32* %i, align 4
  %LoadInst26 = load i32, i32* %B_N, align 4
  %4 = mul i32 %LoadInst25, %LoadInst26
  %LoadInst27 = load i32, i32* %j, align 4
  %5 = add i32 %4, %LoadInst27
  %elePtr28 = getelementptr inbounds [200000 x i32], [200000 x i32]* @B, i32 0, i32 %5
  %scanf29 = call i32 (...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @_Const_String_.3, i32 0, i32 0), i32* %elePtr28)
  %LoadInst30 = load i32, i32* %j, align 4
  %6 = add i32 %LoadInst30, 1
  store i32 %6, i32* %j, align 4
  br label %WhileCond20

WhileEnd31:                                       ; preds = %WhileCond20
  %LoadInst32 = load i32, i32* %i, align 4
  %7 = add i32 %LoadInst32, 1
  store i32 %7, i32* %i, align 4
  br label %WhileCond15

WhileEnd33:                                       ; preds = %WhileCond15
  %LoadInst34 = load i32, i32* %A_N, align 4
  %LoadInst35 = load i32, i32* %B_M, align 4
  %icmptmp36 = icmp ne i32 %LoadInst34, %LoadInst35
  br i1 %icmptmp36, label %Then, label %Else

Then:                                             ; preds = %WhileEnd33
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @_Const_String_.4, i32 0, i32 0))
  ret i32 0

Else:                                             ; preds = %WhileEnd33
  br label %Merge

Merge:                                            ; preds = %Else
  store i32 0, i32* %i, align 4
  store i32 0, i32* %j, align 4
  br label %WhileCond37

WhileCond37:                                      ; preds = %WhileEnd76, %Merge
  %LoadInst38 = load i32, i32* %i, align 4
  %LoadInst39 = load i32, i32* %A_M, align 4
  %icmptmp40 = icmp slt i32 %LoadInst38, %LoadInst39
  br i1 %icmptmp40, label %WhileLoop41, label %WhileEnd78

WhileLoop41:                                      ; preds = %WhileCond37
  store i32 0, i32* %j, align 4
  br label %WhileCond42

WhileCond42:                                      ; preds = %WhileEnd74, %WhileLoop41
  %LoadInst43 = load i32, i32* %j, align 4
  %LoadInst44 = load i32, i32* %B_N, align 4
  %icmptmp45 = icmp slt i32 %LoadInst43, %LoadInst44
  br i1 %icmptmp45, label %WhileLoop46, label %WhileEnd76

WhileLoop46:                                      ; preds = %WhileCond42
  %LoadInst47 = load i32, i32* %i, align 4
  %LoadInst48 = load i32, i32* %B_N, align 4
  %8 = mul i32 %LoadInst47, %LoadInst48
  %LoadInst49 = load i32, i32* %j, align 4
  %9 = add i32 %8, %LoadInst49
  %tmpvar = getelementptr inbounds [200000 x i32], [200000 x i32]* @C, i32 0, i32 %9
  store i32 0, i32* %tmpvar, align 4
  store i32 0, i32* %k, align 4
  br label %WhileCond50

WhileCond50:                                      ; preds = %WhileLoop54, %WhileLoop46
  %LoadInst51 = load i32, i32* %k, align 4
  %LoadInst52 = load i32, i32* %A_N, align 4
  %icmptmp53 = icmp slt i32 %LoadInst51, %LoadInst52
  br i1 %icmptmp53, label %WhileLoop54, label %WhileEnd74

WhileLoop54:                                      ; preds = %WhileCond50
  %LoadInst55 = load i32, i32* %i, align 4
  %LoadInst56 = load i32, i32* %B_N, align 4
  %10 = mul i32 %LoadInst55, %LoadInst56
  %LoadInst57 = load i32, i32* %j, align 4
  %11 = add i32 %10, %LoadInst57
  %tmpvar58 = getelementptr inbounds [200000 x i32], [200000 x i32]* @C, i32 0, i32 %11
  %LoadInst59 = load i32, i32* %i, align 4
  %LoadInst60 = load i32, i32* %B_N, align 4
  %12 = mul i32 %LoadInst59, %LoadInst60
  %LoadInst61 = load i32, i32* %j, align 4
  %13 = add i32 %12, %LoadInst61
  %tmparray = getelementptr inbounds [200000 x i32], [200000 x i32]* @C, i32 0, i32 %13
  %tmpvar62 = load i32, i32* %tmparray, align 4
  %LoadInst63 = load i32, i32* %i, align 4
  %LoadInst64 = load i32, i32* %A_N, align 4
  %14 = mul i32 %LoadInst63, %LoadInst64
  %LoadInst65 = load i32, i32* %k, align 4
  %15 = add i32 %14, %LoadInst65
  %tmparray66 = getelementptr inbounds [200000 x i32], [200000 x i32]* @A, i32 0, i32 %15
  %tmpvar67 = load i32, i32* %tmparray66, align 4
  %LoadInst68 = load i32, i32* %k, align 4
  %LoadInst69 = load i32, i32* %B_N, align 4
  %16 = mul i32 %LoadInst68, %LoadInst69
  %LoadInst70 = load i32, i32* %j, align 4
  %17 = add i32 %16, %LoadInst70
  %tmparray71 = getelementptr inbounds [200000 x i32], [200000 x i32]* @B, i32 0, i32 %17
  %tmpvar72 = load i32, i32* %tmparray71, align 4
  %18 = mul i32 %tmpvar67, %tmpvar72
  %19 = add i32 %tmpvar62, %18
  store i32 %19, i32* %tmpvar58, align 4
  %LoadInst73 = load i32, i32* %k, align 4
  %20 = add i32 %LoadInst73, 1
  store i32 %20, i32* %k, align 4
  br label %WhileCond50

WhileEnd74:                                       ; preds = %WhileCond50
  %LoadInst75 = load i32, i32* %j, align 4
  %21 = add i32 %LoadInst75, 1
  store i32 %21, i32* %j, align 4
  br label %WhileCond42

WhileEnd76:                                       ; preds = %WhileCond42
  %LoadInst77 = load i32, i32* %i, align 4
  %22 = add i32 %LoadInst77, 1
  store i32 %22, i32* %i, align 4
  br label %WhileCond37

WhileEnd78:                                       ; preds = %WhileCond37
  store i32 0, i32* %i, align 4
  br label %WhileCond79

WhileCond79:                                      ; preds = %WhileEnd96, %WhileEnd78
  %LoadInst80 = load i32, i32* %i, align 4
  %LoadInst81 = load i32, i32* %A_M, align 4
  %icmptmp82 = icmp slt i32 %LoadInst80, %LoadInst81
  br i1 %icmptmp82, label %WhileLoop83, label %WhileEnd99

WhileLoop83:                                      ; preds = %WhileCond79
  store i32 0, i32* %j, align 4
  br label %WhileCond84

WhileCond84:                                      ; preds = %WhileLoop88, %WhileLoop83
  %LoadInst85 = load i32, i32* %j, align 4
  %LoadInst86 = load i32, i32* %B_N, align 4
  %icmptmp87 = icmp slt i32 %LoadInst85, %LoadInst86
  br i1 %icmptmp87, label %WhileLoop88, label %WhileEnd96

WhileLoop88:                                      ; preds = %WhileCond84
  %LoadInst89 = load i32, i32* %i, align 4
  %LoadInst90 = load i32, i32* %B_N, align 4
  %23 = mul i32 %LoadInst89, %LoadInst90
  %LoadInst91 = load i32, i32* %j, align 4
  %24 = add i32 %23, %LoadInst91
  %tmparray92 = getelementptr inbounds [200000 x i32], [200000 x i32]* @C, i32 0, i32 %24
  %tmpvar93 = load i32, i32* %tmparray92, align 4
  %printf94 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @_Const_String_.5, i32 0, i32 0), i32 %tmpvar93)
  %LoadInst95 = load i32, i32* %j, align 4
  %25 = add i32 %LoadInst95, 1
  store i32 %25, i32* %j, align 4
  br label %WhileCond84

WhileEnd96:                                       ; preds = %WhileCond84
  %printf97 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @_Const_String_.6, i32 0, i32 0))
  %LoadInst98 = load i32, i32* %i, align 4
  %26 = add i32 %LoadInst98, 1
  store i32 %26, i32* %i, align 4
  br label %WhileCond79

WhileEnd99:                                       ; preds = %WhileCond79
  ret i32 0
}
