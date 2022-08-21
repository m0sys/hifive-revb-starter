#include "led_color_cycle.h"
#include "../common/common.h"
#include <stdio.h>

int run_led_color_cycle()
{
    // Keep directly track of current state
    uint8_t state = 0, red = 0, green = 0, blue = 0;

    printf("\n  hello led_color_cycle!\n");

    setup_lcc_gpio();
    setup_lcc_pwm();

    while (1) {
        // calculate next color state
        switch (state) {
        case 0: // r: 00, g: 00, b: 00
            red += 1;
            if (red == LCC_LED_MAX_BRIGHTNESS) {
                state = 1;
            }
            break;

        case 1: // r: ff, g: 00, b: 00
            green += 1;
            if (green == LCC_LED_MAX_BRIGHTNESS) {
                state = 2;
            }
            break;

        case 2: // r: ff, g: ff, b: 00
            red -= 1;
            blue += 1;
            if (blue == LCC_LED_MAX_BRIGHTNESS) {
                state = 3;
            }
            break;

        case 3: // r: 00, g: ff, b: ff
            green -= 1;
            red += 1;
            if (red == LCC_LED_MAX_BRIGHTNESS) {
                state = 4;
            }
            break;

        case 4: // r: ff, g: 00, b: ff
            blue -= 1;
            green += 1;
            if (green == LCC_LED_MAX_BRIGHTNESS) {
                state = 2;
            }
            break;

        default:
            red = 0;
            green = 0;
            blue = 0;
            state = 0;
        }

        dimm_pwm(red, green, blue);
        delay(10);
    }

    return 0;
}
