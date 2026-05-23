.data
msg1: .asciiz "n is "
msg2: .asciiz "sum is "
.text

main:

li $v0,4
la $a0,msg1
syscall

li $v0,5
syscall
move $t0,$v0 #t0 is n

li $t1,1
li $t2,0
li $t3,0
loop:
     addi $t1,$t1,1
     li  $t3,1
lop: addi $t3,$t3,1
     beq $t3,$t1,sum
     div $t1,$t3
     mfhi $t4
     beq $t4,$0,kk
     j lop
kk:
     beq $t1,$t0,exit
     j loop
sum: add $t2,$t2,$t1
     j kk

exit: li $v0,4
      la $a0,msg2
syscall


li $v0,1
move $a0,$t2
syscall

jr $ra