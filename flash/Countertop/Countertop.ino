#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#include "FillOperator.h"
#include "LedMap.h"

CHSV ledColors[TRIANGLE_LED_COUNT];
CRGB ledRaw[TRIANGLE_LED_COUNT];

// PerlinHue pHue(20, 5);
FillOperator fOp(CHSV(36, 255, 255));
PerlinBrightness pBri(40, 5, 3);
LayerOperator perlinAll(&fOp, &pBri);


void setup() {
  FastLED.addLeds<WS2812B,3,GRB>(ledRaw, TRIANGLE_LED_COUNT);
//  pp.initialize(convertedColors, numColors);
//  pp.setResolution(20);
}

void loop() {
  delay(1);
  perlinAll.go(ledColors + TRIANGLE_LED_TRIANGLE_START, TRIANGLE_LED_TRIANGLE_LEN);
  hsv2rgb_spectrum(ledColors, ledRaw, TRIANGLE_LED_COUNT);
  FastLED.show();
}
