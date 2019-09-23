#include "LedOperator.h"

LayerOperator::LayerOperator(LedOperator * a, LedOperator * b){
  this->first = a;
  this->next = b;
}

void LayerOperator::operator()(CHSV * leds, short len){
  this->first->go(leds, len);
  this->next->go(leds, len);
}
