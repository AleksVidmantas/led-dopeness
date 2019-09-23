#ifndef PERLIN_OPERATORS_H
#define PERLIN_OPERATORS_H

#include "LedOperator.h"

class PerlinHue : public LedOperator {
public:
  PerlinHue(short res, byte ts);
  void operator()(CHSV * leds, short len) override;
private:
  short resolution;
  byte timeStep, nOffset;
  uint16_t timeCount = 0;
};

class PerlinBrightness : public LedOperator {
public:
  PerlinBrightness(short res, byte ts, byte order);
  void operator()(CHSV * leds, short len) override;
private:
  short resolution;
  byte timeStep, order, nOffset;
  uint16_t timeCount = 0;
};

#endif
