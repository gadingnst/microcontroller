#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

const int LED = 13;

void setup() { 
  // LCD yang digunakan 16x2:
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Nilai masukan sensor ke Arduino:
  int nilai = analogRead(A0); 

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Intensitas ");
  lcd.setCursor(11,0); //Kursor kolom ke-11 baris ke-1
  lcd.print(nilai); // LCD menampilkan nilai masukan sensor
  lcd.setCursor(0,1); // Kursor kolom ke-1 baris ke-2
  lcd.print("Keadaan LED ");
  
  if (nilai <= 500){
    digitalWrite(LED, LOW); //LED Mati
    lcd.setCursor(12,1); //Kursor kolom ke 12 baris ke-1
    lcd.print("OFF");
  } else { 
    digitalWrite(LED, HIGH); //LED Hidup
    lcd.setCursor(12,1); //Kursor kolom ke-12 baris ke-2
    lcd.print("ON");
  }
  
  delay(500); 
  lcd.clear();
}
