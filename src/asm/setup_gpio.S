.section .text
.align 2

.globl setup_gpio
.include "asm/inc/mem_map.inc"
.include "asm/inc/gpio.inc"

setup_gpio:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  li t0, GPOI_CTRL_ADDR # load base gpio addr
  li t1, GPIO_RGB_PINS # load rgb_pins offset
  sw t1, GPIO_OUTPUT_EN(t0) # enable output on the rgb pins so they are writable
  sw t1, GPIO_OUTPUT_XOR(t0) # invert output to active high mode
  sw zero, GPIO_OUTPUT_VAL(t0) # clear leds to known state 0

  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret

