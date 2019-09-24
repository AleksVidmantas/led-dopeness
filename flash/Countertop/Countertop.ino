#include "Operators.h"
#include "LedMap.h"

CHSV ledColors[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];
CRGB ledRaw[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];

byte normsquare(byte val){
  short val_s = (short)val;
  return (byte)map(val_s * val_s / 256, 0, 64, 0, 128); //had to remap because base value was not 255
}

byte gaussianBlurKernel[5] = {
  16,
  32,
  159,
  32,
  16
};

CHSV goldPattern[5] = {
  CHSV(36, 255, 0),
  CHSV(36, 255, 0),
  CHSV(36, 255, 0),
  CHSV(36, 255, 90),
  CHSV(36, 255, 90)
};

StaticOperator pGold(goldPattern, 5);
RotateOperator rot(1, 5);
LayerOperator animatedTriangle(&pGold, &rot);
FillOperator fBlue(CHSV(170, 255, 64));
FillOperator fBlack(CHSV(0, 0, 0));
// ToggleFull tColor(&fGold, &fBlue, 30);
// KernelOperator kBlur(gaussianBlurKernel, 5);
//PerlinBrightness pBri(40, 5);
//LayerOperator pBlur(&pBri, &kBlur);
//BrightnessTransform bt(&normsquare);
//LayerOperator perlinColor(&pGold, &pBlur);
//LayerOperator perlinFull(&perlinColor, &bt);
// LayerOperator pBlur(&pGold, &kBlur);

void setup() {
  int total = 0;
  FastLED.addLeds<WS2812B,TRIANGLE_STRIP_PWM,GRB>(ledRaw, TRIANGLE_LED_COUNT);
  total += TRIANGLE_LED_COUNT;
  FastLED.addLeds<WS2812B,SHELF_STRIP_PWM, GRB>(ledRaw + total, SHELF_LED_COUNT);
  total += SHELF_LED_COUNT;
  FastLED.addLeds<WS2812B,CIELING_STRIP_PWM,GRB>(ledRaw + total, CIELING_LED_COUNT);
  total += CIELING_LED_COUNT;
  FastLED.addLeds<WS2812B,COUCH_STRIP_PWM,GRB>(ledRaw + total, COUCH_LED_COUNT);
//  pp.initialize(convertedColors, numColors);
//  pp.setResolution(20);
}

void loop() {
  delay(1);
  animatedTriangle.go(ledColors, 1200);
  fBlack.go(ledColors + TRIANGLE_HORIZONTAL_START, TRIANGLE_HORIZONTAL_LEN);
//  pGold.go(ledColors + TRIANGLE_COUNTER_START, TRIANGLE_COUNTER_LEN);
  hsv2rgb_spectrum(ledColors, ledRaw, TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT);
  FastLED.show();
}
