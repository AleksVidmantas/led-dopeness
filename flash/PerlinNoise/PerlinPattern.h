#ifndef PERLIN_PATTERN_H
#define PERLIN_PATTERN_H

#include "IPattern.h"

struct Vector2_float{
public:
  float x, y; 
};

class PerlinPattern : IPattern {
public:
  void initialize(uint8_t * colors, uint8_t ncolors) override;
  void showPattern(CRGB * leds, short len, short start = 0) override;
  void stepTime(uint8_t dt);
  void setResolution(short resolution);
private:
  short currentTime, resolution, colorValue, timeValue;
  uint8_t * colors;
  uint8_t numColors;
};
#endif
