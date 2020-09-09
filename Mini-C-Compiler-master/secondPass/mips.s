.data
endline: .asciiz "\n"
.text
_fact:
subu $sp, $sp, 92
sw $ra, 88($sp)
sw $fp, 84($sp)
move $fp, $sp
lw $t0, 92($sp)
li $t1, 0
sle $t2, $t0, $t1
beq $t2, 0, L7
li $t2, 1
move $v0, $t2
j end__fact
L7:
lw $t2, 92($sp)
lw $t1, 92($sp)
li $t0, 1
sub $t3, $t1, $t0
sub $sp, $sp, 4
sw $t3, 0($sp)
sw $t0, 84($sp)
sw $t1, 80($sp)
sw $t2, 76($sp)
sw $t3, 72($sp)
sw $t4, 68($sp)
sw $t5, 64($sp)
sw $t6, 60($sp)
sw $t7, 56($sp)
sw $t8, 52($sp)
sw $t9, 48($sp)
s.s $f0, 44($sp)
s.s $f1, 40($sp)
s.s $f2, 36($sp)
s.s $f3, 32($sp)
s.s $f4, 28($sp)
s.s $f5, 24($sp)
s.s $f6, 20($sp)
s.s $f7, 16($sp)
s.s $f8, 12($sp)
s.s $f9, 8($sp)
s.s $f10, 4($sp)
jal _fact
lw $t0, 84($sp)
lw $t1, 80($sp)
lw $t2, 76($sp)
lw $t3, 72($sp)
lw $t4, 68($sp)
lw $t5, 64($sp)
lw $t6, 60($sp)
lw $t7, 56($sp)
lw $t8, 52($sp)
lw $t9, 48($sp)
l.s $f0, 44($sp)
l.s $f1, 40($sp)
l.s $f2, 36($sp)
l.s $f3, 32($sp)
l.s $f4, 28($sp)
l.s $f5, 24($sp)
l.s $f6, 20($sp)
l.s $f7, 16($sp)
l.s $f8, 12($sp)
l.s $f9, 8($sp)
l.s $f10, 4($sp)
move $t3, $v0
add $sp, $sp, 4
mul $t0, $t2, $t3
move $v0, $t0
j end__fact
end__fact:
move $sp, $fp
lw $ra, 88($sp)
lw $fp, 84($sp)
addu $sp, $sp, 92
j $ra
main:
subu $sp, $sp, 100
sw $ra, 96($sp)
sw $fp, 92($sp)
move $fp, $sp
li $t0, 3
sw $t0, 4($sp)
li $v0 5
syscall
move $t0, $v0
sw $t0, 4($sp)
lw $t0, 4($sp)
sub $sp, $sp, 4
sw $t0, 0($sp)
sw $t0, 92($sp)
sw $t1, 88($sp)
sw $t2, 84($sp)
sw $t3, 80($sp)
sw $t4, 76($sp)
sw $t5, 72($sp)
sw $t6, 68($sp)
sw $t7, 64($sp)
sw $t8, 60($sp)
sw $t9, 56($sp)
s.s $f0, 52($sp)
s.s $f1, 48($sp)
s.s $f2, 44($sp)
s.s $f3, 40($sp)
s.s $f4, 36($sp)
s.s $f5, 32($sp)
s.s $f6, 28($sp)
s.s $f7, 24($sp)
s.s $f8, 20($sp)
s.s $f9, 16($sp)
s.s $f10, 12($sp)
jal _fact
lw $t0, 92($sp)
lw $t1, 88($sp)
lw $t2, 84($sp)
lw $t3, 80($sp)
lw $t4, 76($sp)
lw $t5, 72($sp)
lw $t6, 68($sp)
lw $t7, 64($sp)
lw $t8, 60($sp)
lw $t9, 56($sp)
l.s $f0, 52($sp)
l.s $f1, 48($sp)
l.s $f2, 44($sp)
l.s $f3, 40($sp)
l.s $f4, 36($sp)
l.s $f5, 32($sp)
l.s $f6, 28($sp)
l.s $f7, 24($sp)
l.s $f8, 20($sp)
l.s $f9, 16($sp)
l.s $f10, 12($sp)
move $t0, $v0
add $sp, $sp, 4
sw $t0, 0($sp)
lw $t0, 0($sp)
move $a0, $t0
li $v0 1
syscall
li $v0, 4
la $a0, endline
syscall
li $t0, 0
move $v0, $t0
j end_main
end_main:
move $sp, $fp
lw $ra, 96($sp)
lw $fp, 92($sp)
addu $sp, $sp, 100
j $ra
