#include <stdio.h>

int main(void) {
    int numbers[10] = {0};

    int i = 0;
    while (i < 10) {
        scanf("%d", &numbers[i]);
        i++;
    }

    i = 0;
    while (i < 10) {
        printf("%d ", numbers[i]);
        i++;
    }

    putchar('\n');
}
