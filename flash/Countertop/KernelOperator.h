#ifndef KERNEL_OPERATOR_H
#define KERNEL_OPERATOR_H

class KernelOperator : public LedOperator{
public:
    KernelOperator(byte * kernel, byte len);
    ~KernelOperator();
    void operator()(CHSV * leds, short len);
private:
    byte * kernel;
    static CHSV * buffer;
};

#endif