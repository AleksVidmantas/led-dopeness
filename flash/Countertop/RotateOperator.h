#ifndef ROTATE_OPERATOR_H
#define ROTATE_OPERATOR_H

#include "LedOperator.h"

class RotateOperator : public LedOperator {
public:
    //MaxBufSize should be set to the length of your repeating
    //pattern for seamless animation
    RotateOperator(int period, int maxBufSize);
    void operator()(CHSV * leds, short len) override;
private:
    int offset;
    int periodCounter;
    int period;
    int maxBufSize;
};

#endif
