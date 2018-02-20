/*
  Blink
{0,300, 350, 400, 500,650,1024} //null, down,up, left, right, OK,
*//*
Takes an input on the AtTiny85 from the VERY TRICKY analogue input pin 2 (as labeled in HLT tutorial)
and outputs these with Software serial to the arduino uno, or Duemillanove
Hookup 
ATTINY85 pin 3 -> Arduino Uno pin 0
ATTINY85 pin 4 -> Arduino Uno pin 1
 */
#include "SSD1306_minimal.h"
#include <avr/pgmspace.h>

#define DEG "\xa7" "C"

SSD1306_Mini oled; // Declare the OLED object

void splash(char *);

void splash(char *msg) {
 oled.startScreen();
 oled.clear(); // Clears the display

 oled.cursorTo(0, 0); // x:0, y:0
 oled.printString("Light Level");
 oled.cursorTo(0, 10); // x:0, y:23
 oled.printString(msg);
}




#include <SoftwareSerial.h>
//#include <SSD1306.h>
//#define sclPin  6
//#define sdaPin  7

//SSD1306 display(0x3c, sdaPin, sclPin);
// Definitions
#define rxPin 10 //RX pin ATtiny84 2
#define txPin 9 //TX pin ATtiny84 3

SoftwareSerial mySerial(rxPin, txPin);



//boolean switchFans = 0;

int ledPin = 1; //A1 phyPin 12
int analogPin=0;//A0 phyPin 13
int adcVal=0;

char * int2char(int value){
   static char charValue[5]; //INT of 4 digits
  
   String str = String(value); 
   str.toCharArray(charValue,5);
   return charValue;
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin,INPUT);
   mySerial.begin(9600);
   
 oled.init(0x3C); // Initializes the display to the specified address
 oled.clear(); // Clears the display
 delay(1000); // Delay for 1 second
 //splash("adcVal"); // Write something to the display (refer to the splash() method
}

// the loop function runs over and over again forever
void loop() {
    //adcVal = 1000;
   adcVal=analogRead(analogPin);
   splash(int2char(adcVal)); 
   
    mySerial.println("Input Val " + String(adcVal));
      digitalWrite(ledPin, HIGH); 
       //bool state = digitalRead(ledPin);
        //mySerial.println(String(state));
     delay(adcVal);
     
      digitalWrite(ledPin, LOW);
       //state = digitalRead(ledPin);
        //mySerial.println(String(state));
     delay(adcVal);
  
   //mySerial.print("Input Val: ");
  
   
 
  delay(100);

mySerial.println();
  
  
   }
