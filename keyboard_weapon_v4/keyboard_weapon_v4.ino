#include "Keyboard.h"
#include "Mouse.h"

const int joystickX = A0;
const int joystickY = A1;
int togCam = 16;

int TorpToEn = 21;
int EnToTorp = 20;

int Nuke = 14;
int Home = 11;
int EMP = 10;
int PShock = 6;
int Mine = 5;

int AutoTarg = 4;
int BFreqUp = 3;
int BFreqDown = 13;
int TorpLoad1 = 8;
int TorpLoad2 = 12;
int TorpUnl1 = 9;
int TorpUnl2 = 7;

int Tack = 2;
int LRS = 1;
int Status = 0;
int ZoomOut = 22;
int ZoomIn = 23;

int wait = 400;

void setup()
{
  pinMode(togCam, INPUT);
  digitalWrite(togCam, HIGH);
  pinMode(Nuke, INPUT);
  digitalWrite(Nuke, HIGH);
  pinMode(Home, INPUT);
  digitalWrite(Home, HIGH);
  pinMode(EMP, INPUT);
  digitalWrite(EMP, HIGH);
  pinMode(PShock, INPUT);
  digitalWrite(PShock, HIGH);
  pinMode(Mine, INPUT);
  digitalWrite(Mine, HIGH);
  pinMode(AutoTarg, INPUT);
  digitalWrite(AutoTarg, HIGH);
  pinMode(BFreqUp, INPUT);
  digitalWrite(BFreqUp, HIGH);
  pinMode(BFreqDown, INPUT);
  digitalWrite(BFreqDown, HIGH);
  pinMode(TorpLoad1, INPUT);
  digitalWrite(TorpLoad1, HIGH);
  pinMode(TorpLoad2, INPUT);
  digitalWrite(TorpLoad2, HIGH);
  pinMode(TorpUnl1, INPUT);
  digitalWrite(TorpUnl1, HIGH);
  pinMode(TorpUnl2, INPUT);
  digitalWrite(TorpUnl2, HIGH);
  pinMode(Tack, INPUT);
  digitalWrite(Tack, HIGH);
  pinMode(LRS, INPUT);
  digitalWrite(LRS, HIGH);
  pinMode(Status, INPUT);
  digitalWrite(Status, HIGH);
  pinMode(ZoomOut, INPUT);
  digitalWrite(ZoomOut, HIGH);
  pinMode(ZoomIn, INPUT);
  digitalWrite(ZoomIn, HIGH);
  pinMode(TorpToEn, INPUT);
  digitalWrite(TorpToEn, HIGH);
  pinMode(EnToTorp, INPUT);
  digitalWrite(EnToTorp, HIGH);
  Keyboard.begin();
}

void sendTwoKey(int key)
{
  Keyboard.press(KEY_LEFT_SHIFT); delay(10);
  Keyboard.press(key);
  delay(100);
  Keyboard.release(key);
  Keyboard.release(KEY_LEFT_SHIFT);
  delay(wait);
}

void loop()
{
#if 0
  // Testcode: gib Pinnummer für jede gedrückte Taste aus
  for (int i=0; i<24; i++)
  {
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);  
    if (digitalRead (i) == 0)
    {
      // Taste wird gerade gedrückt, gib die Pinnummer aus
      Keyboard.write(32); delay(10);
      Keyboard.write(i/10+'0'); delay(10);
      Keyboard.write(i%10+'0'); delay(10);
      Keyboard.write(32); delay(20);
    }
  }
