#include "PerlinOperators.h"

PerlinHue::PerlinHue(short resolution, byte timeStep) {
  this->resolution = resolution;
  this->timeStep = timeStep;
  this->nOffset = random8();
}

void PerlinHue::operator()(CHSV * leds, short len){
    for(int i = 0; i < len; i++) {
        int ioffset = resolution * i + nOffset;
        leds[i].hue = inoise8(ioffset, timeCount);
    }
    timeCount += timeStep;
}

PerlinBrightness::PerlinBrightness(short resolution, byte timeStep, byte order){
  this->resolution = resolution;
  this->timeStep = timeStep;
  this->order = order;
  this->nOffset = random16() >> 8;
}

void PerlinBrightness::operator()(CHSV * leds, short len){
      for(int i = 0; i < len; i++) {
        int ioffset = resolution * i + nOffset;
        uint8_t brightnessValue = inoise8(ioffset, timeCount); //*.2 for a nightlight, @Aleks Vidmantas
        short val = (brightnessValue * brightnessValue) / 256;
//        for(byte i = 1; i < order; i++){
//          val *= brightnessValue;
//          val /= 256;
//        }
        leds[i].val = val;
    }
    timeCount += timeStep;
}
