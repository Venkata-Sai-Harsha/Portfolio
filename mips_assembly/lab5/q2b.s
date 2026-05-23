 .data
MSG1: .asciiz "The final value of $a0 is: "
.text

main:
    li $t0, 8
    li $a0, 0
    li $t2, 0

    loop:
        add $t2, $t2, $t0
        addi $t0, $t0, -1
        beq $t0, $zero, exit
        j loop
    
    exit:
        li $v0, 4
        la $a0, MSG1
        syscall
        li $v0, 1
        move $a0, $t2
        syscall
        li $v0, 10
        syscall