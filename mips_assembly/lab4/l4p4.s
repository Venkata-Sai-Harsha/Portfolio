.data
MSG1 : .asciiz "left shift : "
MSG2 : .asciiz "right shift : "
MSG3 : .asciiz "\n"

.text 
main:

lui $t2,0xabcd
ori $t2,$t2,0x1234

sll $t1,$t2,8

li $v0,4
la $a0,MSG1
syscall
li $v0,1
move $a0,$t1
syscall

li $v0,4
la $a0,MSG3
syscall

srl $t1,$t2,4

li $v0,4
la $a0,MSG2
syscall
li $v0,1
move $a0,$t1
syscall
jr $ra