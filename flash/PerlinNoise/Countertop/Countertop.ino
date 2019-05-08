#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#include "FillOperator.h"
#include "Transform.h"
#define LEDS_UNDER_COUNTER 185
#define LEDS_ABOVE_COUNTER 115 //300 - 185
#define LEDS_AROUND_TOP 135
#define NUM_LEDS 750

CHSV ledColors[NUM_LEDS];
CRGB leds[NUM_LEDS];

byte tfCube(byte in){
  short s_in = in;
  s_in *= in;
  s_in /= 255;
  s_in *= in;
  s_in /= 255;
  return (byte)s_in;
}

FillOperator base(CHSV(255, 255, 255));
PerlinHue pHue(20, 5);
LayerOperator l1(&base, &pHue);
PerlinBrightness pBri(40, 5, 3);
BrightnessTransform bTf(tfCube);
LayerOperator perlinAll(&pHue, &pBri);
LayerOperator finalLed(&perlinAll, &bTf);

void setup() {
}

void loop() {
  delay(1);
  finalLed(ledColors, NUM_LEDS);
  hsv2rgb_spectrum(ledColors, leds, NUM_LEDS);
  FastLED.show();
}
