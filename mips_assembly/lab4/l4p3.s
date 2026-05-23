.data
MSG1 : .asciiz "enter integer : "
MSG2 : .asciiz "not of given integer :"

.text 
main:
li $v0,4
la $a0,MSG1
syscall
li $v0,5
syscall
move $t0,$v0

nor $t0,$t0,$0

li $v0,4
la $a0,MSG2
syscall
li $v0,1
move $a0,$t0
syscall
jr $ra
