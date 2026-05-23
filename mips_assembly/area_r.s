.data
msg1: .asciiz "Enter the length: "
msg2: .asciiz "Enter the breath: "
msg3: .asciiz "area: "
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
	mul $t0,$t0,$t1
	li $v0,4
	la $a0,msg3
	syscall
	li $v0,1
	move $a0,$t0
	syscall
	jr $ra