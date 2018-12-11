///////////////////////////////////////////////////////////////////////////////
//`File: ColorCube.ino
// Desc: Main loop for arduino code to run.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_TCS34725.h>
#include "utils.h"

#define NEOPIXEL_PIN 10
#define NUMPIXELS 16
#define BAUD_RATE 9600
#define TCS_DELAY 60

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Instantiate color sensor object.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800); // Instantiate neo pixels object.

uint8_t gammatable[256];

void setup()
{

  Serial.begin(BAUD_RATE);
  pixels.begin();
  tcs.begin();

  initGammaTable();
}

void loop()
{
  // TCS outputs sensor values as uint16_t
  uint16_t red, green, blue, clr;
  uint8_t r, g, b;

  // Get data from sensor.
  tcs.getRawData(&red, &green, &blue, &clr);
  delay(TCS_DELAY); // Takes 50ms to read data.

  // Convert raw data to gamma`values.
  r = convertToGamma(clr, red);
  g = convertToGamma(clr, green);
  b = convertToGamma(clr, blue);

  // Update neopixel colr.
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, r, g, b);
    pixels.show();
  }
}
