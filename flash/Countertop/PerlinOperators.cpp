#include "PerlinOperators.h"

PerlinHue::PerlinHue(short resolution, byte timeStep) {
  this->resolution = resolution;
  this->timeStep = timeStep;
  this->nOffset = random8();
}

void PerlinHue::operator()(CHSV * leds, short len){
  for(int i = 0; i < len; i++) {
      int ioffset = resolution * i + nOffset;
      leds[i].hue = ease8InOutApprox(inoise8(ioffset, timeCount));
  }
  timeCount += timeStep;
}

PerlinBrightness::PerlinBrightness(short resolution, byte timeStep){
  this->resolution = resolution;
  this->timeStep = timeStep;
  this->nOffset = random16() << 8;
}

void PerlinBrightness::operator()(CHSV * leds, short len){
    for(int i = 0; i < len; i++) {
      int ioffset = resolution * i + nOffset;
      leds[i].val = ease8InOutApprox(scale8(leds[i].val, inoise8(ioffset, timeCount)));
  }
  timeCount += timeStep;
}

PerlinSaturation::PerlinSaturation(short res, byte ts){
  this->resolution = res;
  this->timeStep = timeStep;
  this->nOffset = random16() >> 4;
}

void PerlinSaturation::operator()(CHSV * leds, short len){
  for(int i = 0; i < len; i++) {
    int ioffset = resolution * i + nOffset;
    leds[i].sat = scale8(leds[i].sat, inoise8(ioffset, timeCount)); //*.2 for a nightlight, @Aleks Vidmantas
  }
  timeCount += timeStep;
}