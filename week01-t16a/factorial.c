#include <stdio.h>

int factorial(int n);

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}

// calculates n!
int factorial(int n) {
    
    if (n <= 0) return 1; 
    // recursive case
    return factorial(n - 1) * n;
}
