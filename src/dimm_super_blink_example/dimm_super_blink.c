#include "dimm_super_blink.h"
#include "../common/common.h"
#include <stdio.h>

int run_dimm_super_blink()
{
    uint8_t state = 0, red = 0, green = 0, blue = 0, white = 0;
    setup_dsb_gpio();
    setup_dsb_pwm();

    while (1) {
        switch (state) {
        case 0:
            dimm_pwm(red, 0, 0);
            red = (red + 1) % DSB_LED_MAX_BRIGHTNESS;
            if (red == 0)
                state = 1;
            break;

        case 1:
            dimm_pwm(0, green, 0);
            green = (green + 1) % DSB_LED_MAX_BRIGHTNESS;
            if (green == 0)
                state = 2;
            break;

        case 2:
            dimm_pwm(0, 0, blue);
            blue = (blue + 1) % DSB_LED_MAX_BRIGHTNESS;
            if (blue == 0)
                state = 0;
            break;

        default:
            dimm_pwm(white, white, white);
            white = (white + 1) % DSB_LED_MAX_BRIGHTNESS;
            if (white == 0)
                state = 0;
            break;
        }

        delay(COMMON_DELAY);
    }
}
