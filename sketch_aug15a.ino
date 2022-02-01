#include <Wire.h>
#include <LiquidCrystal_I2C.h> //library LCD
LiquidCrystal_I2C lcd (0x27, 16,2 ); // inisialisai pin i2c lcd, lcd yg digunakan 16 koloam 2 baris scl A5, sda A4

#define trigPin 10
#define echoPin 11
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <Servo.h>
Servo myservo;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  
  myservo.attach(9);  //pin 9
  myservo.write(180); // awal gerakan pada pertama nyala di posisi 180

}
void loop() {
  parkir();
  palang();
}
void parkir() {

  if (digitalRead(2)==LOW) {
  
  }
  else {
    lcd.print("parkir 1 kosong");
    lcd.setCursor(0,1);}
  if (digitalRead(4)==LOW) {
  
  }
  else {
    lcd.print("parkir 2 kosong");
    lcd.setCursor(0,0);} 
 
}
void palang() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);

  if (distance < 15) //Jika jarak kurang dari 15cm pintu buka
  {
      
      myservo.write(0);
      delay(100);}// delay buka pintu
      
  else 
  {myservo.write(120);
  delay(3000);}  // delay tutup pintu
}  
