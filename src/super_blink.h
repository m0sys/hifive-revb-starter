#define DELAY 200
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03

// Pin 22 (PWM1_3 O) - RED
// Pin 19 (PWM1_1 O) - GREEN
// Pin 21 (PWM1_2 O) - BLUE
// #define RED_LED 0x080000
// #define BLUE_LED 0x400000
// #define GREEN_LED 0x600000
// //! Hifive1 (+ revB)
// //! - Red = Pin 22
// //! - Green = Pin 19
// //! - Blue = Pin 21
// #define RED_LED   0x00200000
// #define BLUE_LED  0x00400000
// #define GREEN_LED 0x00600000
#define RED_LED 0x00400000
#define BLUE_LED 0x00200000
#define GREEN_LED 0x00080000

void setup_gpio();
int set_led(int color, int state);
void delay(int milliseconds);
