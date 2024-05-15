#include <LiquidCrystal.h>

// Pins für den HC-SR04 Ultraschallsensor
const int trigPin = 9;
const int echoPin = 10;

// Pins für das LCD-Display
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Ultraschallsensor-Pins als Eingang bzw. Ausgang konfigurieren
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // LCD-Display initialisieren
  lcd.begin(16, 2);
}

void loop() {
  // Ultraschallimpuls aussenden
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo-Impuls empfangen und Abstand berechnen
  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;

  // Abstand auf dem LCD-Display anzeigen
  lcd.clear();
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(250);
}
