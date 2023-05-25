void quicksort(int A[10], int left, int right) {
    int i;
    int j;
    int x;
    int y;
    i = left;
    j = right;
    x = A[(left + right) / 2];
    while(i <= j) {
        while (A[i] < x) { 
            i = i + 1;
        }
        while (x < A[j]) {
            j = j - 1;
        }
        if (i <= j) {
            y = A[i];
            A[i] = A[j];
            A[j] = y;
            i = i + 1;
            j = j - 1;
        }
    }
    if (left < j) {
        quicksort(A, left, j);
    }
    if (i < right) {
        quicksort(A, i, right);
    } 
    return;
}

int main()
{
// int B[1000000];
// int N;
// scanf("%d", &N);
// int i = 0;
// while(i < N) {
// scanf("%d", &B[i]);
// i = i + 1;
// }
// int left = 0;
// int right = N - 1;
// quicksort(B, left, right);
// i = 0;
// while(i < N) {
// printf("%d\n", B[i]);
// i = i + 1;
// }
int i=0;
int b = 1;
while(i<1){
   
    if(i == 0){
         i = i+1;
        continue;
    }
    b = 0;
}
printf("%d",b);
return 0;
}