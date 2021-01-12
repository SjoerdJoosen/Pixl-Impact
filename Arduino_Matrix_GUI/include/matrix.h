#ifndef MATRIX_H
#define MATRIX_H
#include <Arduino.h>
#include "RGBmatrixPanel.h"
#include <SPI.h>
#include <Adafruit_I2CDevice.h>

#define CLK  8 
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

#endif