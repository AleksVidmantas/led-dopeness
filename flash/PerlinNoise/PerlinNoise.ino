#include "PerlinPattern.h"
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
PerlinPattern p;

void setup() {
  delay(3000);
  LEDS.addLeds<WS2812B,3,GRB>(leds,NUM_LEDS);
  p.initialize(NULL, 0);
  p.setResolution(20);
}

void loop() {
  p.stepTime(5);
  p.showPattern(leds, 300, 0);
  LEDS.show();
}
