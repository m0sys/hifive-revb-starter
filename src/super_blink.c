#include "super_blink.h"
#include <stdio.h>

int main()
{
    int error = 0;
    int led_num = 0;
    int colors[NUM_LEDS] = { RED_LED, GREEN_LED, BLUE_LED };

    setup_gpio();
    setup_pwm();

    // set_led(colors[led_num], ON);
    // set_led(colors[led_num + 1], ON);
    // set_led(colors[led_num + 2], ON);
    while (!error) {
        set_led(colors[led_num], ON);
        delay(DELAY);
        error = set_led(colors[led_num++], OFF);
        delay(DELAY);
        if (led_num >= NUM_LEDS)
            led_num = 0;
    }
}
