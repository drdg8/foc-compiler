int main() {
    int intArr[5] = {1, 2, 3, 4, 5};
    char charArr[5] = {'a', 'b', 'c', 'd', 'e'};
    double doubleArr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

    printf("Integer array:\n");
    for(int i=0; i<5; i++)
        printf("%d ", intArr[i]);
    printf("\n");

    printf("Character array:\n");
    for(int i=0; i<5; i++)
        printf("%c ", charArr[i]);
    printf("\n");

    printf("Double array:\n");
    for(int i=0; i<5; i++)
        printf("%lf ", doubleArr[i]);
    printf("\n");

    return 0;
}
