    // color swirl! connect an RGB LED to the PWM pins as indicated
    // in the #defines
    // public domain, enjoy!
    #define REDPIN2 11
    #define GREENPIN2 10
    #define BLUEPIN2 9
    #define REDPIN 6
    #define GREENPIN 5
    #define BLUEPIN 3
    #define FADESPEED 8 // make this higher to slow down
    void setup() {
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(REDPIN2, OUTPUT);
    pinMode(GREENPIN2, OUTPUT);
    pinMode(BLUEPIN2, OUTPUT);
    }
    void loop() {
    int r, g, b;
    // fade from blue to violet
    for (r = 0; r < 256; r++) {
    analogWrite(BLUEPIN2, r);
    analogWrite(REDPIN, r);
    delay(FADESPEED);
    }
    
    }
