#ifndef KERNEL_OPERATOR_H
#define KERNEL_OPERATOR_H

#include "LedOperator.h"

//Warning: ignores edges that the kernel cannot reach.
//Might want to fill those parts.
class KernelOperator : public LedOperator{
public:
    KernelOperator(byte * kernel, byte len);
    ~KernelOperator();
    void operator()(CHSV * leds, short len);
private:
    void addToKernelBuffer(CHSV color);
    CHSV getFromKernelBuffer(int idx);
    byte * kernel;
    byte kernelLen;
    CHSV * kernelBuffer; //complex algorithms ahead
    byte kernelBufferStart;
    byte kernelBufferLen;
};

#endif