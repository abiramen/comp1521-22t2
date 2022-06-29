#include <stdio.h>

int main(void) {
    int n;
    printf("Enter a value: ");
    scanf("%d", &n);


    printf("n in decimal is: %d\n", n);
    printf("n in hexadecimal: %x\n", n);
    printf("n in octal: %o\n", n);
    return 0;
}
