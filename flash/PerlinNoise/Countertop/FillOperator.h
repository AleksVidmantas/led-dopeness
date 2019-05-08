#ifndef FILL_OPERATOR_H
#define FILL_OPERATOR_H

#include "LedOperator.h"

class FillOperator : public LedOperator{
public:
    FillOperator(CHSV fill);
    operator()(CHSV * leds, short len) override;
private:
    CHSV fill;
};

#endif