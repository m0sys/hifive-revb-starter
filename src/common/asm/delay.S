.section .text
.align 2

.globl delay

.include "common/asm/inc/mem_map.inc"

# a0 - delay (milliseconds)

delay:
  # Func preamble.
  addi sp, sp, -16 # alloc stk frame
  sw ra, 12(sp) # save ret addr onto stk

  li t0, MTIME # load the timer reg
  lw t1, 0(t0) # load curr val of timer

  li t2, MTIME_FREQ # load the timer freq 
  mul t2, t2, a0 # mult milliseconds with freq
  add t2, t1, t2 # mtime is now t2

1:
 lw t1, 0(t0) # load mtime again
 blt t1, t2, 1b # keep looping until mtime = mtime_init + delay

exit:
  # Func epilog.
  lw ra, 12(sp) # restore ret addr from stk
  addi sp, sp, 16 # dealloc stk frame
  ret

