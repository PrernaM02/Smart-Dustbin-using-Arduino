#include <Servo.h>
Servo praj;
// IR sensor pin

const int irSensorPin = 2;

// Motor pins
//servomain.attach(7);

// Ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 8;

// Buzzer pin
const int buzzerPin = 4;

//  Variables
long duration;
int distance;

void setup() {
  pinMode(irSensorPin, INPUT);
  praj.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // IR sensor detection
  if (digitalRead(irSensorPin) == LOW) {
    Serial.println("Open Door");
    for (int a = 0 ; a <= 90 ; a++) {
      praj.write(a);
    delay(5);
  }
  delay(500);
  for (int k = 189; k > 0 ; k--) {
   praj.write(k);
   delay(5);
  }
  delay(1000);
  }

  // Ultrasonic sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Display message if distance is less than 20cm
  if (distance < 20) {
    Serial.println("Dustbin Full");
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  }
  
  delay(100); // Small delay between readings
}