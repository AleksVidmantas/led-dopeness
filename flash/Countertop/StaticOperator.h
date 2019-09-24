#ifndef STATIC_OPERATOR_H
#define STATIC_OPERATOR_H

#include "LedOperator.h"

class StaticOperator : public LedOperator{
public:
    StaticOperator(CHSV * pattern, int patternLen);
    void operator()(CHSV * leds, short len) override;
private:
    CHSV * pattern;
    int patternLen;
};

#endif