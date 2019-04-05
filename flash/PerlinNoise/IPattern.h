#ifndef IPATTERN_H
#define PATTERN_H

#include <FastLED.h>

class IPattern {
public:
  virtual void initialize(CRGB * colors, int ncolors) = 0;
  virtual void showPattern(CRGB * leds, short nleds, short start = 0) = 0;
};

#endif
