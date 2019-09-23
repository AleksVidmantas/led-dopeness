#ifndef LED_OPERATOR_H
#define LED_OPERATOR_H

#include <FastLED.h>

class LedOperator{
public:
  /**
   * @brief Apply the operator to the given LEDs
   * 
   * @param leds LEDs to operate on
   * @param len Number of leds to operate on
   */
  virtual void operator()(CHSV * leds, short len) = 0;

  /**
   * @brief Named function that invokes operator() for convenience
   * 
   * @param leds LEDs to operate on
   * @param len Number of leds to operate on
   */
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
