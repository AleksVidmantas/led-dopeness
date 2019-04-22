#include "PerlinPattern.h"
#define NUM_LEDS 450

CRGB leds[NUM_LEDS];
PerlinPattern p;

uint8_t colors[] = {
  0,  //red
  85, //green
  170 //blue
};

void setup() {
  delay(3000);
  LEDS.addLeds<WS2812B,3,GRB>(leds,NUM_LEDS);
  p.initialize(colors, 3);
  p.setResolution(20);
}

void loop() {
  p.stepTime(5);
  p.showPattern(leds, NUM_LEDS, 0);
  LEDS.show();
}
