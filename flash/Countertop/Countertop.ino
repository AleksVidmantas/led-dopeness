#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#include "FillOperator.h"
#include "Transform.h"
#include "LedMap.h"

CHSV ledColors[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];
CRGB ledRaw[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];

byte normsquare(byte val){
  short val_s = (short)val;
  return (byte)(val * val / 256);
}

// PerlinHue pHue(20, 5);
FillOperator fOp(CHSV(36, 255, 255));
PerlinBrightness pBri(40, 5, 3);
BrightnessTransform bt(&normsquare);
LayerOperator perlinColor(&fOp, &pBri);
LayerOperator perlinAll(&perlinColor, &bt);

void setup() {
  FastLED.addLeds<WS2812B,TRIANGLE_STRIP_PWM,GRB>(ledRaw, TRIANGLE_LED_COUNT);
  FastLED.addLeds<WS2812B,SHELF_STRIP_PWM, GRB>(ledRaw + TRIANGLE_LED_COUNT, SHELF_LED_COUNT);
  FastLED.addLeds<WS2812B,CIELING_STRIP_PWM,GRB>(ledRaw + TRIANGLE_LED_COUNT + SHELF_LED_COUNT, CIELING_LED_COUNT);
  FastLED.addLeds<WS2812B,COUCH_STRIP_PWM,GRB>(ledRaw + TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT, COUCH_LED_COUNT);
//  pp.initialize(convertedColors, numColors);
//  pp.setResolution(20);
}

void loop() {
  delay(1);
  perlinAll.go(ledColors + TRIANGLE_TRIANGLE_START, TRIANGLE_TRIANGLE_LEN);
  hsv2rgb_spectrum(ledColors, ledRaw, TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT);
  FastLED.show();
}
