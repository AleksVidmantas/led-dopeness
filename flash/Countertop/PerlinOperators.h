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
  PerlinBrightness(short res, byte ts);
  void operator()(CHSV * leds, short len) override;
private:
  short resolution;
  byte timeStep, nOffset;
  uint16_t timeCount = 0;
};

class PerlinSaturation : public LedOperator {
public:
  PerlinSaturation(short res, byte ts);
  void operator()(CHSV * leds, short len) override;
private:
  short resolution;
  short timeStep, nOffset;
  uint16_t timeCount = 0;
};

#endif
