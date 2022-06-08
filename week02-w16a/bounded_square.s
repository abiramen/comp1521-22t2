        .text
main:
        # $t0: int x      
        # $t1: int y  
        li      $v0, 4
        la      $a0, enter_number_str
        syscall					# printf("Enter a number: ");

	li	$v0, 5
	syscall	
	move	$t0, $v0			# scanf("%d", &x);

        bgt    $t0, 46340, main__x_gt_46340     # if (x > 46340) goto main__x_gt_46340;

        mul	$t1, $t0, $t0	                # y = x * x


	li	$v0, 1
	move	$a0, $t1
	syscall					# printf("%d", y);

        li      $v0, 11
        li      $a0, '\n'
        syscall                                 # putchar('\n')

        b       main__epilogue                  # goto main__epilogue;

main__x_gt_46340:
        li      $v0, 4
        la      $a0, too_big_str
        syscall					# printf("square too big for 32 bits\n");

main__epilogue:
        li      $v0, 0
        jr      $ra                             # return 0;

        .data
enter_number_str:
        .asciiz "Enter a number: "

too_big_str:
        .asciiz "square too big for 32 bits\n"
