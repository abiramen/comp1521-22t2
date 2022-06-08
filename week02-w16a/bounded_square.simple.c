#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 46340) goto main__x_gt_46340;
    y = x * x;
    printf("%d", y);
    putchar('\n');
    goto main__epilogue;

main__x_gt_46340:
    printf("square too big for 32 bits\n");

main__epilogue:
    return 0;
}
