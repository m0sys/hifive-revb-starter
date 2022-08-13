#include "super_blink.h"
#include <stdio.h>

void delay(int milliseconds) { return; }

void setup_gpio() { return; }

int set_led(int color, int state) { return 0; }

int main()
{
    int error = 0;
    int led_num = 0;
    int colors[NUM_LEDS] = { RED_LED, GREEN_LED, BLUE_LED };

    setup_gpio();

    while (!error) {
        set_led(colors[led_num], ON);
        delay(DELAY);
        error = set_led(colors[led_num], OFF);
        delay(DELAY);
        if (led_num >= NUM_LEDS)
            led_num = 0;
    }
}
