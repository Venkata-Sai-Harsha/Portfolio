.data
MSG1: .asciiz "The value of Z[K]: "
.text

main:
    li $t0, 60
    li $t1, 20

    div $t1, $t1, 4
    add $t1, $t1, 210
    mul $t1, $t1, 16
    sub $t0, $t0, $t1

    li $v0, 4
    la $a0, MSG1
    syscall

    li $v0, 1
    move $a0, $t0
    syscall

    jr $ra