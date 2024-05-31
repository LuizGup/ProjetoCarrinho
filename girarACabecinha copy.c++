// C++ code
//
#include <Servo.h>

int d = 0;

int e = 0;

Servo servo_11;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_11.attach(11, 500, 2500);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);

  servo_11.write(99);
}

void loop() {

  delay(500); // Wait for 500 millisecond(s)

  if (0.01723 * readUltrasonicDistance(A0, A1) > 35) {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
  } 

else {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    servo_11.write(10);
    delay(1000); // Wait for 1000 millisecond(s)
    d = 0.01723 * readUltrasonicDistance(A3, A4);
    delay(500); // Wait for 500 millisecond(s)
    servo_11.write(190);
    delay(1000); // Wait for 1000 millisecond(s)
    e = 0.01723 * readUltrasonicDistance(A3, A4);
    delay(500); // Wait for 500 millisecond(s)
    servo_11.write(99);
    if (d > e) {
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(6, HIGH);
      digitalWrite(4, HIGH);
      delay(450); // Wait for 450 millisecond(s)
      digitalWrite(6, LOW);
      digitalWrite(4, LOW);
    } else {
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      delay(450); // Wait for 450 millisecond(s)
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
    }
  }
}