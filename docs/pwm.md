## Notes On Pulse Width Modulator

### Duty Cycle
The duty cycle represents the percentage of the period where the switch (pin) is on.
For example, a duty cycle of 50% means that the switch is on for half the cycle while
a duty cycle of 25% means that the switch is on for only a quarter of the cycle.
Shorter ON cycles consists with dimmer brightness.

For the FE310-G002 MCU the register that controls this aspect of the PWM is called
`pwmcmpX`.

### Resolution
The resolution determines what degree of granularity you get for setting up the
duty cycle. For example, if you only have a count of 7 i.e. a register of width 3 
you get duty cycles in increments of 12.5%. Increasing the width causes the frequency
of the PWM to shrink since it takes longer to count up to a certain number.

For the FE310-G002 MCU the register that controls this aspect of the PWM is called
`pwms` if `pwmscale` is set to any value other than 0.  

### PWM Cycle
If `pwmzerocmp` is ON then `pwmcmp0` determines the PWM cycle length which causes
`pwmcmpXip` to turn ON whenever `pwms` is the same as `pwmcmp0`. On the next
cycle `pwms` and `pwmcount` are reset to zero.

### Routing to GPIO
To route PWM state to GPIO only `iof_en` and `iof_sel` must be set during the GPIO setup phase.
The `iof_sel` must be set to a `PWM1_MASK` value of `0x00780000` so that the
GPIO knows that it must get its input from the PWM1 unit.


### LEARN MORE

[STM32 Mitch Davis Guide](https://www.youtube.com/watch?v=AjN58ceQaF4&list=PLNyfXcjhOAwO5HNTKpZPsqBhelLF2rWQx&index=3)

[Techquickie](https://www.youtube.com/watch?v=ISzRh5eN_Pg)

