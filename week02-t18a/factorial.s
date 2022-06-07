main:
        # $t0: int n
        # $t1: int fac
        # $t2: int i

        li      $v0, 4
        la      $a0, prompt_str
        syscall                         # printf("n  = ");


        li      $v0, 5
        syscall
        move    $t0, $v0                # scanf("%d", &n);

        li      $t1, 1                  # int fac = 1;

main__loop_i_to_n:
main__loop_i_to_n_init:
        li      $t2, 1                  # int i = 1;

main__loop_i_to_n_cond:
        bgt     $t2, $t0, main__loop_i_to_n_end

main__loop_i_to_n_body:
        mul     $t1, $t1, $t2           # fac = fac * i

main__loop_i_to_n_step:
        addi    $t2, $t2, 1             # i = i + 1
        b       main__loop_i_to_n_cond

main__loop_i_to_n_end:
        li      $v0, 4
        la      $a0, result_str
        syscall                         # printf("n! = ");

        li      $v0, 1
        move    $a0, $t1
        syscall                         # printf("%d", fac);

        li      $v0, 11
        li      $a0, '\n'
        syscall                         # putchar('\n')

        li      $v0, 0
        jr      $ra                     # return 0;


        .data
prompt_str:
        .asciiz "n  = "
result_str:
        .asciiz "n! = "
