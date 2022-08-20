// super blink (sp).
#pragma once
#define SB_ON 0x01
#define SB_OFF 0x00
#define SB_NUM_LEDS 0x03

// Hifive1 (+ revB)
// - Red   = Pin 22  (PWM1_3 O)
// - Green = Pin 19  (PWM1_1 O)
// - Blue  = Pin 21  (PWM1_2 O)
#define SB_RED_LED 0x00400000
#define SB_BLUE_LED 0x00200000
#define SB_GREEN_LED 0x00080000

void setup_sb_gpio();
void setup_sb_pwm();
int set_sb_led(int color, int state);
void run_super_blink();
