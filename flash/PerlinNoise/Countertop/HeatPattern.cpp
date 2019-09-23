#include "HeatPattern.h"

#define DIFFUSION 1.05
#define SPARK_RATE 65535// measured as fraction of 65535

void HeatPattern::initialize(uint8_t * colors, uint8_t ncolors) {
    this->colors = colors;
    this->numColors = ncolors;
}

void HeatPattern::showPattern(CRGB * leds, short len, short start) {
    for(int i = 0; i < len; i++){
        // *shrug emoticon*
    }
}

void HeatPattern::stepTime(uint8_t dt, CRGB * leds, short len, CRGB * buffer, short start){
    for(int i = start + 1; i < (start + len) - 1; i++){
        //Heat equation: del(u) / del(t) = k * del2(u) / del(x2)
        //tl;dr difference of the averages of the neighbors to the value
        short rateRed = (leds[i-1].r - leds[i].r) + (leds[i+1].r - leds[i].r);
        short rateBlue = (leds[i-1].b - leds[i].b) + (leds[i+1].b - leds[i].b);
        short rateGreen = (leds[i-1].g - leds[i].g) + (leds[i+1].g - leds[i].g);
        buffer[i].r = max(0, buffer[i].r + (rateRed / 3) - 1);
        buffer[i].g = max(0, buffer[i].g + (rateGreen / 3) - 1);
        buffer[i].b = max(0, buffer[i].b + (rateBlue / 3) - 1);
        // buffer[i] *= DIFFUSION;
    }
    for(int i = start; i < (start + len); i++){
        leds[i] = buffer[i];
    }
    uint16_t randNumber = random16();
    uint8_t spark = randNumber >> 8; //high byte
    uint8_t index = randNumber & 0x00FF; //low byte

    if(spark < SPARK_RATE){
        short ledIndex = map((long)index, 0, 256, 0, len);
        uint8_t colorIndex = random8() % numColors;
        leds[ledIndex].setHSV(colors[colorIndex], 255, 255);
    }
}
