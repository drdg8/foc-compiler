; ModuleID = 'main'
source_filename = "main"

@c = global i32 5

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
