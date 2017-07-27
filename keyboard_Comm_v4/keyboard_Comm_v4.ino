#include "Keyboard.h"
#include "Mouse.h"

int RedAlert = 0;
int Cancel = 1;
int I = 3;
int II = 5;
int III = 11;
int IV = 8;
int V = 2;
int VI = 4;
int VII = 6;
int VIII = 7;
int IX = 9;
int Upgrade = 10;

int wait = 400;

void setup()
{
  //pinMode(Front, INPUT);
  //digitalWrite(Front, HIGH);
  pinMode(RedAlert, INPUT);
  digitalWrite(RedAlert, HIGH);
  pinMode(Cancel, INPUT);
  digitalWrite(Cancel, HIGH);
  pinMode(I, INPUT);
  digitalWrite(I, HIGH);
  pinMode(II, INPUT);
  digitalWrite(II, HIGH);
  pinMode(III, INPUT);
  digitalWrite(III, HIGH);
  pinMode(IV, INPUT);
  digitalWrite(IV, HIGH);
  pinMode(V, INPUT);
  digitalWrite(V, HIGH);
  pinMode(VI, INPUT);
  digitalWrite(VI, HIGH);
  pinMode(VII, INPUT);
  digitalWrite(VII, HIGH);
  pinMode(VIII, INPUT);
  digitalWrite(VIII, HIGH);
  pinMode(IX, INPUT);
  digitalWrite(IX, HIGH);
  pinMode(Upgrade, INPUT);
  digitalWrite(Upgrade, HIGH);
}

void loop()
{

  if (digitalRead(RedAlert) == 0)
  {
    Keyboard.write('r');
    delay(wait);
  }
  if (digitalRead(Cancel) == 0)
  {
    Keyboard.write('0');
    delay(wait);
  }
  if (digitalRead(I) == 0)
  {
    Keyboard.write('1');
    delay(wait);
  }
  if (digitalRead(II) == 0)
  {
    Keyboard.write('2');
    delay(wait);
  }
  if (digitalRead(III) == 0)
  {
    Keyboard.write('3');
    delay(wait);
  }
  if (digitalRead(IV) == 0)
  {
    Keyboard.write('4');
    delay(wait);
  }
  if (digitalRead(V) == 0)
  {
    Keyboard.write('5');
    delay(wait);
  }
  if (digitalRead(VI) == 0)
  {
    Keyboard.write('6');
    delay(wait);
  }
  if (digitalRead(VII) == 0)
  {
    Keyboard.write('7');
    delay(wait);
  }
  if (digitalRead(VIII) == 0)
  {
    Keyboard.write('8');
    delay(wait);
  }
  if (digitalRead(IX) == 0)
  {
    Keyboard.write('9');
    delay(wait);
  }
  if (digitalRead(Upgrade) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 10; x++) {
      Mouse.move(-100, -100, 0); delay(1);
    }
    for (int x = 0; x < 15; x++) {
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
  
}
