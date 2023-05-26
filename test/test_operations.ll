; ModuleID = 'main'
source_filename = "main"

@_Const_String_ = private constant [24 x i8] c"Addition: %d + %d = %d\0A\00"
@_Const_String_.1 = private constant [27 x i8] c"Subtraction: %d - %d = %d\0A\00"
@_Const_String_.2 = private constant [30 x i8] c"Multiplication: %d * %d = %d\0A\00"
@_Const_String_.3 = private constant [24 x i8] c"Division: %d / %d = %d\0A\00"
@_Const_String_.4 = private constant [40 x i8] c"Logical AND: (a == b) && (a != b) = %d\0A\00"
@_Const_String_.5 = private constant [39 x i8] c"Logical OR: (a == b) || (a != b) = %d\0A\00"
@_Const_String_.6 = private constant [22 x i8] c"Equals: a == b -> %d\0A\00"
@_Const_String_.7 = private constant [26 x i8] c"Not Equals: a != b -> %d\0A\00"
@_Const_String_.8 = private constant [24 x i8] c"Less Than: a < b -> %d\0A\00"
@_Const_String_.9 = private constant [27 x i8] c"Greater Than: a > b -> %d\0A\00"
@_Const_String_.10 = private constant [35 x i8] c"Less Than or Equals: a <= b -> %d\0A\00"
@_Const_String_.11 = private constant [38 x i8] c"Greater Than or Equals: a >= b -> %d\0A\00"

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
  %LoadInst2 = load i32, i32* %a, align 4
  %LoadInst3 = load i32, i32* %b, align 4
  %0 = add i32 %LoadInst2, %LoadInst3
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_, i32 0, i32 0), i32 %LoadInst, i32 %LoadInst1, i32 %0)
  %LoadInst4 = load i32, i32* %a, align 4
  %LoadInst5 = load i32, i32* %b, align 4
  %LoadInst6 = load i32, i32* %a, align 4
  %LoadInst7 = load i32, i32* %b, align 4
  %1 = sub i32 %LoadInst6, %LoadInst7
  %printf8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @_Const_String_.1, i32 0, i32 0), i32 %LoadInst4, i32 %LoadInst5, i32 %1)
  %LoadInst9 = load i32, i32* %a, align 4
  %LoadInst10 = load i32, i32* %b, align 4
  %LoadInst11 = load i32, i32* %a, align 4
  %LoadInst12 = load i32, i32* %b, align 4
  %2 = mul i32 %LoadInst11, %LoadInst12
  %printf13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([30 x i8], [30 x i8]* @_Const_String_.2, i32 0, i32 0), i32 %LoadInst9, i32 %LoadInst10, i32 %2)
  %LoadInst14 = load i32, i32* %a, align 4
  %LoadInst15 = load i32, i32* %b, align 4
  %LoadInst16 = load i32, i32* %a, align 4
  %LoadInst17 = load i32, i32* %b, align 4
  %3 = sdiv i32 %LoadInst16, %LoadInst17
  %printf18 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_.3, i32 0, i32 0), i32 %LoadInst14, i32 %LoadInst15, i32 %3)
  %LoadInst19 = load i32, i32* %a, align 4
  %LoadInst20 = load i32, i32* %b, align 4
  %icmptmp = icmp eq i32 %LoadInst19, %LoadInst20
  %LoadInst21 = load i32, i32* %a, align 4
  %LoadInst22 = load i32, i32* %b, align 4
  %icmptmp23 = icmp ne i32 %LoadInst21, %LoadInst22
  %tmpAnd = and i1 %icmptmp, %icmptmp23
  %printf24 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([40 x i8], [40 x i8]* @_Const_String_.4, i32 0, i32 0), i1 %tmpAnd)
  %LoadInst25 = load i32, i32* %a, align 4
  %LoadInst26 = load i32, i32* %b, align 4
  %icmptmp27 = icmp eq i32 %LoadInst25, %LoadInst26
  %LoadInst28 = load i32, i32* %a, align 4
  %LoadInst29 = load i32, i32* %b, align 4
  %icmptmp30 = icmp ne i32 %LoadInst28, %LoadInst29
  %tmpOR = or i1 %icmptmp27, %icmptmp30
  %printf31 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([39 x i8], [39 x i8]* @_Const_String_.5, i32 0, i32 0), i1 %tmpOR)
  %LoadInst32 = load i32, i32* %a, align 4
  %LoadInst33 = load i32, i32* %b, align 4
  %icmptmp34 = icmp eq i32 %LoadInst32, %LoadInst33
  %printf35 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([22 x i8], [22 x i8]* @_Const_String_.6, i32 0, i32 0), i1 %icmptmp34)
  %LoadInst36 = load i32, i32* %a, align 4
  %LoadInst37 = load i32, i32* %b, align 4
  %icmptmp38 = icmp ne i32 %LoadInst36, %LoadInst37
  %printf39 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @_Const_String_.7, i32 0, i32 0), i1 %icmptmp38)
  %LoadInst40 = load i32, i32* %a, align 4
  %LoadInst41 = load i32, i32* %b, align 4
  %icmptmp42 = icmp slt i32 %LoadInst40, %LoadInst41
  %printf43 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @_Const_String_.8, i32 0, i32 0), i1 %icmptmp42)
  %LoadInst44 = load i32, i32* %a, align 4
  %LoadInst45 = load i32, i32* %b, align 4
  %icmptmp46 = icmp sgt i32 %LoadInst44, %LoadInst45
  %printf47 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([27 x i8], [27 x i8]* @_Const_String_.9, i32 0, i32 0), i1 %icmptmp46)
  %LoadInst48 = load i32, i32* %a, align 4
  %LoadInst49 = load i32, i32* %b, align 4
  %icmptmp50 = icmp sle i32 %LoadInst48, %LoadInst49
  %printf51 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([35 x i8], [35 x i8]* @_Const_String_.10, i32 0, i32 0), i1 %icmptmp50)
  %LoadInst52 = load i32, i32* %a, align 4
  %LoadInst53 = load i32, i32* %b, align 4
  %icmptmp54 = icmp sge i32 %LoadInst52, %LoadInst53
  %printf55 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([38 x i8], [38 x i8]* @_Const_String_.11, i32 0, i32 0), i1 %icmptmp54)
  ret i32 0
}
