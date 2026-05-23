	.data 
x: .asciiz "Enter the value of x: " 
y: .asciiz "Enter the value of y: " 
z: .asciiz "Enter the value of z: " 
result: .asciiz "Result is:  " 
	.text 
main:
	li $v0,4
	la $a0,x
	syscall
	li $v0,5
	syscall
	move $t0,$v0
	li $v0,4
	la $a0,y
	syscall
	li $v0,5
	syscall
	move $t1,$v0
	li $v0,4
	la $a0,z
	syscall
	li $v0,5
	syscall
	move $t2,$v0
	mul $t0, $t0, 5 
	mul $t1, $t1, 3 
	add $t3, $t0, $t1 
	add $t4, $t3, $t2 
	li $v0, 4 
	la $a0, result 
	syscall 
	li $v0, 1 
	move $a0, $t4
	syscall 
	jr $ra