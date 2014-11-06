#include "FastLED/FastLED.h"

#define NUM_LEDS 8
CRGB buffer[NUM_LEDS];

int main() {
  FastLED::addLeds<NEOPIXEL, 10>(buffer, NUM_LEDS);
  return 0;
}
