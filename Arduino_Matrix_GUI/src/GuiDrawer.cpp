#include <Arduino.h>
#include "GuiDrawer.h"

GuiDrawer::GuiDrawer() 
:   matrix(A, B, C, CLK, LAT, OE, false)
{
}

void GuiDrawer::initGuiDrawer(){
    matrix.begin();
    matrix.setTextColor(matrix.Color333(255,255,255));
    matrix.setTextSize(1);
}

void GuiDrawer::drawBaseGui(){
    drawShape(HEART_SHAPE, 0, 0);
    drawShape(COIN_SHAPE, 0, 8);
    drawShape(COIN_SHAPE, 25, 8);
    drawShape(AMMO_SHAPE, 14, 0);
    updateStat(HEALTH_STAT, 6);
    updateStat(AMMO_STAT, 10);  
    updateStat(COINS_STAT, 0);  
}

void GuiDrawer::drawShape(SHAPES shape, int startX, int startY){
    switch (shape)
    {
    case HEART_SHAPE:
        for (int i = 0; i < HEARTSIZE_X; i++){
            for (int j = 0; j < HEARTSIZE_Y; j++)
            {
                COLOURS pixelToDraw = (COLOURS)HEARTSHAPE[i][j];
                pixelDrawer(pixelToDraw, (j+startX), (i + startY));
            }  
            Serial.println();  
        }
        break;
    
    case AMMO_SHAPE:
        for (int i = 0; i < AMMOSIZE_X; i++){
            for (int j = 0; j < AMMOSIZE_Y; j++)
            {
                COLOURS pixelToDraw = (COLOURS)AMMOSHAPE[i][j];
                pixelDrawer(pixelToDraw, (j+startX), (i + startY));
            }    
        }
        break;
        
    case COIN_SHAPE:
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

void GuiDrawer::pixelDrawer(COLOURS colourToDraw, int drawX, int drawY){
    switch (colourToDraw)
    {
    case BLACK:
        matrix.drawPixel(drawX, drawY, matrix.Color333(0,0,0));
        break;

    case WHITE:
        matrix.drawPixel(drawX, drawY, matrix.Color333(255,255,255));
        break;
    
    case RED:
        matrix.drawPixel(drawX, drawY, matrix.Color333(255, 0, 0));
        break;

    case YELLOW:
        matrix.drawPixel(drawX, drawY, matrix.Color333(255, 255, 0));
        break;

    case DARKER_YELLOW:
        matrix.drawPixel(drawX, drawY, matrix.Color888(32, 16, 0));
        break;
    
    case DARKEST_YELLOW:
        matrix.drawPixel(drawX, drawY, matrix.Color888(16, 16, 0));
        break;

    case ORANGE:
        matrix.drawPixel(drawX, drawY, matrix.Color888(255, 64, 0));
        break;
    
    default:
        break;
    }
}

void GuiDrawer::updateStat(STATS statToUpdate, int statValue){
    switch (statToUpdate)
    {
    case HEALTH_STAT:
        matrix.setCursor(8, 1);
        matrix.fillRect(8, 0, 6, 8, matrix.Color333(0,0,0));
        matrix.print(statValue);
        break;
    
    case AMMO_STAT:
        matrix.fillRect(20, 0, 31, 8, matrix.Color333(0,0,0));
        if (statValue != 10){
            matrix.setCursor(26, 1);
        }
        else{
            matrix.setCursor(20, 1);
        }        
        matrix.print(statValue);
        break;

    case COINS_STAT:
        matrix.fillRect(7, 8, 18, 15, matrix.Color333(0,0,0));
        matrix.setCursor(7, 9);       
        matrix.print(statValue);
        break;

    default:
        break;
    }
}