// Cycles through Red, Green, and Blue in a blinking fashion.
#pragma once
#define DSB_LED_MAX_BRIGHTNESS 0x20
int run_dimm_super_blink();

void setup_dsb_gpio();
void setup_dsb_pwm();
