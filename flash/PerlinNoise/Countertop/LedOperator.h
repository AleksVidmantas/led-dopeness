#ifndef LED_OPERATOR_H
#define LED_OPERATOR_H

#include <FastLED.h>

class LedOperator{
public:
  virtual void operator()(CHSV * leds, short len) = 0;
  void go(CHSV * leds, short len){ this->operator()(leds, len); }
};

class LayerOperator : public LedOperator{
public:
  LayerOperator(LedOperator * first, LedOperator * next);
  void operator()(CHSV * leds, short len) override;
private:
  LedOperator * first;
  LedOperator * next;
};

#endif
