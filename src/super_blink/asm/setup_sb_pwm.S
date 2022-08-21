.section .text
.align 2
.globl setup_sb_pwm
.include "common/asm/inc/mem_map.inc"
.include "common/asm/inc/pwm.inc"

setup_sb_pwm:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  li t0, PWM1_ADDR # load base pwm addr
  li t1, PWM_CMP_RED_VAL # load count for red led
  li t2, PWM_CMP_GREEN_VAL # load count for green led
  li t3, PWM_CMP_BLUE_VAL # load count for blue led
  li t4, PWM_CFG_PINS # load the config for pwm
  li t5, PWM_CMP0_VAL # load pwm clk cycle

  # Set count to known state.
  sw zero, PWM_CNT_OFFSET(t0) 
  ## sw zero, PWM_SCNT_OFFSET(t0) 
  sw zero, PWM_CFG_OFFSET(t0)
  sw zero, PWM_CMP0_OFFSET(t0)

  sw t1, PWM_CMP3_OFFSET(t0) # set pwm count for red led
  sw t2, PWM_CMP1_OFFSET(t0) # set pwm count for green led
  sw t3, PWM_CMP2_OFFSET(t0) # set pwm count for blue led
  sw t4, PWM_CFG_OFFSET(t0) # set pwm cfg
  sw t5, PWM_CMP0_OFFSET(t0) # set pwm clk cycle

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret


