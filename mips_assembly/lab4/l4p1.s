.data
MSG1 : .asciiz "enter a integer :"
MSG2 : .asciiz "number after shifting a number by two bits :"
MSG3 : .asciiz "enter number to be shifted :"
.text 
main:
li $v0,4
la $a0,MSG1
syscall
li $v0,5
syscall
move $t0,$v0

li $v0,4
la $a0,MSG3
syscall
li $v0,5
syscall
move $t1,$v0

sll $t0,$t0,$t1

li $v0,4
la $a0,MSG2
syscall
li $v0,1
move $a0,$t0
syscall
jr $ra