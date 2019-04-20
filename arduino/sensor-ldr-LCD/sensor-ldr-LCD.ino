// inisialisasi library LiquidCrystal dan pin LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

void setup() { 
  //LCD yang digunakan 16x2:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // membaca nilai masukan sensor
  int nilai = analogRead(A0);

  // konversi nilai sensor ke tegangan sensor
  float tegangan = nilai * (5 / 1024);

  // mencetak nilai dan tegangan sensor di serial monitor
  Serial.print("Nilai Sensor: ");
  Serial.println(nilai);
  Serial.print("Tegangan Sensor: ");
  Serial.println(tegangan);

  // clear lcd
  lcd.clear();

  // mencetak nilai dan tegangan sensor di LCD
  lcd.setCursor(0, 0);
  lcd.print("Sensor: ");
  lcd.setCursor(8,0);
  lcd.print(nilai);
  lcd.setCursor(0, 1);
  lcd.print("Tegangan: ");
  lcd.setCursor(10, 1);
  lcd.print(tegangan);

  // delay reflash LCD
  delay(500);
}
