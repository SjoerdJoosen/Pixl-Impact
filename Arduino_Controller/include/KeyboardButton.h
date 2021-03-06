#ifndef KEYBOARDBUTTON_H
#define KEYBOARDBUTTON_H
#include <Arduino.h>
#include <Keyboard.h>

class KeyboardButton{

    private:
        char keyToPress;
        int buttonPin;
        
        void simulateKeyPress();

    public:
        KeyboardButton(int buttonPin, char keyToPress);

        void init();
        void checkButton();


};

#endif