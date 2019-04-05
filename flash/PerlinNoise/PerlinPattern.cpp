#include "PerlinPattern.h"
#include <stdlib.h>

void PerlinPattern::initialize(CRGB * colors, int ncolors){
    currentTime = 0;
    resolution = 20; //normal starting number
}

void PerlinPattern::showPattern(CRGB * leds, short len, short start){
    for(int i = 0; i < len; i++) {
        int ioffset = resolution * i;
        uint8_t noise = inoise8(ioffset, currentTime);
        short val = (noise * noise) / 256;
        short val2 = val * val / 256;
        leds[i+start].b = val2;
    }
}

void PerlinPattern::stepTime(uint8_t dt){
    currentTime += dt;
}

void PerlinPattern::setResolution(short resolution){
    this->resolution = resolution;
}