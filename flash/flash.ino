#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 150

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
//#define CLzsOCK_PIN 13

// Define the array of leds, function headers
//int ind = 0;
int ind2 = 0;
CRGB leds[NUM_LEDS];
void flash(CRGB *leds);
int func_2_run = 0;
int arr[3] = {0, 0, 0};
int count = 0;


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.println("<Arduino is ready>");
}
int str2 = 0;
int func_2_run_old = -1;

int curVal = 0;
int codeInd = 0;
char code [16];

void (*pattern)(CRGB *leds) = &chase; //Hella important, minimizes cost and is the function to run

int incomingByte = 0;   // for incoming serial data
char ar[6]; //tmp array holder
char cmd[6]; //ar is assigned here once '$' is read
int ind = 0; 
int ci = 0;  //index for ar and cmd tracking
void loop() {
  delay(5);
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    char c = incomingByte;
    if(c != '$'){
      ar[ci] = c;
      ci++;
    }else{
      strncpy(cmd, ar, 6);
      ar[0] = '0'; //required this way
      ar[1] = '0';
      ar[2] = '0';
      ar[3] = '0';
      ar[4] = '0';
      ar[5] = '0';
      ci = 0;
      Serial.println(cmd);
    }
   
    //Serial.println(c);
  }
  //End Serial Reception Block

  Serial.println(cmd);
  /* Important logic control from serial communication*/
  switch(cmd[0]){ //remember 0 is * for opening communication
    case 'g':
      /* Group pattern logic switch */
      switch(cmd[1]){
        case 'p': 
          pattern = &pulse;
          Serial.println("Fuuuc");
          break;
        case 'c':
          pattern = &chase;
          break; 
         case 's':
          pattern = &flash; //TODO change to strobe?
          break;
      }
      clear(leds);
      cmd[0] = '0';
  }
  
  (*pattern)(leds); //Pattern Function Call
  //delay(450);
  //chase(leds);
  //delay(50);

}

void flash(CRGB *leds) {
  FastLED.setBrightness(255);
  leds[ind2] = CRGB(0, 0, 0);
  leds[ind] = CRGB(0, 0, 0);
  ind = random(0, 149);
  ind2 = random(0, 149);
  leds[ind] = CRGB(255, 255, 255);
  leds[ind2] = CRGB(255, 255, 255);
  FastLED.show();

}


int pre = 1;
int light_str = 230;

int option = 0;
CRGB color;
int speed = 15;
void chase(CRGB *leds) {

  if (pre > 149) {
    pre = 0;
    option++;
    //Serial.println(option);
    speed--;
  }
  if (option > 1) {
    option = 0;
    Serial.println(option);
  }
  leds[pre] = CRGB::Green;
  if (option == 0) {
    leds[pre] = CRGB::Red;
  }

  //leds[pre].fadeLightBy(pre/2+170);
  //delay(50);


  pre++;



  FastLED.show();

}
void direct_brightness(CRGB *leds, int str) {

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(153, 0, 243);
  }
  FastLED.setBrightness(str);
  FastLED.show();
}


void clear(CRGB *leds) {
  FastLED.setBrightness(255);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();

}
int str = 0;
int addum = 50;

void pulse(CRGB *leds) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 255, 0);
  }

  if (str > 254) {
    addum = -5;
  } else if (str < 0) {
    str = 0;
    addum = 5;
  }

  FastLED.setBrightness(str);

  str += addum;
  //delay(5);


  FastLED.show();


}
