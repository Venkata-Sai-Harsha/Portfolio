.data
MSG1: .asciiz "Enter a num1: "
MSG2: .asciiz "Enter a num2: "
MSG3: .asciiz "The multiplication of num1 and num2 is: "

.text
.globl main
main:
    li $v0, 4
    la $a0, MSG1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, MSG2
    syscall
    
    li $v0, 5
    syscall
    move $t1, $v0

    li $t2, 0

loop:
    
    add $t3, $t3, $t0
    addi $t2, $t2, 1
    beq $t2, $t1, exit
    j loop

exit:
    li $v0, 4
    la $a0, MSG3
    syscall

    li $v0, 1
    move $a0, $t3
    syscall

    li $v0, 10
    syscall