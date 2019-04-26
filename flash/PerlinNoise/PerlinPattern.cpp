#include "PerlinPattern.h"
#include <stdlib.h>

void PerlinPattern::initialize(uint8_t * colors, uint8_t ncolors){
    currentTime = 0;
    colorValue = 0;
    timeValue = 0;
    resolution = 20; //normal starting number
    this->colors = colors;
    this->numColors = ncolors;
}

void PerlinPattern::showPattern(CRGB * leds, short len, short start){
    for(int i = 0; i < len; i++) {
        int ioffset = resolution * i;
        uint8_t brightnessValue = inoise8(ioffset, currentTime);
        uint8_t color = inoise8(resolution * (len - i), colorValue);
        uint8_t colorIndex = map((long)color, 0, 256, 0, (long)numColors);
        short val = (brightnessValue * brightnessValue) / 255;
        // short val2 = val * val / 255;
        leds[i+start].setHSV(colors[colorIndex], 255, val);
    }
}

void PerlinPattern::stepTime(uint8_t dt){
    timeValue += dt;
    int deltaTimeTransformed = inoise8(((int)timeValue) << 8) / 16;
    currentTime += deltaTimeTransformed;
    colorValue += deltaTimeTransformed;
}

void PerlinPattern::setResolution(short resolution){
    this->resolution = resolution;
}