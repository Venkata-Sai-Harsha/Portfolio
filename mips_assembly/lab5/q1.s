.data
MSG1: .asciiz "Enter the number A: "
MSG2: .asciiz "Enter the number B: "
MSG3: .asciiz "A is multiple of B"
MSG4: .asciiz "B is multiple of A"
MSG5: .asciiz "A and B are not multiple of each other"
.text

main:
    li $v0,4
    la $a0,MSG1
    syscall

    li $v0,5
    syscall
    move $t0,$v0

    li $v0,4
    la $a0,MSG2
    syscall 

    li $v0,5
    syscall
    move $t1,$v0

    div $t2,$t0,$t1
    mfhi $t3

    beq $t3,0,print1
    div $t2,$t1,$t0
    mfhi $t3

    beq $t3,0,print2

    li $v0,4
    la $a0,MSG5
    syscall
    j exit

    print1:
        li $v0,4
        la $a0,MSG3
        syscall
        j exit

    print2:
        li $v0,4
        la $a0,MSG4
        syscall
        j exit

    exit:
        jr $ra