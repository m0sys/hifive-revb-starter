.section .text
.align 2
.globl setup_lcc_pwm
.include "common/asm/inc/mem_map.inc"
.include "common/asm/inc/pwm.inc"

setup_lcc_pwm:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  # Load pwm consts.
  li t0, PWM1_ADDR # load base pwm addr
  li t1, PWM_CFG_PINS # load the config for pwm
  li t2, PWM_CMP0_VAL # load pwm clk cycle

  # Set count & pwms to known state.
  sw zero, PWM_CNT_OFFSET(t0) 
  sw zero, PWM_SCNT_OFFSET(t0) 

  sw t1, PWM_CFG_OFFSET(t0) # set pwm cfg
  sw t2, PWM_CMP0_OFFSET(t0) # set pwm clk cycle

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret


