#ifndef STATHANDLER_H
#define STATHANDLER_H
#include <Arduino.h>

class StatHandler{
    private:
    int statValue;
    int oldStatValue;

    public:
    StatHandler(){};
    StatHandler(int baseStat);

    int getStat();
    void setStat(int valueToSetTo);
    bool checkForChange();
};

#endif