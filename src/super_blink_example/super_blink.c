#include "super_blink.h"
#include "../common/common.h"
#include <stdio.h>

void run_super_blink()
{
    int error = 0;
    int led_num = 0;
    int colors[SB_NUM_LEDS] = { SB_RED_LED, SB_GREEN_LED, SB_BLUE_LED };

    setup_sb_gpio();
    // setup_sb_pwm();

    // set_led(colors[led_num], ON);
    // set_led(colors[led_num + 1], ON);
    // set_led(colors[led_num + 2], ON);
    while (!error) {
        set_sb_led(colors[led_num], SB_ON);
        delay(COMMON_DELAY);
        error = set_sb_led(colors[led_num++], SB_OFF);
        delay(COMMON_DELAY);
        if (led_num >= SB_NUM_LEDS)
            led_num = 0;
    }
}
