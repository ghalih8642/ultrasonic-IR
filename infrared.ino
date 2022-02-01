#include <Wire.h>
#include <LiquidCrystal_I2C.h> //library LCD
LiquidCrystal_I2C lcd (0x27, 16,22 ); // inisialisai pin i2c lcd, lcd yg digunakan 16 koloam 2 baris scl A5, sda A4
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
 // lcd.print("hay bos");
 // lcd.setCursor(4,0);
}


void loop() {

  if (digitalRead(2)==LOW) {
  lcd.setCursor(0,1);
  lcd.clear();
  }
  else {
    lcd.print("1 kosong");
    lcd.setCursor(0,1);}
  if (digitalRead(3)==LOW) {
  lcd.setCursor(0,0);
  lcd.clear();
  }
  else {
    lcd.print("2 kosong");
    lcd.setCursor(0,0);}  
  
    
    
//  if (digitalRead(out)==LOW || digitalRead(S2)==LOW )  {
//    KELUAR();
  }
