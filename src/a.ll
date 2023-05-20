; ModuleID = 'main'
source_filename = "main"

@c = global i32 3

define i32 @main() {
entry:
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 1, i32* %a, align 4
  store i32 3, i32* %a, align 4
  store i32 1, i32* %b, align 4
  %LoadInst = load i32, i32* %a, align 4
  %LoadInst1 = load i32, i32* %b, align 4
  %0 = add i32 %LoadInst, %LoadInst1
  store i32 %0, i32* @c, align 4
  %LoadInst2 = load i32, i32* %a, align 4
  %LoadInst3 = load i32, i32* %b, align 4
  %1 = mul i32 %LoadInst2, %LoadInst3
  store i32 %1, i32* @c, align 4
  %LoadInst4 = load i32, i32* %a, align 4
  %LoadInst5 = load i32, i32* %b, align 4
  %2 = sub i32 %LoadInst4, %LoadInst5
  store i32 %2, i32* @c, align 4
  ret i32 0
}
