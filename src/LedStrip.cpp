#include "LedStrip.h"

LedStrip::LedStrip(const int* ledAmt, const int* dataPin)
{
     mLeds = new CRGB[*ledAmt];
     FastLED.addLeds<NEOPIXEL, kDataPin>(mLeds, *ledAmt);
     //mLeds[1].setRGB(0,255,0);
     //FastLED.show();
     //Serial.println("got here");
}


void LedStrip::showLED(int r, int g, int b, int id)
{
    mLeds[id].setRGB(r,g,b);
    delay(kDelay);
    FastLED.show();
}

void LedStrip::update(String flag)
{}

void LedStrip::wipe(int r, int g, int b)
{
    for(int i = 0; i <= kLedAmt/2; i++)
    {
    mLeds[kLedAmt/2 + i].setRGB(r,g,b);
    mLeds[kLedAmt/2 - i].setRGB(r,g,b);
    delay(kDelay);
    FastLED.show();
    }

  for(int i = kLedAmt; i >= kLedAmt/2; i--)
  {
    mLeds[i].setRGB(0,0,0);
    mLeds[kLedAmt - i].setRGB(0,0,0);
    delay(kDelay);
    FastLED.show();
  }
}

void LedStrip::blinkRight(int r, int g, int b)
{
  for(int i = (kLedAmt * 2/3) +1; i <= kLedAmt; i++)
  {
    mLeds[i].setRGB(r,g,b);
  }
  FastLED.show();
  delay(1000);
  for(int i = (kLedAmt * 2/3) +1; i <= kLedAmt; i++)
  {
    mLeds[i].setRGB(0,0,0);
  }
  FastLED.show();
  delay(1000);
}

void LedStrip::blinkLeft(int r, int g, int b)
{
  for(int i = 0; i <= (kLedAmt * 1/3) -1; i++)
  {
    mLeds[i].setRGB(r,g,b);
  }
  FastLED.show();
  delay(1000);
  for(int i = 0; i <= (kLedAmt * 1/3) -1; i++)
  {
    mLeds[i].setRGB(0,0,0);
  }
  FastLED.show();
  delay(1000);
}

void LedStrip::off()
{
  for(int i = 0; i <= kLedAmt; i++)
  {
    mLeds[i].setRGB(0,0,0);
  }
  FastLED.show();
}

void LedStrip::Stop(int r, int g, int b)
{
  for(int i = (kLedAmt * 1/3); i <= (kLedAmt * 2/3); i++)
  {
    mLeds[i].setRGB(r,g,b);
  }
  FastLED.show();
}

void LedStrip::fullBack(int r, int g, int b)
{
  for(int i = (kLedAmt * 1/3); i <= (kLedAmt * 2/3); i++)
  {
    mLeds[i].setRGB(r,g,b);
  }
  FastLED.show();
  delay(1000);
  for(int i = (kLedAmt * 1/3); i <= (kLedAmt * 2/3); i++)
  {
    mLeds[i].setRGB(0,0,0);
  }
  FastLED.show();
  delay(1000);
}

void LedStrip::PanicButton()
{
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 121, 0);
  }
  FastLED.show();
  delay(333);
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 121, 0);
  }
  FastLED.show();
  delay(333);
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 121, 0);
  }
  FastLED.show();
  delay(333);
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
  delay(1000);

  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  delay(333);
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  delay(333);for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  delay(333);for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(0, 0, 0);
  }
  FastLED.show();
  delay(1000);
}

void LedStrip::fullTill(int r, int g, int b)
{
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(r,g,b);
  }
  FastLED.show();
}

void LedStrip::Christmas()
{
  for(int i = 0; i < kLedAmt; i+=2)
  {
    mLeds[i].setRGB(255, 0, 0);
  }
  FastLED.show();
  for(int i = 1; i < kLedAmt; i+=2)
  {
    mLeds[i].setRGB(0, 255, 0);
  }
  FastLED.show();
  delay(350);

  for(int i = 0; i < kLedAmt; i+=2)
  {
    mLeds[i].setRGB(0, 255, 0);
  }
  FastLED.show();
  for(int i = 1; i < (kLedAmt-1); i+=2)
  {
    mLeds[i].setRGB(255, 0, 0);
  }
  FastLED.show();
}

void LedStrip::MuricaBaby()
{
  for(int i = 0; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(0, 100, 255);
  }
  FastLED.show();
  for(int i = 1; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  for(int i = 2; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 0, 0);
  }
  FastLED.show();

  delay(350);

  for(int i = 1; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(0, 100, 255);
  }
  FastLED.show();
  for(int i = 2; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  for(int i = 0; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 0, 0);
  }
  FastLED.show();

  delay(350);

  for(int i = 2; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(0, 100, 255);
  }
  FastLED.show();
  for(int i = 0; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 255, 255);
  }
  FastLED.show();
  for(int i = 1; i < kLedAmt; i+=3)
  {
    mLeds[i].setRGB(255, 0, 0);
  }
  FastLED.show();

  delay(350);
}

/*void LedStrip::SpookyScary();
{
  int gamer;
  int hue = 0
  int divisor = 30
  float pi = 3.14159265359
  int min_brightness = 8
  int max_brightness = 64
  
  for(int i = 0; i < kLedAmt; i++)
  {
    float breath = (exp(sin(millis()/5000.0*pi)) - 0.36787944)*108.0;
    breath = map(breath, 0, 255, min_brightness, max_brightness);
    FastLED.setBrightness(breath);
    fill_rainbow(mLeds, kLedAmt, (hue++/divisor));
    if(hue == (255 * divisor)) 
    {
  	hue = 0;
    }
    mLeds[i].setRGB(255, 81, 0);
    FastLED.show();
    delay(5); 
  } 
  
  for(int i = 0; i < kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 0);
    FastLED.show();
    delay(100);
    mLeds[i].setRGB(0,0,0);
    FastLED.show();
  }
  delay(int gamer = random(333, 1000));

  for(int i = 0; i< kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 0);
    FastLED.show();
    delay(100);
    mLeds[i].setRGB(0,0,0);
    FastLED.show();
  }
  delay(int gamer = random(333, 1666));

  for(int i = 0; i< kLedAmt; i++)
  {
    mLeds[i].setRGB(255, 255, 0);
    FastLED.show();
    delay(100);
    mLeds[i].setRGB(0,0,0);
    FastLED.show();
  }
  delay(int gamer = random(333, 666));
}*/