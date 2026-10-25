.section .ktext, "ax", @progbits

_except:
  addiu $k0, $sp, 0
  addiu $sp, $sp, -144

  .set noat
  sw $1, 136($sp)
  .set at

  sw $2, 132($sp)
  sw $3, 128($sp)
  sw $4, 124($sp)
  sw $5, 120($sp)
  sw $6, 116($sp)
  sw $7, 112($sp)
  sw $8, 108($sp)
  sw $9, 104($sp)
  sw $10, 100($sp)
  sw $11, 96($sp)
  sw $12, 92($sp)
  sw $13, 88($sp)
  sw $14, 84($sp)
  sw $15, 80($sp)
  sw $16, 76($sp)
  sw $17, 72($sp)
  sw $18, 68($sp)
  sw $19, 64($sp)
  sw $20, 60($sp)
  sw $21, 56($sp)
  sw $22, 52($sp)
  sw $23, 48($sp)
  sw $24, 44($sp)
  sw $25, 40($sp)
  sw $28, 36($sp)
  sw $30, 32($sp)
  sw $31, 28($sp)

  mfhi $t0
  sw $t0, 24($sp)

  mflo $t0
  sw $t0, 20($sp)

  mfc0 $t0, $14
  sw $t0, 16($sp)

  addiu $a1, $sp, 16
  mfc0 $a0, $13

  lui $t0, %hi(interrupt_handler)
  ori $t0, $t0, %lo(interrupt_handler)
  jalr $t0
  nop


restore_state:
  lw $t0, 16($sp)
  mtc0 $t0, $14

  lw $t0, 20($sp)
  mtlo $t0

  lw $t0, 24($sp)
  mthi $t0

  lw $31, 28($sp)
  lw $30, 32($sp)
  lw $28, 36($sp)
  lw $25, 40($sp)
  lw $24, 44($sp)
  lw $23, 48($sp)
  lw $22, 52($sp)
  lw $21, 56($sp)
  lw $20, 60($sp)
  lw $19, 64($sp)
  lw $18, 68($sp)
  lw $17, 72($sp)
  lw $16, 76($sp)
  lw $15, 80($sp)
  lw $14, 84($sp)
  lw $13, 88($sp)
  lw $12, 92($sp)
  lw $11, 96($sp)
  lw $10, 100($sp)
  lw $9, 104($sp)
  lw $8, 108($sp)
  lw $7, 112($sp)
  lw $6, 116($sp)
  lw $5, 120($sp)
  lw $4, 124($sp)
  lw $3, 128($sp)
  lw $2, 132($sp)

  .set noat
  lw $1, 136($sp)
  .set at

  addiu $sp, $k0, 0

  eret

.globl clear_stack
clear_stack:
  lui $sp, 0x8040

  lui $t0, %hi(kernel_main)
  ori $t0, $t0, %lo(kernel_main)
  mtc0 $t0, $14

  eret
