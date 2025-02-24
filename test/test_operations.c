int main() {
    int a = 10;
    int b = 5;

    // Arithmetic Operations
    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %d\n", a, b, a / b);


    // // Logical Operations
    printf("Logical AND: (a == b) && (a != b) = %d\n", (a == b) && (a != b));
    printf("Logical OR: (a == b) || (a != b) = %d\n", (a == b) || (a != b));

    // // Comparison Operations
    printf("Equals: a == b -> %d\n", a == b);
    printf("Not Equals: a != b -> %d\n", a != b);
    printf("Less Than: a < b -> %d\n", a < b);
    printf("Greater Than: a > b -> %d\n", a > b);
    printf("Less Than or Equals: a <= b -> %d\n", a <= b);
    printf("Greater Than or Equals: a >= b -> %d\n", a >= b);

    return 0;
}
