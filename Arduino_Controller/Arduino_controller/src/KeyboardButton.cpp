#include "KeyboardButton.h"

KeyboardButton::KeyboardButton(int buttonPin, char keyToPress){
    this -> buttonPin = buttonPin;
    this -> keyToPress = keyToPress;
    init();
}

void KeyboardButton::init(){
    pinMode(buttonPin, INPUT);
}

void KeyboardButton::checkButton(){
    Serial.print(digitalRead(buttonPin));
    if (digitalRead(buttonPin) == HIGH){
        Serial.println(keyToPress);
        simulateKeyPress();
    }
    else if (digitalRead(buttonPin) == LOW){
        Keyboard.release(keyToPress);
    }
}

void KeyboardButton::simulateKeyPress(){
    Keyboard.press(keyToPress);
}