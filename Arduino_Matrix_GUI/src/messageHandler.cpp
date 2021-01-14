#include <Arduino.h>
#include "messageHandler.h"

MessageHandler::MessageHandler(StatHandler* Health, StatHandler* Ammo, StatHandler* Coins){
    health = Health;
    ammo = Ammo;
    coins = Coins;
}

void MessageHandler::recieveMessage(){
    if (Serial.available() > 0){
        char readChar = Serial.read();

        //checks if the read char is the starting char, 
        //if so it empties the message and sets isReading to true
        if (readChar == startChar){
            isReading = true;
            message = "";
        }

        else if (isReading){
            
            //checks if read char is the ending char,
            //if so it sets isReading to false and runs the handleMessage function
            if (readChar == endChar){
                isReading = false;
                handleMessage();
            }

            //adds read character to message string
            else {
                message += readChar;
            }
        }
    }
}

void MessageHandler::handleMessage(){
    //
    if (message.startsWith("GAMESTATE:")){
        if (message.endsWith("IDLE")){

        }
        else if (message.endsWith("BUSY")){

        }
    }

    //checks if the message starts with one of the stats
    else if (message.startsWith("HEALTH:")){
        health->setStat(getValue(message));
    }
    else if (message.startsWith("AMMO:")){
        ammo->setStat(getValue(message));
    }
    else if (message.startsWith("COINS:")){
        coins->setStat(getValue(message));
    }
}

int MessageHandler::getValue(String aMessage){
    int index = aMessage.indexOf(':');
    String value = aMessage.substring(index + 1);
    value.trim();
    int Value = value.toInt();
    return Value;
}