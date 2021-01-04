#include <Arduino.h>
#include "statHandler.h"
#include "messageHandler.h"
#include "GuiDrawer.h"

StatHandler Health(6);
StatHandler Ammo (99);
StatHandler Coins (0);

MessageHandler messageHandler(&Health, &Ammo, &Coins);

GuiDrawer guiDrawer;

void setup() {
  Serial.begin(9600);
  guiDrawer.drawBaseGui();
}

void loop() {
  messageHandler.recieveMessage();

  //checks wether the different values have changed since last loop
  if (Health.checkForChange()){

  }
  if (Ammo.checkForChange()){

  }
  if (Coins.checkForChange()){

  }
}