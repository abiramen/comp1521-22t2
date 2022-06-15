N_ELEMENTS = 5

main:
	# $t0: int i

main__loop_i_to_5_init:
	li	$t0, 0			# int i = 0;

main__loop_i_to_5_cond:
	bge	$t0, N_ELEMENTS, main__loop_i_to_5_end

main__loop_i_to_5_body:

	# la	$t1, array
	# add 	$t1, $t1, $t0		# array + i

	li	$v0, 11
	lb	$a0, array($t0)		# array + $t0
					# value($reg) = value + $reg
	# lb 	$a0, ($t1)
	syscall				# putchar(array[i]);


	li	$v0, 11
	li	$a0, '\n'
	syscall				# putchar('\n');

main__loop_i_to_5__step:	
	addi	$t0, $t0, 1		# i++;
	b 	main__loop_i_to_5_cond	# goto main__loop_i_to_5_cond;


main__loop_i_to_5_end:
	li	$v0, 0
	jr	$ra			# return 0;

	.data
array:
	.byte	'h', 'e', 'l', 'l', 'o'
