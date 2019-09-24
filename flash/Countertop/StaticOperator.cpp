#include "StaticOperator.h"

StaticOperator::StaticOperator(CHSV * pattern, int patternLen){
    this->pattern = pattern;
    this->patternLen = patternLen;
}

void StaticOperator::operator()(CHSV * leds, short len){
    int pIdx = 0;
    for(int i = 0; i < len; i++){
        leds[i] = pattern[pIdx];
        pIdx++;
        if(pIdx == patternLen)
            pIdx = 0;
    }
}