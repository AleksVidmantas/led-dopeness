#include FillOperator.h

FillOperator::FillOperator(CHSV fill){
    this->fill = fill;
}

void FillOperator::operator()(CHSV * leds, short len){
    for(short i = 0; i < len; i++){
        leds[i] = fill;
    }
}