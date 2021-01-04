#include <Arduino.h>
#include "GuiDrawer.h"

//parsed properties are defined in "matrix.h"
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

GuiDrawer::GuiDrawer(){
    matrix.begin();
    Serial.begin(9600);
}

void GuiDrawer::drawBaseGui(){
    drawHeart(0, 0);
    Serial.println("drawn base gui");
}

void GuiDrawer::drawHeart(int startX, int startY){
    
    for (int i = 0; i < HEARTSIZE_X; i++){
        for (int j = 0; j < HEARTSIZE_Y; j++)
        {
            COLOURS pixelToDraw = (COLOURS)HEARTSHAPE[i][j];
            pixelDrawer(pixelToDraw, (i+startX), (j + startY));
            // Serial.println("drawing heart!");
            // Serial.print("at location:");
            // Serial.print(i);
            // Serial.print(", ");
        }    
        Serial.println("");
    }
}

void GuiDrawer::pixelDrawer(COLOURS colourToDraw, int drawX, int drawY){
    switch (colourToDraw)
    {
    case BLACK:
        //THIS DOESNT WORK FOR SOME STUPID REASON
        matrix.drawPixel(drawX, drawY, matrix.Color888(0,0,0));
        Serial.print("black ");
        break;

    case WHITE:
        matrix.drawPixel(drawX, drawY, matrix.Color888(255,255,255));
        Serial.print("white ");
        break;
    
    case RED:
        matrix.drawPixel(drawX, drawY, matrix.Color888(255, 0, 0));
        Serial.print("red   ");
        break;

    case YELLOW:
        matrix.drawPixel(drawX, drawY, matrix.Color888(0, 0, 0));
        break;

    default:
        break;
    }

}