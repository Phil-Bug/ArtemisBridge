#include "Keyboard.h"
#include "Mouse.h"

const int joystickX = A1;   
const int joystickY = A0;
int togCam = 0;

int Warp1 = 12; 
int Warp2 = 11;
int Warp3 = 10;
int Warp4 = 9;
int Stop = 8;

int Upgrade = 5; 
int Reverse = 3;
int Shield = 1;
int Dock = 2;

int Tack = 7;
int LRS = 6;
int Status = 4; 
int ZoomOut = 23;
int ZoomIn = 22;

int wait = 400;

void setup()
{
  pinMode(togCam, INPUT);
  digitalWrite(togCam, HIGH);
   pinMode(Warp1, INPUT);  
  digitalWrite(Warp1, HIGH);  
  pinMode(Warp2, INPUT);  
  digitalWrite(Warp2, HIGH);  
    pinMode(Warp3, INPUT);  
  digitalWrite(Warp3, HIGH);  
  pinMode(Warp4, INPUT);  
  digitalWrite(Warp4, HIGH);  
    pinMode(Stop, INPUT);  
  digitalWrite(Stop, HIGH);  
  pinMode(Upgrade, INPUT);  
  digitalWrite(Upgrade, HIGH);  
  pinMode(Reverse, INPUT);  
  digitalWrite(Reverse, HIGH);  
    pinMode(Shield, INPUT);  
  digitalWrite(Shield, HIGH);  
  pinMode(Dock, INPUT);  
  digitalWrite(Dock, HIGH);
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
}

void loop()
{
  if ( analogRead(joystickX) <= 50) {
    //Rear (198)
    Keyboard.write(198);
    delay(400);
  }
  if ( analogRead(joystickX) >= 1000) {
    //Front (195)
    Keyboard.write(195);
    delay(400);
  }
  if ( analogRead(joystickY) <= 50) {
    //Left (196)
    Keyboard.write(196);
    delay(400);
  }
  if ( analogRead(joystickY) >= 1000) {
    //Right (197)
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
      Mouse.move(-11, 0, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(0, 11, 0);
    }
    Mouse.click();
  } 
  if (digitalRead(Warp1) == 0)
  {
    Keyboard.write('1'); 
    delay(wait);  
  }
  if (digitalRead(Warp2) == 0)
  {
    Keyboard.write('2');
    delay(wait);  
  }
   if (digitalRead(Warp3) == 0)
  {
    Keyboard.write('3');  
    delay(wait);  
  }
  if (digitalRead(Warp4) == 0)
  {
    Keyboard.write('4');  
    delay(wait);  
  }
  if (digitalRead(Stop) == 0)
  {
    Keyboard.write(32);  
    delay(wait);  
  }
   if (digitalRead(Upgrade) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 10; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(25, 0, 0); delay(1);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(0, 5, 0); delay(1);
    }
    Mouse.click(); delay(200);
    for (int x = 0; x < 10; x++) {
      Mouse.move(-100, -100, 0); 
    }
  }
  if (digitalRead(Reverse) == 0)
  {
    Keyboard.write(177); 
    delay(wait);  
  }
  if (digitalRead(Shield) == 0)
  {
    Keyboard.write('q');
    delay(wait);  
  }
   if (digitalRead(Dock) == 0)
  {
    Keyboard.write('r');  
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
}
