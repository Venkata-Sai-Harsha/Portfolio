    .data
MSG1: .asciiz "Enter a number: "
MSG2: .asciiz "The factorial of the number is: "
.text

main:
    li $v0, 4
    la $a0, MSG1
    syscall
    li $v0, 5
    move $t0, $v0
    syscall
    li $t1, 1
    loop:
        beq $t0, 1, exit
        mul $t1, $t1, $t0
        addi $t0, $t0, -1
        j loop
    exit:
    li $v0, 4
    la $a0, MSG2
    syscall
    li $v0, 1
    move $a0, $t1
    syscall
    jr $ra