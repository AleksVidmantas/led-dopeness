#include "Transform.h"

BrightnessTransform::BrightnessTransform(byte(* tf)(byte)){
    this->tf = tf;
}

void BrightnessTransform::operator()(CHSV * leds, short len){
    for(short i = 0; i < len; i++){
        leds[i].val = this->tf(leds[i].val);
    }
}

HueTransform::HueTransform(byte(* tf)(byte)){
    this->tf = tf;
}

void HueTransform::operator()(CHSV * leds, short len){
    for(short i = 0; i < len; i++){
        leds[i].val = this->tf(leds[i].val);
    }
}