#ifndef IPATTERN_H
#define PATTERN_H

#include <FastLED.h>

class IPattern {
public:
  // colors are a list of hues
  virtual void initialize(uint8_t * colors, uint8_t ncolors) = 0;
  virtual void showPattern(CRGB * leds, short nleds, short start = 0) = 0;
};

#endif