#endif
  
  if ( analogRead(joystickX) <= 200) {
    //Rear (198)
    Keyboard.write(198);
    delay(400);
  }
  if ( analogRead(joystickX) >= 800) {
    //front (195)
    Keyboard.write(195);
    delay(400);
  }
  if ( analogRead(joystickY) <= 200) {
     //Keyboard.write('l');
    Keyboard.write(196);
    delay(400);
  }
  if ( analogRead(joystickY) >= 800) {
     //Keyboard.write('r');
    Keyboard.write(197);
    delay(400);
  }
  if (digitalRead(togCam) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 10; x++) {
      Mouse.move(100, 0, 0);
    }
    for (int x = 0; x < 11; x++) {
      Mouse.move(0, -100, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(-8, 0, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(0, 11, 0);
    }
    Mouse.click();
  }

  if (digitalRead(Nuke) == 0)
  {
    Keyboard.write('2');
    delay(wait);
  }
  if (digitalRead(Home) == 0)
  {
    Keyboard.write('1');
    delay(wait);
  }
  if (digitalRead(PShock) == 0)
  {
    Keyboard.write('5');
    delay(wait);
  }
  if (digitalRead(EMP) == 0)
  {
    Keyboard.write('4');
    delay(wait);
  }
  if (digitalRead(Mine) == 0)
  {
    Keyboard.write('3');
    delay(wait);
  }
  //load and unload torpedo
  if (digitalRead(TorpUnl1) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(5, 0, 0); delay(1);
    }
    for (int x = 0; x < 30; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
     delay(10);
    Mouse.click();
     delay(200);
     for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }

  //load and unload torpedo
  if (digitalRead(TorpUnl2) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 9; x++) {
      Mouse.move(5, 0, 0); delay(1);
    }
    for (int x = 0; x < 27; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
     delay(1);
    Mouse.click();
     delay(200);
     for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }
  
  if (digitalRead(AutoTarg) == 0)
  {
    Keyboard.write('b');
    delay(wait);
  }
  if (digitalRead(BFreqDown) == 0)
  {
    Keyboard.write(KEY_LEFT_ARROW );
    delay(wait);
  }
  if (digitalRead(BFreqUp) == 0)
  {
    Keyboard.write(KEY_RIGHT_ARROW );
    delay(wait);
  }
  if (digitalRead(Tack) == 0)
  {
    Keyboard.write(199);
    delay(wait);
  }
  if (digitalRead(LRS) == 0)
  {
    Keyboard.write(200);
    delay(wait);
  }
  if (digitalRead(Status) == 0)
  {
    Keyboard.write(201);
    delay(wait);
  }
  if (digitalRead(ZoomOut) == 0)
  {
    Keyboard.write('z');
    delay(wait);
  }
  if (digitalRead(ZoomIn) == 0)
  {
    Keyboard.write('t');
    delay(wait);
  }
  //fire torpedo
  if (digitalRead(TorpLoad1) == 0)
  {
    //sendTwoKey('1');
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 11; x++) {
      Mouse.move(20, 0, 0); delay(1);
    }
    for (int x = 0; x < 30
    ; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
     delay(10);
    Mouse.click();
     delay(200);
     for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }
  //fire torpedo
  if (digitalRead(TorpLoad2) == 0)
  {
   // sendTwoKey('2');
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 11; x++) {
      Mouse.move(20, 0, 0); delay(1);
    }
    for (int x = 0; x < 27; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
     delay(1);
    Mouse.click();
     delay(200);
     for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }
  if (digitalRead(TorpToEn) == 0)
  {
    //sendTwoKey('u');
    Mouse.begin();
    for (int x = 0; x < 10; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    Mouse.begin();
    for (int x = 0; x < 40; x++) {
      Mouse.move(15, 0, 0); delay(1);
    }
    for (int x = 0; x < 28; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
    delay(10);
    Mouse.click();
    delay(200);
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }
  if (digitalRead(EnToTorp) == 0)
  {
    //sendTwoKey('i');
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    Mouse.begin();
    for (int x = 0; x < 40; x++) {
      Mouse.move(15, 0, 0); delay(1);
    }
    for (int x = 0; x < 30; x++) {
      Mouse.move(0, 15, 0); delay(1);
    }
    delay(10);
    Mouse.click();
    delay(200);
    for (int x = 0; x < 11; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
  }  
}
