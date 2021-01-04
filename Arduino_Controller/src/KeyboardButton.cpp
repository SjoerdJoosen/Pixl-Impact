#include "KeyboardButton.h"

KeyboardButton::KeyboardButton(int buttonPin, char keyToPress){
    this -> buttonPin = buttonPin;
    this -> keyToPress = keyToPress;
    init();
}

void KeyboardButton::init(){
    pinMode(buttonPin, INPUT);
    
    //if the keyboard has already been started it should skip starting the keyboard again
    #ifndef KEYBOARD_BEGUN
    #define KEYBOARD_BEGUN
        Keyboard.begin();
    #endif
}

void KeyboardButton::checkButton(){
    if (digitalRead(buttonPin) == HIGH){
        simulateKeyPress();
    }
    else if (digitalRead(buttonPin) == LOW){
        Keyboard.release(keyToPress);
    }
}

void KeyboardButton::simulateKeyPress(){
    Keyboard.press(keyToPress);
}