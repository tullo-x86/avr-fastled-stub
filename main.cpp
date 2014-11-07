#include "FastLED/FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 64 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 10
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

long unsigned int us = 0;
long unsigned int micros() {
  return ++us;
}

uint32_t ms = 0;
uint32_t millis() {
  return ++ms;
}

void delay(long unsigned int us) {}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }

int main() { 
	LEDS.addLeds<NEOPIXEL,DATA_PIN>(leds,NUM_LEDS);
	LEDS.setBrightness(84);
	
	uint8_t hue = 0;
	while(1)
	{
	  // First slide the led in one direction
	  for(int i = 0; i < NUM_LEDS; i++) {
		  // Set the i'th led to red 
		  leds[i] = CHSV(hue++, 255, 255);
		  // Show the leds
		  FastLED.show(); 
		  // now that we've shown the leds, reset the i'th led to black
		  // leds[i] = CRGB::Black;
		  fadeall();
		  // Wait a little bit before we loop around and do it again
		  delay(10);
	  }

	  // Now go in the other direction.  
	  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
		  // Set the i'th led to red 
		  leds[i] = CHSV(hue++, 255, 255);
		  // Show the leds
		  FastLED.show();
		  // now that we've shown the leds, reset the i'th led to black
		  // leds[i] = CRGB::Black;
		  fadeall();
		  // Wait a little bit before we loop around and do it again
		  delay(10);
	  }
	}
	return 0;
}
