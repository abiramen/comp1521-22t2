main:
        # $t0: int i

main__loop_i_to_10__scan_init:
        li      $t0, 0                          # int i = 0;

main__loop_i_to_10__scan_cond:
        bge     $t0, 10, main__loop_i_to_10__scan_end

main__loop_i_to_10__scan_body:

        li      $v0, 5
        syscall
        mul     $t1, $t0, 4                     # 4 * i
        sw      $v0, numbers($t1)               # scanf("%d", &numbers[i]);

main__loop_i_to_10__scan_step:
        addi    $t0, $t0, 1
        b       main__loop_i_to_10__scan_cond   # goto main__loop_i_to_10__scan_cond;

main__loop_i_to_10__scan_end:

main__loop_i_to_10__print_init:
        li      $t0, 0                          # i = 0;

main__loop_i_to_10__print_cond:
        bge     $t0, 10, main__loop_i_to_10__print_end

main__loop_i_to_10__print_body:

        li      $v0, 1
        mul     $t1, $t0, 4                     # 4 * i
        lw      $a0, numbers($t1)
        syscall                                 # putchar(numbers[i]);

        li      $v0, 11
        li      $a0, ' '
        syscall                                 # putchar(' ');


main__loop_i_to_10__print_step:
        addi    $t0, $t0, 1                     # i++;
        b       main__loop_i_to_10__print_cond  # goto main__loop_i_to_10__print_cond

main__loop_i_to_10__print_end:

        li      $v0, 11
        li      $a0, '\n'
        syscall                                 # putchar('\n')

        li      $v0, 0
        jr      $ra                             # return 0;


        

        .data
numbers:
        .word   0:10
        # .word   0, 0, 0, 0, 0, 0, 0, 0, 0, 0
