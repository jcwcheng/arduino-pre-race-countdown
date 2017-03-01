// include the library code:
#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

const int neoPixelPin = 6;  // control pin
const int numPixels = 5;    // number of pixels
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, neoPixelPin, NEO_GRB + NEO_KHZ800);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lcdState = 0;
const int buttonPin = 7; // the number of the push button pin 
int buttonState = 0;
int lastButtonState = 0;
boolean state = false;
// make some custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b11111,
  0b01110,
  0b00000
};




void setup() {
  strip.begin();    // initialize pixel strip
  strip.show();     // Initialize all pixels to 'off'


    
  pinMode(buttonPin, INPUT);

  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // create a new character
  lcd.createChar(0, heart);
  // create a new character
  lcd.createChar(1, smiley);
 
}

void loop() {
  lcd.display();
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    
    for(int lcdState=0; lcdState<=3; lcdState++){
      lcd.print("Are you ready ");
      lcd.setCursor(0, 1);
      lcd.print("for race day? ");
      lcd.write((byte) 1);
      
      for (int brightness = 200; brightness >= 0; brightness--) {
        for (int pixel = 0; pixel < numPixels; pixel++) {
          strip.setBrightness(brightness);    // set the brightness
          strip.setPixelColor(pixel, 0x0003CC);
        }
        strip.show();                         // refresh the strip
        delay(30);                            // wait a hundredth of a second
      }    
      lcdState +=1;
      lcd.clear();
      if(lcdState=1){
        lcd.setCursor(0,0);
        lcd.print("Ready? ");
        for (int brightness = 200; brightness >= 0; brightness--) {
          for (int pixel = 0; pixel < numPixels; pixel++) {
            strip.setBrightness(brightness);    // set the brightness
            strip.setPixelColor(pixel, 0xCC0315);
          }
        strip.show();                         // refresh the strip
        delay(30);                            // wait a hundredth of a second
        }
        lcdState +=1;
        lcd.clear(); 
      }
      if(lcdState=2){
        lcd.print("Get set! ");
        for (int brightness = 150; brightness >= 0; brightness--) {
          for (int pixel = 0; pixel < numPixels; pixel++) {
            strip.setBrightness(brightness);    // set the brightness
            strip.setPixelColor(pixel, 0xFF7F00);
          }
        strip.show();                         // refresh the strip
        delay(30);                            // wait a hundredth of a second
        }
        lcdState +=1;
        lcd.clear(); 
      }      
      if(lcdState=3){
        lcd.print("Go! ");
        for (int brightness = 200; brightness >= 0; brightness--) {
          for (int pixel = 0; pixel < numPixels; pixel++) {
            strip.setBrightness(brightness);    // set the brightness
            strip.setPixelColor(pixel, 0x00CC15);
          }
        strip.show();                         // refresh the strip
        delay(30);                            // wait a hundredth of a second
        }
        lcdState +=1;
        lcd.clear(); 
      }      
    }

    
  }else{
    lcd.clear();
    lcd.noDisplay();
  } 
}

