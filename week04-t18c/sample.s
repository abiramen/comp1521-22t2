main:

main__prologue:
	begin
	push	$ra

main__body:
	li	$t0, 5
	li	$a0, 0
	li	$s0, 5			# saved registers
					# if we modify an $s register, we have to restore it
					# to its original value before our function returns

	jal	some_other_func		# some_other_func(0)

	# we don't know what $a0 contains at this point
	# we also don't know what $t0 (or any $t register) contains at this point
	# however, the value of $s0 should still be preserved by the other function

main__epilogue:

	pop	$ra
	end
	jr	$ra
