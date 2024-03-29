//Hilmi Ogün SEYREK
//ogunseyrek@gmail.com

#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
  
#define pin 3
dht DHT;

void setup() {
Serial.begin(9600);
lcd.begin();
lcd.backlight();
lcd.clear();
}

void loop() {
 int readData = DHT.read22(pin);
 float t = DHT.temperature;
 float h = DHT.humidity;
 lcd.setCursor(0,0);
 lcd.print("Sicaklik: "); 
 lcd.setCursor(11,0);
 lcd.print(t); 
 lcd.print(" C");
 lcd.setCursor(0,1);
 lcd.print("Nem: ");
 lcd.setCursor(8,1);
 lcd.print(h);
 lcd.print(" %");
 delay(1000);
}
