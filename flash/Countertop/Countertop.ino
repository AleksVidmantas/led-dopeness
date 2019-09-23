#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#include "LedMap.h"

CHSV ledColors[TRIANGLE_LED_COUNT];
CRGB ledRaw[TRIANGLE_LED_COUNT];
// HeatPattern hp;
PerlinPattern pp;

PerlinHue pHue(20, 5);
PerlinBrightness pBri(40, 5, 3);
LayerOperator perlinAll(&pHue, &pBri);

#define numColors 1
uint16_t colors[numColors] = {
  // 0,  //red
  // 300, //purple
  // 29, //orange
  // 85, //green
  // 170, //mint
  // 240 //blue
  51 //GOLD BABY
};
uint8_t convertedColors[numColors];

void setup() {
  for(uint8_t i = 0; i < numColors; i++){
    //fastled uses 0..255, which is different from everything else
    convertedColors[i] = colors[i] * 255 / 360;
  }
  FastLED.addLeds<WS2812B,3,GRB>(ledRaw, TRIANGLE_LED_COUNT);
  pp.initialize(convertedColors, numColors);
  pp.setResolution(20);
}

void loop() {
  delay(1);
  perlinAll.go(ledColors + TRIANGLE_LED_TRIANGLE_START, TRIANGLE_LED_TRIANGLE_LEN);
  hsv2rgb_spectrum(ledColors, ledRaw, TRIANGLE_LED_COUNT);
  FastLED.show();
}
