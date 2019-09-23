#include <FastLED.h>

#define NUM_LEDS 300 //calibrate one strip at a time
#define PWM 3

int idx;
CRGB leds[NUM_LEDS];

void setup(){
    idx = 0;
    FastLED.addLeds<WS2812B, PWM, GRB>(leds, NUM_LEDS);
}

void loop(){
    int shift = Serial.parseInt();

    leds[idx] = CRGB(0, 0, 0);
    idx += shift;
    leds[idx] = CRGB(255, 255, 255);
    FastLED.show();

    if(idx >= NUM_LEDS)
        idx = NUM_LEDS - 1;
    else if(idx < 0)
        idx = 0;
    
    Serial.print("Cursor now at: ");
    Serial.println(idx, DEC);
}
