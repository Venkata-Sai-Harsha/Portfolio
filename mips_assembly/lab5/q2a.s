.data
MSG1: .asciiz "Enter the value of $t10: "
MSG2: .asciiz "Enter the value of $t8: "
MSG3: .asciiz "Enter the value of $t1: "
MSG4: .asciiz "Enter the value of $t2: "
MSG5: .asciiz "After executing the instructions: "
MSG6: .asciiz "\nThe value of $s0 is: "
MSG7: .asciiz "\nThe value of $t1 is: "
MSG8: .asciiz "\nThe value of $t2 is: "
.text

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
    move $t8, $v0

    li $v0, 4
    la $a0, MSG3
    syscall

    li $v0, 5
    syscall
    move $t1, $v0

    li $v0, 4
    la $a0, MSG4
    syscall

    li $v0, 5
    syscall
    move $t2, $v0

    ble $t0, $zero, if
    bge $t0, $zero, else
    beq $t0, $zero, exit

if:
    sub $s0, $zero, $t8
    addi $t1, $t1, 2
    j exit

else:
    move $s0, $t8
    addi $t2, $t2, 1
    j exit

exit:
    li $v0, 4
    la $a0, MSG5
    syscall

    li $v0, 4
    la $a0, MSG6
    syscall

    li $v0, 1
    move $a0, $s0
    syscall

    li $v0, 4
    la $a0, MSG7
    syscall

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 4
    la $a0, MSG8
    syscall

    li $v0, 1
    move $a0, $t2
    syscall

    jr $ra