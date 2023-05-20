; ModuleID = 'main'
source_filename = "main"

define i32 @main() {
entry:
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  %d = alloca double, align 8
  store double 1.100000e+00, double* %d, align 8
  store i32 1, i32* %a, align 4
  store i32 3, i32* %a, align 4
  store i32 1, i32* %b, align 4
  ret i32 0
}
