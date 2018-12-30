///////////////////////////////////////////////////////////////////////////////
//`File: utils.h
// Desc: Header file for some helpful functions.
//
//
// Author: Irfan Hossain
///////////////////////////////////////////////////////////////////////////////
#ifndef UTILS_H
#define UTILS_H

#define PHOTO_R_PIN A1
#define NEOPIXEL_PIN 10
#define TCS_LED_PIN 11

#define NUMPIXELS 16
#define BAUD_RATE 9600
#define TCS_DELAY 500
#define CALIBRATE_DELAY 500
#define NEOPIXEL_ON 100
#define SHADOW_THRESHOLD 700

/////////////////////////////////////////
//
void initGammaTable();

/////////////////////////////////////////
//
uint8_t convertToGamma(uint16_t clr, uint16_t rawData);


/////////////////////////////////////////
//
uint8_t mapColors256(uint16_t rawData, uint16_t max);

/////////////////////////////////////////
//
void calibrate(uint16_t *red, uint16_t *blue, uint16_t *green, uint16_t *clr);

/////////////////////////////////////////
//
void getData(uint16_t *red, uint16_t *blue, uint16_t *green, uint16_t *clear);

/////////////////////////////////////////
//
void updateAllPixels(uint8_t red, uint8_t blue, uint8_t green, int num, int delayTime);


/////////////////////////////////////////
//
void printValues(uint8_t red, uint8_t green, uint8_t blue);

#endif UTILS_H
