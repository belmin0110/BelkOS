.data

.extern _bss_start
.extern _bss_end

.extern _ktext_start
.extern _ktext_end

.text

.globl __start
__start:
  mtc0 $0, $12
  lui $sp, 0x8040

  lui $t0, %hi(_ktext_start)
  ori $t0, $t0, %lo(_ktext_start)

  lui $t1, %hi(_ktext_end)
  ori $t1, $t1, %lo(_ktext_end)

  lui $t2, 0x8000
  ori $t2, $t2, 0x0180

_copy_ktext:
  slt $t3, $t0, $t1
  beq $t3, $0, _bss_setup
  nop

  lw $t4, 0($t0)
  sw $t4, 0($t2)

  addiu $t0, $t0, 4
  addiu $t2, $t2, 4

  j _copy_ktext
  nop

_bss_setup:
  lui $t0, %hi(_bss_start)
  ori $t0, $t0, %lo(_bss_start)

  lui $t1, %hi(_bss_end)
  ori $t1, $t1, %lo(_bss_end)

  slt $t2, $t0, $t1
  beq $t2, $0, _kernel_main
  nop

  sw $0, 0($t0)
  addiu $t0, $t0, 4

  j _bss_setup
  nop

_enable_interrupts:
  ori $t0, $0, 0xFF01
  mtc0 $t0, $12

_kernel_main:
  jal kernel_main
  nop

_panic:
  j _panic
  nop
