#include "led_color_cycle.h"
#include "common/common.h"
#include "platform.h"
#include <stdio.h>

// Do not set this to high, it may damage your eyes or your LED

// Simple variables for LEDs, buttons, etc.

volatile unsigned int* const g_pwm1 = (unsigned int*)PWM1_BASE_ADDR;
volatile unsigned int* const g_pwm1_s = (unsigned int*)(PWM1_BASE_ADDR + PWM_S);
volatile unsigned int* const g_pwm1_count = (unsigned int*)(PWM1_BASE_ADDR + PWM_COUNT);
volatile unsigned int* const g_pwm_cmp0 = (unsigned int*)(PWM1_BASE_ADDR + PWM_CMP0);
volatile unsigned int* const g_pwm_red = (unsigned int*)(PWM1_BASE_ADDR + PWM_CMP3);
volatile unsigned int* const g_pwm_green = (unsigned int*)(PWM1_BASE_ADDR + PWM_CMP1);
volatile unsigned int* const g_pwm_blue = (unsigned int*)(PWM1_BASE_ADDR + PWM_CMP2);

void setup_pwm()
{
    // reset counters
    *g_pwm1_count = 0x00;
    *g_pwm1_s = 0x00;

    // define cycle length
    *g_pwm_cmp0 = 0xff;

    *g_pwm1 = PWM_CFG_ENALWAYS | PWM_CFG_ONESHOT

        | PWM_CFG_ZEROCMP

        | PWM_CFG_DEGLITCH;
}

void pwm_dimm(uint8_t const red, uint8_t const green, uint8_t const blue)
{
    *g_pwm_red = red;
    *g_pwm_green = green;
    *g_pwm_blue = blue;
}

int run_led_color_cycle()
{
    // Keep directly track of current state
    uint8_t state = 0, red = 0, green = 0, blue = 0;

    printf("\n  hello led_color_cycle!\n");

    setup_lcc_gpio();

    setup_pwm();

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

        pwm_dimm(red, green, blue);

        delay(COMMON_DELAY);
    }

    return 0;
}
