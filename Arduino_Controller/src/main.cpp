#include <Arduino.h>
#include "KeyboardButton.h"

//arduino setup
//#  #  #  #  #  #  #  #  #  #  #  #
//5  4  3  2  1  0  A6 A5 A4 A3 A2 A1
//6  7  8  9  10 11 12 13 14 resgnd3V
//#  #  #  #  #  #  #  #  #  #  #  #


//ground button base variables
const int PINGROUNDBUTTON_W = 6;
const int PINGROUNDBUTTON_A = 7;
const int PINGROUNDBUTTON_S = 8;
const int PINGROUNDBUTTON_D = 9;

const char CHARGROUNDBUTTON_W = 'w';
const char CHARGROUNDBUTTON_A = 'a';
const char CHARGROUNDBUTTON_S = 's';
const char CHARGROUNDBUTTON_D = 'd';


//punch button variables
const int PINPUNCHBUTTON_I = 2;
const int PINPUNCHBUTTON_J = 3;
const int PINPUNCHBUTTON_K = 4;
const int PINPUNCHBUTTON_L = 5;

const char CHARPUNCHBUTTON_I = 'i';
const char CHARPUNCHBUTTON_J = 'j';
const char CHARPUNCHBUTTON_K = 'k';
const char CHARPUNCHBUTTON_L = 'l';


//keyboard button objects
KeyboardButton groundButton_w(PINGROUNDBUTTON_W, CHARGROUNDBUTTON_W);
KeyboardButton groundButton_a(PINGROUNDBUTTON_A, CHARGROUNDBUTTON_A);
KeyboardButton groundButton_s(PINGROUNDBUTTON_S, CHARGROUNDBUTTON_S);
KeyboardButton groundButton_d(PINGROUNDBUTTON_D, CHARGROUNDBUTTON_D);

KeyboardButton punchButton_i(PINPUNCHBUTTON_I, CHARPUNCHBUTTON_I);
KeyboardButton punchButton_j(PINPUNCHBUTTON_J, CHARPUNCHBUTTON_J);
KeyboardButton punchButton_k(PINPUNCHBUTTON_K, CHARPUNCHBUTTON_K);
KeyboardButton punchButton_l(PINPUNCHBUTTON_L, CHARPUNCHBUTTON_L);


void setup() {
  groundButton_w.init();
  groundButton_a.init();
  groundButton_s.init();
  groundButton_d.init();
 
  punchButton_i.init();
  punchButton_j.init();
  punchButton_k.init();
  punchButton_l.init();
}

void loop() {
  groundButton_w.checkButton();
  groundButton_a.checkButton();
  groundButton_s.checkButton();
  groundButton_d.checkButton();
 
  punchButton_i.checkButton();
  punchButton_j.checkButton();
  punchButton_k.checkButton();
  punchButton_l.checkButton();
}