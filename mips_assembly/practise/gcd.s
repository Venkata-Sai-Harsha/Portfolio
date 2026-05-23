.data
prompt1: .asciiz "Enter the first number: "
prompt2: .asciiz "Enter the second number: "
result: .asciiz "The GCD is: "
.text
main:

    li $v0, 4
    la $a0, prompt1
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, prompt2
    syscall

    li $v0, 5
    syscall
    move $t1, $v0

    move $t2, $zero


    loop:
        beq $t1, $zero, done    

        div $t0, $t1      
        mfhi $t2          

        move $t0, $t1     
        move $t1, $t2     

        j loop

    done:
        li $v0, 4
        la $a0, result
        syscall

        li $v0, 1
        move $a0, $t0
        syscall

        jr $ra