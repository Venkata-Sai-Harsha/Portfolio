.data

MSG1 : .asciiz "Enter the number : "
.text

main:
	li $v0,4
	la $a0,MSG1
	syscall
	li $v0,5
	syscall
	move $t0,$v0

	li $t1,2
	li $t2,0
	li $t3,1
	
	li $v0,1
	move $a0,$t2
	syscall
	li $v0,1
	move $a0,$t3
	syscall
	add $t4,$t2,$t3

loop :
	beq $t1,$t0,exit
	add $t4,$t3,$t2
	li $v0,1
	move $a0,$t4
	syscall
	move $t2,$t3
	move $t3,$t4
	addi $t1,$t1,1
	j loop

exit :
	jr $ra