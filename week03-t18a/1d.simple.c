#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    char array[N_ELEMENTS] = {'h', 'e', 'l', 'l', 'o'};

main__loop_i_to_5:
main__loop_i_to_5_init:
    int i = 0;
main__loop_i_to_5_cond:
    if (i >= N_ELEMENTS) goto main__loop_i_to_5_end;
main__loop_i_to_5_body:
    putchar(array[i]);
    // *(array + i)
    putchar('\n');
main__loop_i_to_5_step:
    i++;
    goto main__loop_i_to_5_cond;
main__loop_i_to_5_end:
    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

