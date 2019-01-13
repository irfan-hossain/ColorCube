///////////////////////////////////////////////////////////////////////////////
//`File: utils.h
// Desc: Header file for some helpful functions.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef UTILS_H
#define UTILS_H

#define PHOTO_R_PIN A1  // Pin where photoresistor is connected.
#define NEOPIXEL_PIN 10 // Data pin for neopixels.
#define TCS_LED_PIN 11 // Data pin for TCS color sensor.

#define NUMPIXELS 16
#define BAUD_RATE 9600
#define TCS_DELAY 500 // Delay for how long TCS led should be on.
#define CALIBRATE_DELAY 300 // Delay between each led turning on during calib.
#define NEOPIXEL_ON 100 // Value to turn neopixel on for each color channe.l
#define SHADOW_DIFF_THRESHOLD 250 // Threshold for photoresistor sensor value.

/////////////////////////////////////////
// module: mapColors256
//
// desc: Convert UINT16 raw data from
// rgb sensor to a UINT8.
//
// inputs: rawData - One data channel from
//         rgb sensor.
//         max - The maximum value for the
//         rgb channel used in rawData
//
// outputs: none
//
// return: neoData - The data from the sensor
//         constrained to a value within 0-255.
/////////////////////////////////////////
uint8_t mapColors256(uint16_t rawData, uint16_t max);

/////////////////////////////////////////
// module: calibrate
//
// desc: Find the maximum value for each
// color channel for mapping.
//
// inputs: none
//
// outputs: red - max value of red channel.
//          green - max value of green channel.
//          blue - max value of blue channel.
//          clear - max value of clear channel.
//
// return: nonw
/////////////////////////////////////////
void calibrate(uint16_t *red, uint16_t *green, uint16_t *blue,
                             uint16_t *clr, uint16_t *ambient);

/////////////////////////////////////////
// module: getData
//
// desc: Custom get data function that
// turns on the sensor led with a delay
// for consitent lighting.
//
// inputs: none
//
// outputs: red - value of red channel.
//          green - value of green channel.
//          blue - value of blue channel.
//          clear - value of clear channel.
//
// return:
/////////////////////////////////////////
void getData(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *clr);

/////////////////////////////////////////
// module: update all pixels
//
// desc: Updates all the neopixels.
//
// inputs: red - value of red channel.
//         green - value of green channel.
//         blue - value of blue channel.
//         num - number of leds in pixels.
//         delay - delay time between turning
//         on each eld.
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void updateAllPixels(uint8_t red, uint8_t green, uint8_t blue, int num, int delayTime);


/////////////////////////////////////////
// module: printValues
//
// desc: Prints all the rgb sensor values,
// used for debugging.
//
// inputs: red - value of red channel.
//         green - value of green channel.
//         blue - value of blue channel.
//
// outputs: none
//
// return: none
/////////////////////////////////////////
void printValues(uint8_t red, uint8_t green, uint8_t blue);

#endif UTILS_H
