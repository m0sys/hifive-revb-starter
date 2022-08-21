.section .text
.align 2
.globl setup_dsb_gpio

.include "common/asm/inc/mem_map.inc"
.include "common/asm/inc/gpio.inc"

setup_dsb_gpio:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  # Load gpio consts.
  li t0, GPOI_CTRL_ADDR # load base gpio addr
  li t1, GPIO_RGB_PINS # load rgb_pins offset
  li t2, GPIO_PWM1_MASK # load pwm IOF sel mask

  # Setup gpio to enable led output with pwm support.
  sw t1, GPIO_IOF_EN_OFFSET(t0) # enable I/O func for pwm usecase
  sw t2, GPIO_IOF_SEL_OFFSET(t0) # select pwm mask as I/O func

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret


