.section .text
.align 2
.globl setup_lcc_gpio

.include "common/asm/inc/mem_map.inc"
.include "common/asm/inc/gpio.inc"

setup_lcc_gpio:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  li t0, GPOI_CTRL_ADDR # load base gpio addr
  li t1, GPIO_RGB_PINS # load rgb_pins offset
  not t2, t1 # invert rgb vals
  li t3, GPIO_PWM1_MASK # load pwm mask

  # Setup gpio to enable led output with pwm support.
  sw t2, GPIO_INPUT_EN_OFFSET(t0) # enable input for pwm usecase
  sw t1, GPIO_OUTPUT_EN_OFFSET(t0) # enable output on the rgb pins so they are writable
  sw t1, GPIO_OUTPUT_VAL_OFFSET(t0) # set output vals to known state rgb
  sw t1, GPIO_IOF_EN_OFFSET(t0) # enable I/O func for pwm usecase
  sw t3, GPIO_IOF_SEL_OFFSET(t0) # select pwm mask as I/O func

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret

