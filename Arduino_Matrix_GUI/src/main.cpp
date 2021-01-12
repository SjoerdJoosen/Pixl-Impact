#include <Arduino.h>
#include "statHandler.h"
#include "messageHandler.h"
#include "GuiDrawer.h"

//StatHandler Health(6);
//StatHandler Ammo (10);
//StatHandler Coins (0);

//MessageHandler messageHandler(&Health, &Ammo, &Coins);

//properties defined in matrix.h
//RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

GuiDrawer guiDrawer();
//GuiDrawer guiDrawer(&matrix);

void setup() {
  
  //guiDrawer.drawBaseGui();
}

void loop() {
  //messageHandler.recieveMessage();

  //checks wether the different values have changed since last loop
  //if (Health.checkForChange()){

 // }
 // if (Ammo.checkForChange()){

 // }
 // if (Coins.checkForChange()){

 // }
}