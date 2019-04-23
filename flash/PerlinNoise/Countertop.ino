#include "PerlinPattern.h"
#include "HeatPattern.h"
#define LEDS_UNDER_COUNTER 185
#define LEDS_ABOVE_COUNTER 115 //300 - 185
#define LEDS_AROUND_TOP 150
// can't do all 400 because of memory constraints
#define NUM_LEDS 300

CRGB leds[NUM_LEDS];
CRGB buffer[LEDS_UNDER_COUNTER];
HeatPattern hp;
PerlinPattern pp;

#define numColors 3
uint16_t colors[numColors] = {
  0,  //red
  // 300, //purple
  // 29, //orange
  // 85, //green
  170, //mint
  240 //blue
};
uint8_t convertedColors[numColors];

void setup() {
  for(uint8_t i = 0; i < numColors; i++){
    //fastled uses 0..255, which is different from everything else
    convertedColors[i] = map(colors[i], 0, 360, 0, 255);
  }
  LEDS.addLeds<WS2812B,3,GRB>(leds,NUM_LEDS);
  hp.initialize(convertedColors, numColors);
  pp.initialize(convertedColors, numColors);
  pp.setResolution(20);
}

void loop() {
  delay(50);
  //first arg of stepTime is currently unused
  hp.stepTime(0, leds, NUM_LEDS, buffer);
  pp.showPattern(leds, LEDS_ABOVE_COUNTER, LEDS_UNDER_COUNTER);
  pp.stepTime(5);
  LEDS.show();
}
