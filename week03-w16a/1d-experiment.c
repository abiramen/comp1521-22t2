#include <stdio.h>
#define N_ELEMENTS 5

int main(void) {
    int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

    
    for (int i = 0; i < N_ELEMENTS; i++) {
        printf("%p ", &array[i]);
        // printf("%p ", array + i);    

        // general formula for indexing a 1 dimensional array
        // array[i] = array + sizeof(element) * i

        printf("%d ", array[i]);        // &array[i] = array + 4 * i
        putchar('\n');                  // &array[i] = array + 4 * i
    }

    return 0;
}


// What if we had
// int array[N_ELEMENTS] = {3, 1, 4, 1, 5};

