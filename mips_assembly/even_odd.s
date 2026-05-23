	.data
MSG1 : .asciiz "Enter num: "
MSG2: .asciiz "It's Even Number "
MSG3 : .asciiz "It's Odd Number "
	.text
	
main:
	li $v0,4
	la $a0,MSG1
	syscall
	li $v0,5
	syscall
	move $t0,$v0
	li $t1,2
	div $t0,$t1
	mfhi $s0
	beq $s0,1,odd
	j even
	odd:
		li $v0,4
		la $a0,MSG3
		syscall
		j exit
	even:
		li $v0,4
		la $a0,MSG2
		syscall
		j exit
	exit:
		jr $ra