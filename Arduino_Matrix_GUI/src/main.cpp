#include <Arduino.h>
#include "statHandler.h"
#include "messageHandler.h"
#include "GuiDrawer.h"

StatHandler Health(6);
StatHandler Ammo (10);
StatHandler Coins (0);

MessageHandler messageHandler(&Health, &Ammo, &Coins);

GuiDrawer guiDrawer;

void setup() {
  Serial.begin(9600);
  guiDrawer.initGuiDrawer();
  guiDrawer.drawBaseGui();
}

void loop()
{
  messageHandler.recieveMessage();

  // checks wether the different values have changed since last loop
  if (Health.checkForChange()){
    guiDrawer.updateStat(guiDrawer.HEALTH_STAT, Health.getStat());
  }
  if (Ammo.checkForChange()){
    guiDrawer.updateStat(guiDrawer.AMMO_STAT, Ammo.getStat());  
  }
  if (Coins.checkForChange()){
    guiDrawer.updateStat(guiDrawer.COINS_STAT, Coins.getStat());  
  }
}