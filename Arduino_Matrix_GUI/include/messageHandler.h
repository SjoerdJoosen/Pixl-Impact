#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H
#include <Arduino.h>
#include "statHandler.h"


class MessageHandler{
   private:
     const char startChar = '#';
     const char endChar = '%';
     String message;
     bool isReading = false;

     StatHandler* health = nullptr;
     StatHandler* ammo = nullptr;
     StatHandler* coins = nullptr;
   
     void initMessage();
     void handleMessage();
     int getValue(String aMessage);

   public: 
     MessageHandler(StatHandler* Health, StatHandler* Ammo, StatHandler* Coins);
     void recieveMessage();
};

#endif