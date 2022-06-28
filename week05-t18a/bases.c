#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);
    
    printf("decimal input: %d\n", n);
    printf("hexadecimal input: %x\n", n);
    printf("octal input: %o\n", n);
    return 0;
}
