int main() {
    int i;
    int intArr[5];
    char charArr[5];
    double doubleArr[5];
    for(i = 0; i < 5; i=i+1) {
        intArr[i] = i + 1; 
    }
    charArr[0] = 'a';
    charArr[1] = 'b';
    charArr[2] = 'c';
    charArr[3] = 'd';
    charArr[4] = 'e';
    
    doubleArr[0] = 1.1; 
    doubleArr[1] = 2.2; 
    doubleArr[2] = 3.3; 
    doubleArr[3] = 4.4; 
    doubleArr[4] = 5.5; 

    printf("Integer array:\n");
    for(i=0; i<5;  i=i+1){
        printf("%d ", intArr[i]);
    }
    printf("\n");

    printf("Character array:\n");
    for( i=0; i<5;  i=i+1){
        printf("%c ", charArr[i]);
    }
    printf("\n");

    printf("Double array:\n");
    for( i=0; i<5;  i=i+1){
        printf("%lf ", doubleArr[i]);
    }
    printf("\n");

    return 0;
}
