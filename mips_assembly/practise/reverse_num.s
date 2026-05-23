.data
msg1: .asciiz "Enter a number: "
msg2: .asciiz "Reverse a number is: "
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
        div $t3, $t0, $t2
        mfhi $t4
        mflo $t0
        mul $t1, $t1, $t2
        add $t1, $t1, $t4
        beq $t0, $zero, exit
        j loop

    exit:
        li $v0, 4
        la $a0, msg2
        syscall
        li $v0, 1
        move $a0, $t1
        syscall
        jr $ra 