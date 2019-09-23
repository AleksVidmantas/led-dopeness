#include "LedOperator.h"

LedOperator * LedOperator::operator>>(LedOperator & next){
//  return new LayerOperator(this, next);
  return NULL;
}

LedOperator * LedOperator::operator>>(LedOperator * next){
  return new LayerOperator(this, next);
}

LayerOperator::LayerOperator(LedOperator * a, LedOperator * b){
  this->first = a;
  this->next = b;
}

void LayerOperator::operator()(CHSV * leds, short len){
  this->first->go(leds, len);
  this->next->go(leds, len);
}
