#ifndef HEATPATTERN_H
#define HEATPATTERN_H

#include "IPattern.h"

class HeatPattern : IPattern {
public:
    void initialize(uint8_t * colors, uint8_t ncolors) override;
    void showPattern(CRGB * leds, short len, short start = 0) override;
    void stepTime(uint8_t dt, CRGB * leds, short len, CRGB * buffer, short start = 0);
private:
    uint8_t * colors;
    uint8_t numColors;
    CRGB * buffer;
    uint16_t buflen;
};

#endif