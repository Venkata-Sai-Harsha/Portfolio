.data
msg1:.asciiz "Enter a string : "
msg2:.asciiz "it is palindrome : "
msg3:.asciiz "it is not palindrome : "
.text

main:

    li $v0,4
    la $a0,msg1
    syscall

    li $v0,5
    syscall
    move $t0,$v0

    move $t1,$t0
    li $t2,0

loop:
    li $t5,10
    beq $t1,0,exit
    div $t1,$t5
    mfhi $t3
    mflo $t1

    mul $t2,$t2,10
    add $t2,$t2,$t3

    j loop

exit:

    beq $t0,$t2,ispal

    li $v0, 4
    la $a0, msg3
    syscall

    jr $ra

ispal:
    li $v0, 4
    la $a0,msg2
    syscall

jr $ra