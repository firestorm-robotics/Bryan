#include <Arduino.h>
#include <FastLED.h>
#include "SoftwareSerial.h"
#include "LedStrip.h"
#include "Constants.h"


#define RX 6
#define TX 7

//yo yo its me vector

SoftwareSerial xbee(RX,TX);
LedStrip* ledStrip;
String flag;
int x_raw = 0;
int y_raw = 0;
float x;
float y;
bool isChristmas = false;
bool isMuricaBaby = false;
//CRGB leds[20];
void randomColor();
void wipe(int r, int g, int b);
void halfWipe(int r, int g, int b, bool toCable);
void displayColor(int r, int g, int b);
void sweep(int r, int g, int b, bool toCable);
void state();

float mapfloat(int x, int in_min, int in_max, int out_min, int out_max)
{
 return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void setup() 
{
  Serial.begin(9600);
  xbee.begin(9600);
  Serial.println("starting");
  xbee.println("starting");
  // put your setup code here, to run once:
  //FastLED.addLeds<NEOPIXEL, 3>(leds, 20);
  ledStrip = new LedStrip( &kLedAmt, &kDataPin);

}

void loop() 
{
  x_raw = analogRead(4);
  y_raw = analogRead(5);

  x = mapfloat(x_raw,0,1024,-1,1);
  y = mapfloat(y_raw,0,1024,-1,1);
  
  if(x > .1)
  {
    ledStrip -> blinkRight(255, 150, 0);
  }

  if(x < -.1)
  {
    ledStrip -> blinkLeft(255, 150, 0);
  }

  if(x > -.1 && x < .1 && y < .01 && y > -.01)
  {
    ledStrip -> backStop(255, 0, 0);
  }

  if(y < -.01)
  {
    ledStrip -> fullBack(225, 0, 0);
  }
  if(y > 0.9)
  {
    ledStrip -> fullTill(245, 25, 245);
  }else 
  {
    ledStrip ->off();
  }

  if(isChristmas)
  {
    ledStrip -> Christmas();
  }

  if(isMuricaBaby)
  {
    ledStrip -> MuricaBaby();
  }
  

} // put your main code here, to run repeatedly:


void state(void)
{

 if(xbee.available() > 0)
 {
   flag = xbee.readString();
   
 }
 if(flag == "green")
 {
   ledStrip -> wipe(255,255,0);
   //Serial.println('a');
 }
 if(flag == "purple")
 {
   ledStrip -> wipe(255,0,255);
   //Serial.println('b');
 }
}
