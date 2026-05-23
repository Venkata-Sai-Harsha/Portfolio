.data
msg1:.asciiz "Enter the number : "
msg2:.asciiz "Perfect number : "
msg3:.asciiz "Not perfect number : "
.text

main:

    li $v0,4
    la $a0,msg1
    syscall

    li $v0,5
    syscall
    move $t0,$v0

    li $t1,1  #counter
    li $t2,0  #sum

loop:

    beq $t1,$t0,exit
    div $t3,$t0,$t1
    mfhi $t4
    beq $t4,0,sum
    addi $t1,$t1,1
    j loop


sum :
    add $t2,$t2,$t1
    addi $t1,$t1,1
    j loop

exit:
    beq $t0,$t2,perf
    bne $t0,$t2,nperf

perf:

    li $v0,4
    la $a0,msg2
    syscall

    li $v0,1
    move $a0, $t2
    syscall

    jr $ra

nperf:
    li $v0,4
    la $a0,msg3
    syscall

    li $v0,1
    move $a0, $t2
    syscall

    jr $ra