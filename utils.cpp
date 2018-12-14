///////////////////////////////////////////////////////////////////////////////
//`File: utils.cpp
// Desc: Implementation file for some helpful functions.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <Adafruit_NeoPixel.h>
#include <Adafruit_TCS34725.h>
#include <Arduino.h>
#include <Math.h>
#include "utils.h"

extern Adafruit_TCS34725 tcs;
extern Adafruit_NeoPixel pixels;
extern uint8_t gammatable[256];
/////////////////////////////////////////
// Thanks to adafruit and PhilB for the
// gammatable! The table converts the TCS
// rgb data to colors human eyes can see.
void initGammaTable()
{
  for (int i=0; i<256; i++)
  {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    gammatable[i] = x;
  }
}

/////////////////////////////////////////
// This function is based on example code
// from the colorview example in the TCS
// library.
uint8_t convertToGamma(uint16_t clr, uint16_t rawData)
{
  float color;
  uint8_t idx;

  color = rawData;
  color /= clr;
  color *= 256;

  idx = (uint8_t)color;

  return gammatable[idx];
}

/////////////////////////////////////////
// Custom get data function to get data
// in one shot.
void getData(uint16_t *red, uint16_t *blue, uint16_t *green, uint16_t *clr)
{
  digitalWrite(TCS_LED_PIN, HIGH);
  tcs.getRawData(red, blue, green, clr);
  delay(1000);
  digitalWrite(TCS_LED_PIN, LOW);
}

/////////////////////////////////////////
// Update all the neopixels.
void updateAllPixels(uint8_t red, uint8_t blue, uint8_t green, int num)
{
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, red, green, blue);
    pixels.show();
  }
}
