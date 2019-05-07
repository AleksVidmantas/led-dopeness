#include "PerlinPattern.h"
#include "heatPattern.h"
#include "PerlinOperators.h"
#include "Transform.h"
#define LEDS_UNDER_COUNTER 185
#define LEDS_ABOVE_COUNTER 115 //300 - 185
#define LEDS_AROUND_TOP 135
#define NUM_LEDS 750

CHSV ledColors[NUM_LEDS];
CRGB leds[NUM_LEDS];

byte tfCube(byte in){
  short ins = in;
  ins *= in;
  ins /= 255;
  ins *= in;
  ins /= 255;
  return (byte)ins;
}

PerlinHue pHue(20, 5);
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
