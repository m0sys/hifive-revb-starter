// Cycles through Red, Green, and Blue.
#pragma once
#define LCC_LED_MAX_BRIGHTNESS 0x20
int run_dimm_led();

void setup_dl_gpio();
void setup_dl_pwm();
