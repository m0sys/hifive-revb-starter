.section .text
.align 2
.globl dimm_pwm
.include "common/asm/inc/mem_map.inc"
.include "common/asm/inc/pwm.inc"

dimm_pwm:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  # Load pwm consts.
  li t0, PWM1_ADDR # load base pwm addr

  # Update pwm pin values (dimm them).
  sw a0, PWM_CMP3_OFFSET(t0) # set pwm count for red led to new red val
  sw a1, PWM_CMP1_OFFSET(t0) # set pwm count for green led to new green val
  sw a2, PWM_CMP2_OFFSET(t0) # set pwm count for blue led to new blue val

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret
