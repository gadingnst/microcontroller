#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

const int trigPin = A1;
const int echoPin = A0;
long waktu;
int jarak;

void setup() {
    lcd.begin(16,2);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    waktu = pulseIn(echoPin, HIGH);
    jarak = (waktu * 0.034) / 2;
    lcd.setCursor(0,0);
    lcd.print("Jarak: ");
    lcd.setCursor(7,0);
    lcd.print(jarak);
    lcd.setCursor(12,0);
    lcd.print("cm");
    delay(1000);
}

