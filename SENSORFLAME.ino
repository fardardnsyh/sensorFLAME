#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

const int pinApi = A1;      //inisialisasi sensor api pin pada A1
const int pompa = 8;       // inisialisasi pompa pin pada 8
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

int fireValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
 pinMode(pinApi, INPUT); // Untuk menentukan pin sensor api sebagai input
 pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
 pinMode(pompa, OUTPUT); // Untuk menentukan pin pompa sebagai output
digitalWrite(buzzer,LOW);
digitalWrite(pompa,HIGH);

}
void loop() {
fireValue = analogRead(pinApi); // Membaca nilai sensor api
Serial.print("Api: ");
Serial.println(fireValue);

//output Api
if (fireValue < 100){
  digitalWrite(buzzer, HIGH);
  digitalWrite(pompa, LOW);
  lcd.setCursor(5, 0);
  lcd.print("Api : ");
  lcd.print(fireValue);
  lcd.setCursor(1, 1);
  lcd.print("Ruangan Ada Api");
  delay(6000);
  lcd.clear();  
}
else {
  digitalWrite(buzzer, LOW);
  digitalWrite(pompa, HIGH);
  lcd.setCursor(2, 0);
  lcd.print("Ruangan Aman");
  delay(3000);
  lcd.clear();
}
}
