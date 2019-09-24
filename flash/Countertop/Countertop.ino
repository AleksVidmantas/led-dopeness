#include "Operators.h"
#include "LedMap.h"

CHSV ledColors[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];
CRGB ledRaw[TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT];

byte gaussianBlurKernel[5] = {
  16,
  32,
  159,
  32,
  16
};

CHSV goldPattern[7] = {
  CHSV(36, 255, 0),
  CHSV(36, 255, 0),
  CHSV(36, 255, 0),
  CHSV(36, 255, 0),  
  CHSV(36, 255, 70),
  CHSV(36, 255, 130),
  CHSV(36, 255, 70)
};

StaticOperator pGold(goldPattern, 7);
RotateOperator rot(1, 7);
LayerOperator animatedTriangle(&pGold, &rot);
FillOperator fWhite(CHSV(255, 255, 255));
FillOperator fBlack(CHSV(0, 0, 0));
PerlinHue pHue(20, 10);
PerlinBrightness pBri(10, 5);
LayerOperator pFull(&pHue, &pBri);
LayerOperator pFinal(&fWhite, &pFull);

void setup() {
  int total = 0;
  FastLED.addLeds<WS2812B,TRIANGLE_STRIP_PWM,GRB>(ledRaw, TRIANGLE_LED_COUNT);
  total += TRIANGLE_LED_COUNT;
  FastLED.addLeds<WS2812B,SHELF_STRIP_PWM, GRB>(ledRaw + total, SHELF_LED_COUNT);
  total += SHELF_LED_COUNT;
  FastLED.addLeds<WS2812B,CIELING_STRIP_PWM,GRB>(ledRaw + total, CIELING_LED_COUNT);
  total += CIELING_LED_COUNT;
  FastLED.addLeds<WS2812B,COUCH_STRIP_PWM,GRB>(ledRaw + total, COUCH_LED_COUNT);
}

void loop() {
  pFinal.go(ledColors, 1200);
  animatedTriangle.go(ledColors + TRIANGLE_TRIANGLE_START, TRIANGLE_TRIANGLE_LEN);
  fBlack.go(ledColors + TRIANGLE_HORIZONTAL_START, TRIANGLE_HORIZONTAL_LEN);
//  pGold.go(ledColors + TRIANGLE_COUNTER_START, TRIANGLE_COUNTER_LEN);
  hsv2rgb_rainbow(ledColors, ledRaw, TRIANGLE_LED_COUNT + SHELF_LED_COUNT + CIELING_LED_COUNT + COUCH_LED_COUNT);
  FastLED.show();
}
