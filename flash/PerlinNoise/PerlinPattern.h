#ifndef PERLIN_PATTERN_H
#define PERLIN_PATTERN_H

#include "IPattern.h"

struct Vector2_float{
public:
  float x, y; 
};

class PerlinPattern : IPattern {
public:
  void initialize(CRGB * colors, int ncolors) override;
  void showPattern(CRGB * leds, short len, short start = 0) override;
  void stepTime(uint8_t dt);
  void setResolution(short resolution);
private:
  short currentTime, resolution;
};
#endif
