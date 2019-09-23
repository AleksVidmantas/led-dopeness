#ifndef TOGGLE_OPERATOR_H
#define TOGGLE_OPERATOR_H

#include "LedOperator.h"

class ToggleFull : public LedOperator{
public:
    ToggleFull(LedOperator* a, LedOperator* b, int cycles);
    ToggleFull(LedOperator* a, LedOperator* b, int cyclesA, int cyclesB);
    void operator()(CHSV * leds, short len) override;
private:
    LedOperator *a, *b;
    int cyclesA;
    int cyclesTotal;
    int counter;
};

#endif
