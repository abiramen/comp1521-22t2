// non recursively calculate a factorial in C
// Abiram Nadarajah, Feb 2022

#include <stdio.h>

int main(void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    // for (int i = 1; i <= n; i++) {
    //     fac *= i;
    // }

    // int i = 1;
    // while (i <= n) {
    //     fac *= i;
    //     i++;
    // }

main__loop_i_to_n:
main__loop_i_to_n_init:
    int i = 1;

main__loop_i_to_n_cond:

main__loop_i_to_n_body:
    fac *= i;   // fac = fac * i

main__loop_i_to_n_step:
    i++;        // i = i + 1;
    goto main__loop_i_to_n_cond;

main__loop_i_to_n_end:

    printf("n! = ");
    printf("%d", fac);
    putchar('\n');
    return 0;
}
