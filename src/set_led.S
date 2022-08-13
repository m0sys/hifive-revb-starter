.section .text
.align 2

.globl set_led
.include "mem_map.inc"
.include "gpio.inc"

.equ NOERR, 0x0
.equ ERR, 0x1
.equ LEDON, 0x1

# a0 - which LED to set.
# a1 - what ON/OFF state to set LED.
set_led:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  li t0, GPOI_CTRL_ADDR # load base gpio addr
  lw t1, GPIO_OUTPUT_VAL(t0) # get curr val of the pins
  
  beqz a1, led_off # branch off if LED a1 requests it
  li t2, LEDON # ld on val to t2
  beq a1, t2, led_on # branch if ON state is requested
  li a0, ERR # got invalid state - ret error
  j exit

led_on:
  xor t1, t1, a0 # change only the LED that has been requested
  sw t1, GPIO_OUTPUT_VAL(t0) # write new output to gpio reg
  li a0, NOERR
  sw t1, GPIO_OUTPUT_XOR(t0)
  j exit

led_off:
  xor a0, a0, 0xffffffff # invert everything so all bits are off except LED bits
  and t1, t1, a0 # turn off LED we want
  sw t1, GPIO_OUTPUT_VAL(t0) # write new output to gpio reg 
  li a0, NOERR

  # Func epilog.
exit:
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret

