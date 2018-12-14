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

uint8_t gammatable[256];

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS
                                          ,TCS34725_GAIN_4X);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN
                                          ,NEO_GRB + NEO_KHZ800);

void setup()
{

  /////////////////////////////////////////
  //
  Serial.begin(BAUD_RATE);
  pixels.begin();
  tcs.begin();

  /////////////////////////////////////////
  //
  initGammaTable();

  /////////////////////////////////////////
  //
  pinMode(TCS_LED_PIN, OUTPUT);
  pinMode(PHOTO_R_PIN, INPUT);
}

void loop()
{
  // TCS outputs sensor values as uint16_t
  uint16_t red, green, blue, clr;

  // Get data and update if there's a shadow.
  int photoRValue = analogRead(PHOTO_R_PIN);
  if (photoRValue < 500)
  {
    // Get data from sensor.
    getData(&red, &green, &blue, &clr);

    // Convert raw data to gamma`values.
    uint8_t r, g, b;
    r = convertToGamma(clr, red);
    g = convertToGamma(clr, green);
    b = convertToGamma(clr, blue);

    // Update neopixel color.
    updateAllPixels(r, g, b, NUMPIXELS);
  }
}
