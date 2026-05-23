.data

MSG1 : .asciiz "Enter your number : "
.text

main :
	li $v0,4
	la $a0,MSG1
	syscall 
	li $v0,5
	syscall
	move $t0,$v0
	
	li $t1,0
	li $t2,2
	li $t3,2

loop :
	bgt $t2,$t0,exit #$t0(5)
	li $t3,2
	j check

check :
	
	beq $t3,$t2,print
	div $t4,$t2,$t3
	mfhi $t5
	addi $t3,$t3,1
	beq $t5,$0,plus
	j check
plus :
	addi $t2,$t2,1
	j loop

print :

	li $v0,1
	move $a0,$t3
	syscall
    #add $t6,$t6,$t3
	addi $t2,$t2,1
	j loop

exit :
    # li $v0,1
    # move $a0,$t6
    # syscall
	jr $ra