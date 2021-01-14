#ifndef GUIDRAWER_H
#define GUIDRAWER_H
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

class GuiDrawer {
  private:


  RGBmatrixPanel matrix;

  enum COLOURS{
      BLACK = 0,      //0
      WHITE,          //1
      RED,            //2
      YELLOW,         //3
      DARKER_YELLOW,  //4
      DARKEST_YELLOW, //5
      ORANGE          //6
  };

  enum SHAPES{
      HEART_SHAPE = 0,      //0
      AMMO_SHAPE,           //1
      COIN_SHAPE            //2
  };

  const int HEARTSIZE_X = 8;
  const int HEARTSIZE_Y = 8;
  const int HEARTSHAPE [8][8] = 
  {
    {0, 2, 2, 0, 0, 2, 2, 0},
    {2, 2, 1, 2, 2, 2, 2, 2},
    {2, 1, 2, 2, 2, 2, 2, 2},
    {2, 1, 2, 2, 2, 2, 2, 2},  
    {2, 2, 2, 2, 2, 2, 2, 2},  
    {0, 2, 2, 2, 2, 2, 2, 0},  
    {0, 0, 2, 2, 2, 2, 0, 0},  
    {0, 0, 0, 2, 2, 0, 0, 0},  
  };

  const int COINSIZE_X = 8;
  const int COINSIZE_Y = 7;
  const int COINSHAPE [8][7] = 
  {
    {0, 0, 4, 4, 4, 0, 0},
    {0, 4, 3, 3, 3, 4, 0},
    {4, 3, 3, 4, 3, 3, 4},
    {4, 3, 3, 4, 3, 3, 4},
    {4, 3, 3, 4, 3, 3, 4},
    {4, 3, 3, 4, 3, 3, 4},
    {0, 4, 3, 3, 3, 4, 0},
    {0, 0, 4, 4, 4, 0, 0}
  };
    
  const int AMMOSIZE_X = 8;
  const int AMMOSIZE_Y = 6;
  const int AMMOSHAPE [8][6] =
  {
    {0, 6, 0, 0, 6, 0},
    {6, 6, 6, 6, 6, 6},
    {3, 3, 5, 3, 3, 5},
    {3, 3, 5, 3, 3, 5},
    {3, 3, 5, 3, 3, 5},
    {3, 3, 5, 3, 3, 5},
    {3, 3, 5, 3, 3, 5},
    {3, 3, 5, 3, 3, 5}
  };

  void drawShape(SHAPES shape, int startX, int startY);
  void pixelDrawer(COLOURS colourToDraw, int drawX, int drawY);
  
  public:

  enum STATS{
      HEALTH_STAT = 0,     //1
      AMMO_STAT,           //1
      COINS_STAT           //2
  };

  GuiDrawer();
  void initGuiDrawer();
  void drawBaseGui();
  void updateStat(STATS statToUpdate, int statValue);
};
  
#endif