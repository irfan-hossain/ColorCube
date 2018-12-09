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

#define NEOPIXEL_PIN 10
#define NUMPIXELS 16

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Instantiate color sensor object.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800); // Instantiate neo pixels object.


void setup()
{
    Serial.begin(9600);
    pixels.begin();
    tcs.begin();

}

void loop()
{
  // TCS outputs sensor values as uint16_t
  uint16_t red, green, blue, clr;
  // Use these to store converted sensor values for NeoPixels.
  uint8_t neo_red, neo_green, neo_blue;

  // Get data from sensor.
  tcs.getRawData(&red, &green, &blue, &clr);
  delay(60); // Takes 50ms to read data.

  // Convert 16-bit output to 8-bits.
  neo_red = (red >> 8)*50;
  neo_green = (green >> 8)*50;
  neo_blue = (blue >> 8)*50;

  // Update NeoPixels with senesor value.
  pixels.clear();
  for(int i=0;i<NUMPIXELS;i++)
  {
    pixels.setPixelColor(i, pixels.Color(neo_red,neo_green,neo_blue));
    pixels.show();
  }

}
