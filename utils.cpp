///////////////////////////////////////////////////////////////////////////////
//`File: utils.cpp
// Desc: Implementation file for some helpful functions.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <Arduino.h>
#include <Math.h>
#include "utils.h"

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
