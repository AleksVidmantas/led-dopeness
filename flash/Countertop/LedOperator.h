#ifndef LED_OPERATOR_H
#define LED_OPERATOR_H

#include <FastLED.h>

class LedOperator{
public:
  virtual void operator()(CHSV * leds, short len){ leds[0].sat = 255; leds[0].val = 255; }
  virtual void go(CHSV * leds, short len){ this->operator()(leds, len); }
  LedOperator * operator>>(LedOperator & next);
  LedOperator * operator>>(LedOperator * next);
};

class LayerOperator : public LedOperator{
public:
  LayerOperator(LedOperator * a, LedOperator * b);
  void operator()(CHSV * leds, short len) override;
private:
  LedOperator * first;
  LedOperator * next;
};

#endif
