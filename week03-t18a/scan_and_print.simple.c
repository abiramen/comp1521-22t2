#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

main__loop_i_to_10_scan:
main__loop_i_to_10_scan_init:;
    i = 0;

main__loop_i_to_10_scan_cond:
    if (i >= 10) goto main__loop_i_to_10_scan_end;
main__loop_i_to_10_scan_body:
    scanf("%d", &numbers[i]);   // numbers + 4 * i
main__loop_i_to_10_scan_step:
    i++;
    goto main__loop_i_to_10_scan_cond;
main__loop_i_to_10_scan_end:;



main__loop_i_to_10_print:
main__loop_i_to_10_print_init:;
    i = 0;
main__loop_i_to_10_print_cond:
    if (i >= 10) goto main__loop_i_to_10_print_end;
main__loop_i_to_10_print_body:
    printf("%d", numbers[i]);   // numbers + 4 * i
    putchar(' ');
main__loop_i_to_10_print_step:
    i++;
    goto main__loop_i_to_10_print_cond;
main__loop_i_to_10_print_end:
    putchar('\n');
    return 0;
}
