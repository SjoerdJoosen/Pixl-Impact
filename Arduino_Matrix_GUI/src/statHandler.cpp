#include <Arduino.h>
#include "statHandler.h"


StatHandler::StatHandler(int baseStat){
    this -> statValue = baseStat;
    this -> oldStatValue = baseStat;
}

int StatHandler::getStat(){
    return statValue;
    Serial.println("stat got");
}

void StatHandler::setStat(int valueToSetTo){
    this -> statValue = valueToSetTo;
    Serial.println("stat set");
}

bool StatHandler::checkForChange(){
    bool hasChanged = false;
    if (statValue != oldStatValue){
        hasChanged = true;
        oldStatValue = statValue;
    }
    return hasChanged;
}