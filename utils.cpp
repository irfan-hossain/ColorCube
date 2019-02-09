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

/////////////////////////////////////////
//
uint8_t mapColors256(uint16_t rawData, uint16_t max)
{
  uint8_t neoData;
  neoData = map(rawData, 0, max, 0, 255);
  return neoData;
}

/////////////////////////////////////////
//
void calibrate(uint16_t *red, uint16_t *green, uint16_t *blue,
                             uint16_t *clr, uint16_t *ambient)
{
  // These variable are used to only get one color value, since
  // for each channel we want just that channels color value.
  uint16_t dummy1, dummy2;

  // Get red max value.
  updateAllPixels(NEOPIXEL_ON, 0, 0, NUMPIXELS, CALIBRATE_DELAY);
  getData(red, &dummy1, &dummy2, clr);
  updateAllPixels(0, 0, 0, NUMPIXELS, 0);

  // Get green max value.
  updateAllPixels(0, NEOPIXEL_ON, 0, NUMPIXELS, CALIBRATE_DELAY);
  getData(&dummy1, green, &dummy2, clr);
  updateAllPixels(0, 0, 0, NUMPIXELS, 0);

  // Get blue max value.
  updateAllPixels(0, 0, NEOPIXEL_ON, NUMPIXELS, CALIBRATE_DELAY);
  getData(&dummy1, &dummy2, blue, clr);
  updateAllPixels(0, 0, 0, NUMPIXELS, 0);

  // Get ambient light reading.
  *ambient = analogRead(PHOTO_R_PIN);
}

/////////////////////////////////////////
//
void getData(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *clr)
{
  // Turn TCS LED on.
  digitalWrite(TCS_LED_PIN, HIGH);
  delay(TCS_DELAY);

  // Get data.
  tcs.getRawData(red, green, blue, clr);
  delay(TCS_DELAY);

  // Turn TCS LED off.
  digitalWrite(TCS_LED_PIN, LOW);
  delay(TCS_DELAY);
}

/////////////////////////////////////////
//
void updateAllPixels(uint8_t red, uint8_t green, uint8_t blue, int num, int delayTime)
{
  for(int i=0;i<num;i++)
  {
    pixels.setPixelColor(i, red, green, blue);
    pixels.show();
    delay(delayTime);
  }
}

/////////////////////////////////////////
//
void printValues(uint8_t red, uint8_t green, uint8_t blue)
{
  Serial.print("RED: "); Serial.print("\t"); Serial.println(red);
  Serial.print("GRN: "); Serial.print("\t"); Serial.println(green);
  Serial.print("BLU: "); Serial.print("\t"); Serial.println(blue);
  Serial.println(" ");
}
