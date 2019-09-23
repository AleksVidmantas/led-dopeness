#ifndef BRIGHTNESS_TRANSFORM_H
#define BRIGHTNESS_TRANSFORM_H

#include "LedOperator.h"

class BrightnessTransform : public LedOperator {
public:
    BrightnessTransform(byte (*tf)(byte in));
    void operator()(CHSV * leds, short len) override;
private:
    byte (*tf)(byte in);
};

class HueTransform : public LedOperator {
public:
    HueTransform(byte (*tf)(byte in));
    void operator()(CHSV * leds, short len) override;
private:
    byte (*tf)(byte in);
};

#endif