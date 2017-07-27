#include "Keyboard.h"
#include "Mouse.h"

int Upgrade = 8;
int Scan = 19;
int Prev = 18;
int Next = 20;
int ZoomOut = 21;
int Closest = 22;
int ZoomIn = 23;

int wait = 400;

void setup()
{
  //pinMode(Front, INPUT);
  //digitalWrite(Front, HIGH);
  pinMode(Scan, INPUT);
  digitalWrite(Scan, HIGH);
  pinMode(Prev, INPUT);
  digitalWrite(Prev, HIGH);
  pinMode(Next, INPUT);
  digitalWrite(Next, HIGH);
  pinMode(ZoomIn, INPUT);
  digitalWrite(ZoomIn, HIGH);
  pinMode(ZoomOut, INPUT);
  digitalWrite(ZoomOut, HIGH);
  pinMode(Closest, INPUT);
  digitalWrite(Closest, HIGH);
  pinMode(Upgrade, INPUT);
  digitalWrite(Upgrade, HIGH);
}

void loop()
{

  if (digitalRead(Scan) == 0)
  {
    Keyboard.write(176);
    delay(wait);
  }
  if (digitalRead(Prev) == 0)
  {
    Keyboard.write('i');
    delay(wait);
  }
  if (digitalRead(Next) == 0)
  {
    Keyboard.write('u');
    delay(wait);
  }
  if (digitalRead(Closest) == 0)
  {
    Keyboard.write('z');
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

  if (digitalRead(ZoomOut) == 0)
  {
    Keyboard.write(KEY_DOWN_ARROW);
    delay(wait);
  }
  if (digitalRead(ZoomIn) == 0)
  {
    Keyboard.write(KEY_UP_ARROW);
    delay(wait);
  }
}
