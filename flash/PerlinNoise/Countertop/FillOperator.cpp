#include "FillOperator.h"

FillOperator::FillOperator(CHSV fill){
    this->fill = fill;
}

void FillOperator::operator()(CHSV * leds, short len){
    fill_solid(leds, len, fill);
}