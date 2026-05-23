    .data
msg1:   .asciiz "Enter a number: "
msg2:   .asciiz "Number is prime."
msg3:   .asciiz "Number is not prime."

    .text
    .globl main

main:
    li $v0, 4               # Print "Enter a number: " message
    la $a0, msg1
    syscall

    li $v0, 5               # Read integer from user
    syscall
    move $t0, $v0           # Store input number in $t0

    li $t1, 2               # Initialize divisor to 2

loop:
    beq $t1, $t0, prime     # If divisor equals input number, number is prime
    div $t0, $t1            # Divide input number by divisor
    mfhi $t2                # Remainder is in $t2
    beqz $t2, not_prime     # If remainder is zero, number is not prime

    addi $t1, $t1, 1        # Increment divisor
    j loop

prime:
    li $v0, 4               # Print "Number is prime." message
    la $a0, msg2
    syscall
    j exit

not_prime:
    li $v0, 4               # Print "Number is not prime." message
    la $a0, msg3
    syscall

exit:
    li $v0, 10              # Exit program
    syscall