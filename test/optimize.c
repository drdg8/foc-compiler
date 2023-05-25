int add(int a, int b) {
    return a + b;
}

int compute_sum(int n) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i = i+1) {
        sum = add(sum, i);
    }
    return sum;
}

int main() {
    int n = 100;
    printf("The sum is: %d\n", compute_sum(n));
    return 0;
}
