; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [21 x i8] c"a is greater than b\0A\00"
@_Const_String_.1 = private constant [21 x i8] c"b is greater than a\0A\00"
@_Const_String_.2 = private constant [9 x i8] c"a is 10\0A\00"
@_Const_String_.3 = private constant [8 x i8] c"a is 5\0A\00"

declare i32 @printf(i8*, ...)

declare i32 @scanf(...)

define i32 @main() {
entry:
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 10, i32* %a, align 4
  store i32 5, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %LoadInst1 = load i32, i32* %b, align 4
  %icmptmp = icmp sgt i32 %LoadInst, %LoadInst1
  br i1 %icmptmp, label %Then, label %Else

Then:                                             ; preds = %entry
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_, i32 0, i32 0))
  br label %Merge4

Else:                                             ; preds = %entry
  %printf2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @_Const_String_.1, i32 0, i32 0))
  br label %Merge4

Merge4:                                           ; preds = %Else, %Then
  %LoadInst3 = load i32, i32* %a, align 4
  %icmptmp5 = icmp eq i32 %LoadInst3, 10
  br i1 %icmptmp5, label %Case0, label %Comparison1

Case0:                                            ; preds = %Merge4
  %printf6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @_Const_String_.2, i32 0, i32 0))
  br label %SwitchEnd

Comparison1:                                      ; preds = %Merge4
  %icmptmp7 = icmp eq i32 %LoadInst3, 5
  br i1 %icmptmp7, label %Case1, label %SwitchEnd

Case1:                                            ; preds = %Comparison1
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([8 x i8], [8 x i8]* @_Const_String_.3, i32 0, i32 0))
  br label %SwitchEnd

SwitchEnd:                                        ; preds = %Case1, %Comparison1, %Case0
  ret i32 0
}
