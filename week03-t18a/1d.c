#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

    printf("%p\n", &array[0]);
    printf("%p\n", array);

    for (int i = 0; i < N_ELEMENTS; i++) {
        // array[1] = array + 1
        // array[3] = array + 3

        printf("%p %p ", &array[i], array + i);

        printf("%d", *(array + i));
        putchar('\n');
    }

    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

