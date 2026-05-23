	.data 
MSG1: .asciiz "Enter the value for x : " 
MSG2: .asciiz "Enter the value for y : " 
MSG3: .asciiz "Result of \n(4x/3)*y= " 
	.text 
main : 
	li $v0,4 
	la $a0,MSG1 
	syscall 
	li $v0,5 
	syscall 
	move $t0,$v0 
	li $v0,4 
	la $a0,MSG2 
	syscall 
	li $v0,5 
	syscall 
	move $t1,$v0 
	mul $t0,$t0,4 
	div $t0,$t0,3 
	mul $t0,$t0,$t1 
	li $v0,4 
	la $a0,MSG3 
	syscall 
	li $v0,1 
	move $a0,$t0 
	syscall 
	li $v0,10 
	syscall