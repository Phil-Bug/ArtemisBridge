// - - - - -
// DmxSerial - A hardware supported interface to DMX.
// DmxSerialRecv.ino: Sample DMX application for retrieving 3 DMX values:
// address 1 (red) -> PWM Port 9
// address 2 (green) -> PWM Port 6
// address 3 (blue) -> PWM Port 5
// 
// Copyright (c) 2011 by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// 
// Documentation and samples are available at http://www.mathertel.de/Arduino
// 25.07.2011 creation of the DmxSerial library.
// 10.09.2011 fully control the serial hardware register
//            without using the Arduino Serial (HardwareSerial) class to avoid ISR implementation conflicts.
// 01.12.2011 include file and extension changed to work with the Arduino 1.0 environment
// 28.12.2011 changed to channels 1..3 (RGB) for compatibility with the DmxSerialSend sample.
// 10.05.2012 added some lines to loop to show how to fall back to a default color when no data was received since some time.
// 07.12.2013 luotinen: modified for two led strips (3,5,6 & 9,10,11) and default color green
// - - - - -

#include <DMXSerial.h>

// Constants for demo program

// Front or top strip
const int RedPinFront =    11;  // PWM output pin for Red Light.
const int GreenPinFront =  10;  // PWM output pin for Green Light.
const int BluePinFront =   9;  // PWM output pin for Blue Light.

// Back or bottom strip
const int RedPinBack =    6;  // PWM output pin for Red Light.
const int GreenPinBack =  5;  // PWM output pin for Green Light.
const int BluePinBack =   3;  // PWM output pin for Blue Light.

// White standby mode
#define RedDefaultLevel   100
#define GreenDefaultLevel 100
#define BlueDefaultLevel  100

void setup () {
  DMXSerial.init(DMXReceiver);
  
  // set some default values (green for both strips)
  DMXSerial.write(1, 0);
  DMXSerial.write(2, 100);
  DMXSerial.write(3, 0);
  DMXSerial.write(4, 0);
  DMXSerial.write(5, 100);
  DMXSerial.write(6, 0);
  
  // enable pwm outputs
  pinMode(RedPinFront,   OUTPUT); // sets the digital pin as output
  pinMode(GreenPinFront, OUTPUT);
  pinMode(BluePinFront,  OUTPUT);
  pinMode(RedPinFront,   OUTPUT); 
  pinMode(GreenPinFront, OUTPUT);
  pinMode(BluePinFront,  OUTPUT);
}

void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    // read recent DMX values and set pwm levels 
    analogWrite(RedPinFront,   DMXSerial.read(1));
    analogWrite(GreenPinFront, DMXSerial.read(2));
    analogWrite(BluePinFront,  DMXSerial.read(3));
    analogWrite(RedPinBack,   DMXSerial.read(4));
    analogWrite(GreenPinBack, DMXSerial.read(5));
    analogWrite(BluePinBack,  DMXSerial.read(6));
  } else {
    // Show default color, when no data was received since 5 seconds or more.
    analogWrite(RedPinFront,   RedDefaultLevel);
    analogWrite(GreenPinFront, GreenDefaultLevel);
    analogWrite(BluePinFront,  BlueDefaultLevel);
    analogWrite(RedPinBack,   RedDefaultLevel);
    analogWrite(GreenPinBack, GreenDefaultLevel);
    analogWrite(BluePinBack,  BlueDefaultLevel);
  } // if
}
// End
