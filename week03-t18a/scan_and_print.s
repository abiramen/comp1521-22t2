main:
        # $t0: int i
main__loop_i_to_10_scan:
main__loop_i_to_10_scan_init:
        li      $t0, 0                                  # int i = 0;

main__loop_i_to_10_scan_cond:
        bge     $t0, 10, main__loop_i_to_10_scan_end

main__loop_i_to_10_scan_body: 
        li      $v0, 5
        syscall
        mul     $t1, $t0, 4                             # 4 * i
        sw      $v0, numbers($t1)                       # scanf("%d", &numbers[i]);

main__loop_i_to_10_scan_step:
        addi    $t0, $t0, 1                             # i++;
        b       main__loop_i_to_10_scan_cond            # goto main__loop_i_to_10_scan_cond;

main__loop_i_to_10_scan_end:


main__loop_i_to_10_print:
main__loop_i_to_10_print_init:
        li      $t0, 0                                  # i = 0;

main__loop_i_to_10_print_cond:
        bge     $t0, 10, main__loop_i_to_10_print_end   # if (i >= 10) goto main__loop_i_to_10_print_end;

main__loop_i_to_10_print_body: 
        li      $v0, 1
        mul     $t1, $t0, 4                             # 4 * i
        lw      $a0, numbers($t1)                       # numbers + 4 * i
        syscall                                         # printf("%d", numbers[i]); 

        li      $v0, 11
        li      $a0, ' '
        syscall                                         # putchar(' ');

main__loop_i_to_10_print_step:
        addi    $t0, $t0, 1                             # i++;
        b       main__loop_i_to_10_print_cond           # goto main__loop_i_to_10_print_cond;

main__loop_i_to_10_print_end:
        li      $v0, 11
        li      $a0, '\n'
        syscall                                         # putchar('\n');

        li      $v0, 0
        jr      $ra                                     # return 0;



        .data
numbers:
        .word   0:10
