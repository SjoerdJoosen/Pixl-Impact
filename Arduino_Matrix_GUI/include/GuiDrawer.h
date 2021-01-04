#ifndef GUIDRAWER_H
#define GUIDRAWER_H
#include <Arduino.h>
#include "matrix.h"

class GuiDrawer {
  private:

  enum COLOURS{
      BLACK = 0,      //0
      WHITE,          //1
      RED,            //2
      YELLOW,         //3
      DARKER_YELLOW,  //4
      DARKEST_YELLOW, //5
      GRAY            //6
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

  void drawHeart(int startX, int startY);

  void pixelDrawer(COLOURS colourToDraw, int drawX, int drawY);
  public:
  GuiDrawer();
  void drawBaseGui();
};
  
#endif