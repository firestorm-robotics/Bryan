#include <FastLED.h>
#include <Arduino.h>
#include "Constants.h"

#ifndef LEDSTRIP_H
class LedStrip
{
    private:
        int mWidth = 1;
        int mDot = 0;
        int mVel = 1;
        String m_flag = "wipe"; 
        CRGB *mLeds;
        int *temp;
        void showLED(int r, int g, int b, int id);
    public:
        LedStrip(const int* ledAmt, const int* dataPin);
        ~LedStrip(); 
        void update(String flag);
        void wipe(int r, int g, int b);
        void blinkRight(int r, int g, int b);
        void blinkLeft(int r, int g, int b);
        void off();
        void backStop(int r, int g, int b);
        void fullBack(int r, int g, int b);
        void fullTill(int r, int g, int b);
        void Christmas();
        void MuricaBaby();

};
#endif