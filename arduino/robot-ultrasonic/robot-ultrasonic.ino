// inialisasi pin untuk motor kanan-kiri
const int motor1 = 7;
const int motor2 = 6;
const int motor3 = 5;
const int motor4 = 4;

// inialisasi pin sensor ultrasonic
const int pinT = 0; // pin Trigger
const int pinE = 1; // pin Echo

// inialisasi pin untuk pengaturan kecepatan
// wajib menggunakan pin PWM
const int pinSpeed = 9;

// inialisasi variabel durasi, jarak dan kecepatan
int duration, distance, speed;

void setup() {
  // inialisasi status I/O masing2 pin
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(pinT, OUTPUT);
  pinMode(pinE, INPUT);
  pinMode(pinSpeed, OUTPUT);
}

void controlRobot(int distance, int minDistance) {
  // ------------ mengatur pergerakan robot --------------- //
  if (distance >= minDistance){
    // maju
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  } else {
    // mundur
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(300);

    // belok kiri
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    delay(300);
  } 
}

void loop() {
  // ------------- pengaturan kecepatan -------------- //
  // membatasi nilai speed 0 - 255
  speed = constrain(speed, 0, 255);
  
  // inialisasi nilai kecepatan
  // nilai kecepatan dapat diubah, batasannya antara 0 - 255
  speed = 170;
  
  // menuliskan nilai speed pada pinSpesed
  analogWrite(pinSpeed, speed);
  
  // ----------- mengaktifkan sensor ultrasonic -------------- //
  // mengaktifkan pin trigger
  digitalWrite(pinT, HIGH);
  
  // delay 10 mikrodetik
  delayMicroseconds(10);
  
  // mematikan pin trigger
  digitalWrite(pinT, LOW);
  
  // mendapat data duration pantulan gelombang ultrasonic
  duration = pulseIn(pinE, HIGH);
  
  // konversi duration ke distance dalam satuan centimeter(cm)
  distance = ((duration * 0.034) / 2);
  
  // jalankan robot
  controlRobot(distance, 10);
}
