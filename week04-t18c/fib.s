	.data
enter_number_str:
	.asciiz "Enter a number: "
result_str_1:
	.asciiz "Fibonacci of "
result_str_2:
	.asciiz " is "

	.text
main:
	# Args: void
	# Returns: int
	#
	# Registers:
	# 	Stack:		[$ra]
	#	Uses:		[$v0, $a0, $t0]
	#	Clobbers:	[$v0, $a0, $t0]
	#
	# Locals:
	#   - $t0: int n
	#
	# Structure:
	#   - main
	#     -> [prologue]
	#     -> [body]
	#     -> [epilogue]

main__prologue:
	begin					# creates a stack frame for a function
	push	$ra

main__body:
	li	$v0, 4				# syscall 4: print_string
	la	$a0, enter_number_str		#
	syscall					# printf("Enter a number: ");

	li	$v0, 5				# syscall 5: read_int
	syscall					#
	move	$t0, $v0			# scanf("%d", &n);

	li	$v0, 4				# syscall 4: print_string
	la	$a0, result_str_1		#
	syscall					# printf("Fibonacci of ");

	li	$v0, 1				# syscall 1: print_int
	move	$a0, $t0			#
	syscall					# printf("%d", n);

	li	$v0, 4				# syscall 4: print_string
	la	$a0, result_str_2		#
	syscall					# printf(" is ");

	move	$a0, $t0
	jal	fib				# fib(n);
						# now that the function is done,
						# $v0 will contain the result

	move	$a0, $v0
	li	$v0, 1				# syscall 1: print_int
	syscall					# printf("%d", fib(n));

	li	$v0, 11				# syscall 11: print_char
	li	$a0, '\n'			#
	syscall					# putchar('\n');

	li	$v0, 0

main__epilogue:

	pop	$ra
	end					# destroys the stack frame that we
						# created for our function

	jr	$ra				# return 0;


fib:
	# Args:
	#   - $a0: int n
	# Returns: int
	#
	# Registers:
	# 	Stack:		[$ra, $s0, $s1]
	#	Uses:		[$v0, $a0, $s0, $s1]
	#	Clobbers:	[$v0, $a0]
	#
	# Locals:
	#   - $s0: int fib(n - 1)
	#   - $s1: int n
	#
	# Structure:
	#   - fib
	#     -> [prologue]
	#     -> [body]
	#        -> n_lt_2
	#     -> [epilogue]

fib__prologue:
	begin
	push	$ra
	push	$s0
	push	$s1

fib__body:
	blt	$a0, 2, fib__n_lt_2

	move	$s1, $a0

	addi	$a0, $a0, -1
	jal	fib					
	move	$s0, $v0				# fib(n - 1) 


	addi	$a0, $s1, -2
	jal	fib					# fib(n - 2)

	add 	$v0, $s0, $v0				# fib(n - 1) + fib(n - 2)

	b 	fib__epilogue
fib__n_lt_2:
	move	$v0, $a0

fib__epilogue:

	pop	$s1
	pop	$s0
	pop	$ra
	end
	jr	$ra
	# jr stands for jump register
	# it jumps to the instruction which is pointed to by the register
