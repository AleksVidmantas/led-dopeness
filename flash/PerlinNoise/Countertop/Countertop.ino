#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#define LEDS_UNDER_COUNTER 185
#define LEDS_ABOVE_COUNTER 115 //300 - 185
#define LEDS_AROUND_TOP 135
#define NUM_LEDS 750

CHSV ledColors[NUM_LEDS];
CRGB leds[NUM_LEDS];
//CRGB buffer[LEDS_UNDER_COUNTER];
HeatPattern hp;
PerlinPattern pp;

PerlinHue pHue(20, 5);
PerlinBrightness pBri(40, 5, 3);
LayerOperator perlinAll(&pHue, &pBri);

#define numColors 255
//uint16_t colors[numColors]; //= {
//  0,  //red
//   300, //purple
//   29, //orange
//  // 85, //green
//  170, //mint
//  240 //blue
//};
uint8_t convertedColors[numColors];

void setup() {
//  Serial.begin(9600);
//  Serial.println("Startin...");
//  for(uint16_t i = 0; i < numColors; i++){
//    colors[i] = i;
//  }
//  Serial.println("Initialized hue spectrum");
  for(uint8_t i = 0; i < numColors; i++){
    //fastled uses 0..255, which is different from everything else
    convertedColors[i] = i;
  }
//  Serial.println("Converted colors");
  FastLED.addLeds<WS2812B,3,GRB>(leds,NUM_LEDS);
//  hp.initialize(convertedColors, numColors);
  pp.initialize(convertedColors, numColors);
  pp.setResolution(20);
}

void loop() {
//  delay(50);
  delay(1);
  //first arg of stepTime is currently unused
//  hp.stepTime(0, leds, NUM_LEDS, buffer);
//  pp.showPattern(leds, NUM_LEDS, 0);
//  pp.stepTime(1);
//  pHue->go(ledColors, NUM_LEDS);
//  pBri->go(ledColors, NUM_LEDS);
  perlinAll.go(ledColors, NUM_LEDS);
  hsv2rgb_spectrum(ledColors, leds, NUM_LEDS);
  FastLED.show();
}
