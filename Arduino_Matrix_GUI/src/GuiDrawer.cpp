#include <Arduino.h>
#include "GuiDrawer.h"

//RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

GuiDrawer::GuiDrawer(){
    matrix.begin();
    Serial.begin(9600);
}

// GuiDrawer::GuiDrawer(RGBmatrixPanel *Matrix){
//     matrix = Matrix;
//     matrix->begin();
//     Serial.begin(9600);
// }

void GuiDrawer::drawBaseGui(){
    drawShape(HEART, 0, 0);
    drawShape(COIN, 0, 8);
    drawShape(COIN, 25, 8);
    Serial.println("drawn base gui");
}

void GuiDrawer::drawShape(SHAPES shape, int startX, int startY){
    switch (shape)
    {
    case HEART:
        for (int i = 0; i < HEARTSIZE_X; i++){
            for (int j = 0; j < HEARTSIZE_Y; j++)
            {
                COLOURS pixelToDraw = (COLOURS)HEARTSHAPE[i][j];
                pixelDrawer(pixelToDraw, (j+startX), (i + startY));
            }    
        }
        break;
    
    case AMMO:
        for (int i = 0; i < AMMOSIZE_X; i++){
            for (int j = 0; j < AMMOSIZE_Y; j++)
            {
                COLOURS pixelToDraw = (COLOURS)AMMOSHAPE[i][j];
                pixelDrawer(pixelToDraw, (j+startX), (i + startY));
            }    
        }
        break;
        
    case COIN:
        for (int i = 0; i < COINSIZE_X; i++){
            for (int j = 0; j < COINSIZE_Y; j++)
            {
                COLOURS pixelToDraw = (COLOURS)COINSHAPE[i][j];
                pixelDrawer(pixelToDraw, (j+startX), (i + startY));
            }    
        }
        break;

    default:
        break;
    }
}

// void GuiDrawer::pixelDrawer(COLOURS colourToDraw, int drawX, int drawY){
//     switch (colourToDraw)
//     {
//     case BLACK:
//         matrix->drawPixel(drawX, drawY, matrix->Color333(0,0,0));
//         Serial.print("black ");
//         break;

//     case WHITE:
//         matrix->drawPixel(drawX, drawY, matrix->Color333(255,255,255));
//         Serial.print("white ");
//         break;
    
//     case RED:
//         matrix->drawPixel(drawX, drawY, matrix->Color333(255, 0, 0));
//         Serial.print("red   ");
//         break;

//     case YELLOW:
//         matrix->drawPixel(drawX, drawY, matrix->Color333(255, 255, 0));
//         break;

//     case DARKER_YELLOW:
//         matrix->drawPixel(drawX, drawY, matrix->Color888(16, 16, 0));
//         break;

//     default:
//         break;
//     }

// }