
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 300

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
//#define CLzsOCK_PIN 13
CRGB leds[NUM_LEDS];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  CRGB leds[NUM_LEDS];
}


int i = 0;
void loop() {
  direct_brightness(leds, i);
  i++;
  //delay(13);

}


int creep_i = 0;
void creep(CRGB *leds){
  for(int i = 0; i < NUM_LEDS; i++){
    
  }
}


void direct_brightness(CRGB *leds, int str) {

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(triwave8(i)+str, 0, sin8(i+str)); //leds[i] = CRGB(sin8(i+str), 0, triwave8(i)+str); I kinda lucked out 
    leds[i].fadeLightBy(triwave8(i)+str);
    //Serial.println(sin8(i) + str+1);
  }
  //FastLED.setBrightness(str);
  FastLED.show();
}
