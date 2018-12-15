#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 150

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
//#define CLzsOCK_PIN 13

// Define the array of leds
int ind = 0;
int ind2 = 0;
CRGB leds[NUM_LEDS];


 
void flash(CRGB *leds);
int func_2_run = 0;
int arr[3] = {0,0,0};
int count = 0;

///////

// Example 3 - Receive with start- and end-markers

const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(9600);
     FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    Serial.println("<Arduino is ready>");
}
int str2 =0;
int func_2_run_old = -1;

void loop() {
    recvWithStartEndMarkers();
    showNewData();
    //Serial.println(Serial.read());
  //delay(100);
  
/*
  while(Serial.peek() > -1){
    //Serial.print(Serial.peek());
    arr[count] = Serial.read() - 48;
    count ++; 
  }
  Serial.print(arr[0]);
  Serial.print(arr[1]);
  Serial.print(arr[2]);
  func_2_run = arr[0];
  Serial.println();

  //if(Serial.peek() > -1){
    //func_2_run = Serial.peek() - 48;
    //Serial.read();
    //Serial.readBytesUntil('n', buffer, 3);
    //int incomingValue = atoi(buffer);
    //Serial.print(incomingValue);
    //func_2_run = incomingValue;
    //clear(leds);
  //}*/
  //clear(leds);
  //clear(leds);
  func_2_run = receivedChars[0]-48;
  str2 = (receivedChars[1] - 48)*10 + (receivedChars[2] - 48);
  if(func_2_run_old != func_2_run){
    clear(leds);
    clear(leds);
  }
  switch(func_2_run){
    case 0:
      flash(leds);
      func_2_run_old = 0;
      break;
    case 1:
      chase(leds);
      func_2_run_old = 1;
      break;
    case 2: 
      pulse(leds);
      func_2_run_old = 2;
      break;
    case 3:
     // int str = 0;
       //tens and ones place, MATH
      //Serial.println("STR: ");
      //Serial.println(str2);
      direct_brightness(leds, str2);
      func_2_run_old = 3;
      break;
    default:
       break;
  }
  
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

///////


void flash(CRGB *leds){
  FastLED.setBrightness(255);
  leds[ind2] = CRGB(0,0,0);
  leds[ind] = CRGB(0,0,0);
  ind = random(0,149);
  ind2 = random(0,149);
  leds[ind] = CRGB(255,255,255); 
  leds[ind2] = CRGB(255,255,255);
  FastLED.show();

}


int pre = 1;
int light_str = 230;

int option = 0;
CRGB color;
int speed = 15;
void chase(CRGB *leds) { 
  
  if(pre > 149){
    pre = 0;
    option++;
    Serial.println(option);
    speed--; 
  }
  if(option > 1){
    option = 0;
    Serial.println(option);
  }
  leds[pre] = CRGB::Blue;
  if(option == 0){
    leds[pre] = CRGB::Red;
  }
  
  //leds[pre].fadeLightBy(pre/2+170);
  //delay(50);

 
  pre++;
 
  
  
  FastLED.show();
 
}
void direct_brightness(CRGB *leds, int str){

  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(153,0,243);
  }
  FastLED.setBrightness(str);
  FastLED.show();
}


void clear(CRGB *leds){
  FastLED.setBrightness(255);
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(0,0,0);
  }
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(0,0,0);
  }
  FastLED.show();
  
}
int str = 0;
int addum = 50;
void pulse(CRGB *leds){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(0,255,0);
  }

  if(str > 254){
    addum = -5;
  }else if(str < 0){
    str = 0;
    addum = 5;
  }

  FastLED.setBrightness(str);
  
  str += addum;
  //delay(5);
   
  
  FastLED.show();
 
  
}
