.data
msg1: .asciiz "Enter the first number: "
msg2: .asciiz "Enter the second number: "
msg3: .asciiz "division is: "
      .text
main:
	li $v0,4
	la $a0,msg1
	syscall
	li $v0,5
	syscall
	move $t0,$v0
	li $v0,4
	la $a0,msg2
	syscall
	li $v0,5
	syscall
	move $t1,$v0
	div $t0,$t0,$t1
	li $v0,4
	la $a0,msg3
	syscall
	li $v0,1
	move $a0,$t0
	syscall
	jr $ra