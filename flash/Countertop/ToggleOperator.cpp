#include "ToggleOperator.h"

ToggleFull::ToggleFull(LedOperator* a, LedOperator* b, int cyclesA, int cyclesB){
    this->cyclesA = cyclesA;
    this->cyclesTotal = cyclesA + cyclesB;
    this->a = a;
    this->b = b;
}

ToggleFull::ToggleFull(LedOperator *a, LedOperator *b, int cycles)
    : ToggleFull(a, b, cycles, cycles) {}

void ToggleFull::operator()(CHSV * leds, short len){
    if(counter < cyclesA)
        a->go(leds, len);
    else
        b->go(leds, len);
    
    counter++;

    if(counter == cyclesTotal)
        counter = 0;
}