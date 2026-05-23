.data
MSG1 : .asciiz "enter a value of x: "
MSG2 : .asciiz "enter a value of y: "
MSG3 : .asciiz "enter a value of z: "
MSG4 : .asciiz "enter a value of q: "
MSG5 : .asciiz "value of x after operation :"
.text 
main:
li $v0,4
la $a0,MSG1
syscall
li $v0,5
syscall
move $s1,$v0

li $v0,4
la $a0,MSG2
syscall
li $v0,5
syscall
move $s2,$v0

li $v0,4
la $a0,MSG3
syscall
li $v0,5
syscall
move $s3,$v0

li $v0,4
la $a0,MSG4
syscall
li $v0,5
syscall
move $s4,$v0

sub $t0,$s3,$s4
add $t0,$t0,$s2
add $t0,$t0,$s1

li $v0,4
la $a0,MSG5
syscall
li $v0,1
move $a0,$t0
syscall
jr $ra