; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [13 x i8] c"Integer: %d\0A\00"
@_Const_String_.1 = private constant [10 x i8] c"Char: %c\0A\00"
@_Const_String_.2 = private constant [13 x i8] c"Double: %lf\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @main() {
entry:
  %d = alloca double, align 8
  %c = alloca i8, align 1
  %i = alloca i32, align 4
  store i32 10, i32* %i, align 4
  store i8 97, i8* %c, align 1
  store double 3.140000e+00, double* %d, align 8
  %LoadInst = load i32, i32* %i, align 4
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst)
  %LoadInst1 = load i8, i8* %c, align 1
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @_Const_String_.1, i32 0, i32 0), i8 %LoadInst1)
  %LoadInst3 = load double, double* %d, align 8
  %printf4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @_Const_String_.2, i32 0, i32 0), double %LoadInst3)
  ret i32 0
}
