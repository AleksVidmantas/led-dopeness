#include "RotateOperator.h"

RotateOperator::RotateOperator(int period, int maxBufSize){
    this->period = period;
    this->offset = 0;
    this->periodCounter = 0;
    this->maxBufSize = maxBufSize;
}

void RotateOperator::operator()(CHSV * leds, short len){
    CHSV * buf = (CHSV *)malloc(sizeof(CHSV) * offset);

    //copy last offset elements to buffer
    for(int i = 0; i < offset; i++){
        buf[i] = leds[len - offset + i];
    }

    //shift remaining elements forwards
    for(int i = len - offset - 1; i >= 0; i--){
        leds[i + offset] = leds[i];
    }

    //paste array elements we copied back into the front of the led array
    for(int i = 0; i < offset; i++){
        leds[i] = buf[i];
    }

    //step time forwards, wrapping where necessary
    if(++periodCounter > period){
        if(++offset >= maxBufSize){
            offset = 0;
        }
        periodCounter = 0;
    }
}