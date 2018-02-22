/*
Display on oled I2C 128x64 the value of ADC input A0. LED blinks at a rate dependant of input Value.
Serial Communication transmits adc value to UNO TX/RX pins.
 */
//create OLED 
#include "SSD1306_minimal.h" // modified to work with attiny84
#include <avr/pgmspace.h>
#define DEG "\xa7" "C"
SSD1306_Mini oled; // Declare the OLED object

//OLED display function
void splash(char *);

void splash(char *msg) {
 oled.startScreen();
 oled.clear(); // Clears the display
 oled.cursorTo(0, 0); // x:0, y:0
 oled.printString("Light Level");
 oled.cursorTo(0, 10); // x:0, y:23
 oled.printString(msg);
}



//create softare serial
#include <SoftwareSerial.h>
#define rxPin 10 //RX pin ATtiny84 2
#define txPin 9 //TX pin ATtiny84 3
SoftwareSerial mySerial(rxPin, txPin);

//boolean switchFans = 0;

int ledPin = 1; //A1 phyPin 12
int analogPin=0;//A0 phyPin 13
int adcVal=0;

//convert int to char *
char * int2char(int value){
   static char charValue[5]; //INT of 4 digits
  
   String str = String(value); 
   str.toCharArray(charValue,5);
   return charValue;
}


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize pins.
  pinMode(ledPin, OUTPUT);
  pinMode(analogPin,INPUT);
   mySerial.begin(9600);
  
  //display setup
 oled.init(0x3C); // Initializes the display to the specified address
 oled.clear(); // Clears the display
 delay(1000); // Delay for 1 second
 //splash("adcVal"); // Write something to the display (refer to the splash() method
}

// the loop function runs over and over again forever
void loop() {
    //adcVal = 1000;
   adcVal=analogRead(analogPin);
  
   splash(int2char(adcVal)); //display ADC value on OLED
   
   mySerial.println("Input Val " + String(adcVal));//send ADC value to myserial
  
   digitalWrite(ledPin, HIGH); //led blinks
   delay(adcVal);
   digitalWrite(ledPin, LOW);
   delay(adcVal);
  
   delay(100);

   mySerial.println();
  
  
   }
