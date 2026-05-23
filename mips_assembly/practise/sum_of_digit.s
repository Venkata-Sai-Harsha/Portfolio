.data
msg1: .asciiz "Enter a number: "
msg2: .asciiz "sum of the digits is: "
.text

main:
    li $v0, 4
    la $a0, msg1
    syscall
    li $v0, 5
    syscall
    move $t0, $v0

    li $t1, 0
    li $t2, 10

loop:   
    div $t0, $t2
    mflo $t3
    mfhi $t4
    add $t1, $t1, $t4
    move $t0, $t3
    beq $t0, $0, exit
    j loop

exit:
    li $v0, 4
    la $a0, msg2
    syscall
    li $v0, 1
    move $a0, $t1
    syscall

    jr $ra