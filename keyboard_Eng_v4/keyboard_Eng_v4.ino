#include "Keyboard.h"
#include "Mouse.h"

int Store = 7;
int ResetCool = 8;
int ResetPow = 18;
int CoolantDec = 9;
int CoolantInc = 10;
int PowerDec = 19;
int PowerInc = 20;
int Prev = 21;
int Next = 11;
int DamCom = 12;
int I = 6;
int II = 5;
int III = 3;
int IV = 2;
int V = 1;
int VI = 4;
int VII = 0;
int VIII = 23;
int IX = 22;
int Upgrade = 13;

int wait = 400;
//int storePressed = 0;


void setup()
{
  pinMode(Store, INPUT);
  digitalWrite(Store, HIGH);
  pinMode(ResetCool, INPUT);
  digitalWrite(ResetCool, HIGH);
  pinMode(ResetPow, INPUT);
  digitalWrite(ResetPow, HIGH);
  pinMode(CoolantDec, INPUT);
  digitalWrite(CoolantDec, HIGH);
  pinMode(CoolantInc, INPUT);
  digitalWrite(CoolantInc, HIGH);
  pinMode(PowerDec, INPUT);
  digitalWrite(PowerDec, HIGH);
  pinMode(PowerInc, INPUT);
  digitalWrite(PowerInc, HIGH);
  pinMode(Prev, INPUT);
  digitalWrite(Prev, HIGH);
  pinMode(Next, INPUT);
  digitalWrite(Next, HIGH);
  pinMode(DamCom, INPUT);
  digitalWrite(DamCom, HIGH);
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

//void sendTwoKey(int key)
//{
//  Keyboard.press(key);
//  delay(100);
//  //Keyboard.releaseAll();
//  delay(wait);
//  //storePressed = 0;
//}

void loop()
{

  if (digitalRead(Store) == 0)
  {
    //storePressed=1;
    //delay(wait);
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(100, -100, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(-5, 0, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(0, 10, 0);
    }
    Mouse.click();delay(200);
    for (int x = 0; x < 10; x++) {
      Mouse.move(100, -100, 0); 
    }
  }
  if (digitalRead(ResetCool) == 0)
  {
    Keyboard.write(176);
    delay(wait);
  }
  if (digitalRead(ResetPow) == 0)
  {
    Keyboard.write(32);
    delay(wait);
  }
  if (digitalRead(CoolantDec) == 0)
  {
    Keyboard.write('c');
    delay(wait);
  }
  if (digitalRead(CoolantInc) == 0)
  {
    Keyboard.write('e');
    delay(wait);
  }
  if (digitalRead(PowerDec) == 0)
  {
    Keyboard.write('s');
    delay(wait);
  }
  if (digitalRead(PowerInc) == 0)
  {
    Keyboard.write('w');
    delay(wait);
  }
  if (digitalRead(Prev) == 0)
  {
    Keyboard.write('a');
    delay(wait);
  }
  if (digitalRead(Next) == 0)
  {
    Keyboard.write('d');
    delay(wait);
  }
  
  if (digitalRead(I) == 0)
  {
    //sendTwoKey('1');
     Keyboard.write('1');
    delay(wait);
  }
  if (digitalRead(II) == 0)
  {
    //sendTwoKey('2');
     Keyboard.write('2');
    delay(wait);
  }
  if (digitalRead(III) == 0)
  {
    //sendTwoKey('3');
     Keyboard.write('3');
    delay(wait);
  }
  if (digitalRead(IV) == 0)
  {
    //sendTwoKey('4');
     Keyboard.write('4');
    delay(wait);
  }
  if (digitalRead(V) == 0)
  {
    //sendTwoKey('5');
     Keyboard.write('5');
    delay(wait);
  }
  if (digitalRead(VI) == 0)
  {
    //sendTwoKey('6');
     Keyboard.write('6');
    delay(wait);
  }
  if (digitalRead(VII) == 0)
  {
    //sendTwoKey('7');
     Keyboard.write('7');
    delay(wait);
  }
  if (digitalRead(VIII) == 0)
  {
    //sendTwoKey('8');
     Keyboard.write('8');
    delay(wait);
  }
  if (digitalRead(IX) == 0)
  {
    //sendTwoKey('9');
     Keyboard.write('9');
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

  if (digitalRead(DamCom) == 0)
  {
    Mouse.begin();
    for (int x = 0; x < 11; x++) {
      Mouse.move(100, -100, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(-10, 0, 0);
    }
    for (int x = 0; x < 10; x++) {
      Mouse.move(0, 7, 0);
    }
    Mouse.click();delay(200);
    for (int x = 0; x < 10; x++) {
      Mouse.move(100, -100, 0); 
    }
  }
    
}
