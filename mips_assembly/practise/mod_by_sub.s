.data
msg1:.asciiz " enter a number : "
msg2:.asciiz "output "
.text

main:

li $v0,4
la $a0,msg1
syscall

li $v0,5
syscall
move $t0,$v0

loop:

sub $t0,$t0,3
blt $t0,3,exit
j loop

exit:

li $v0,4
la $a0,msg2
syscall

li $v0,1
move $a0,$t0
syscall

jr $ra