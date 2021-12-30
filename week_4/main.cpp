#include "mbed_config.h"
#include "mbed-os/mbed.h"

const int SLEEP_TIME = 100;

DigitalOut led(LED1);
InterruptIn button(USER_BUTTON);
Timer timer;

// Blink mode, when true LED is blinking
volatile bool should_blink = true;

// Number of stable button readings needed
int bounce_count = 2;

// The window (in ms) within which multiple presses are seen as bounces
const int cooldown_time = 20;

// The time that a button press started (-1 if it hasn't happened)
int press_start = 0;

void handle_button_press() {
  int curr_time = timer.read_ms();

  if ((curr_time - press_start) < cooldown_time) {
    bounce_count--;
  } else {
    press_start = curr_time;
    should_blink = !should_blink;
  }

  if (bounce_count == 0) {
    should_blink = !should_blink;
    bounce_count = 5;
  }
}

int main() {
  // Start the timer
  timer.start();

  // attach an interrupt to the falling edge of the button press
  button.fall(&handle_button_press);

  while (1) {
    if (should_blink) {
      led = 1;
    }
    ThisThread::sleep_for(SLEEP_TIME);

    if (should_blink) {
      led = 0;
    }
    ThisThread::sleep_for(SLEEP_TIME);
  }
  return 0;
}
