#pragma once
#define LCC_LED_MAX_BRIGHTNESS 0x20
int run_led_color_cycle();

void setup_lcc_gpio();
void setup_lcc_pwm();
