	.data 
Msg1: .asciiz "Enter the value of x: " 
result: .asciiz "The result is: " 
Msg2: .asciiz "\n" 
	.text 
	
main: 
	li $v0, 4 
	la $a0, Msg1 
	syscall 
	li $v0, 5 
	syscall 
	move $t0, $v0 
	mul $t1, $t0, $t0 
	li $t2, 4
	mul $t1, $t1, $t2  
	li $t2, 2  
	mul $t3, $t0, $t2 
	add $t1, $t1, $t3 
	li $t2, 3 
	add $t1, $t1, $t2  
	li $v0, 4 
	la $a0, result 
	syscall 
	li $v0, 1 
	move $a0, $t1 
	syscall 
	li $v0, 4 
	la $a0, Msg2 
	syscall 
	jr $ra