#define DELAY 200
#define ON 0x01
#define OFF 0x00
#define NUM_LEDS 0x03

// Hifive1 (+ revB)
// - Red   = Pin 22  (PWM1_3 O)
// - Green = Pin 19  (PWM1_1 O)
// - Blue  = Pin 21  (PWM1_2 O)
#define RED_LED 0x00400000
#define BLUE_LED 0x00200000
#define GREEN_LED 0x00080000

void setup_gpio();
int set_led(int color, int state);
void delay(int milliseconds);
