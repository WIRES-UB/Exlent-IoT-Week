#include <Servo.h>

// Create a Servo object
Servo robotArm;

// Pin assignments
const int servoPin = 9;
const int potPin = A0;

int potValue;
int angle;

void setup() {

  robotArm.attach(servoPin);

  Serial.begin(9600);

}

void loop() {

  // Read the potentiometer
  potValue = analogRead(potPin);

  // Convert 0-1023 to 0-180 degrees
  angle = map(potValue, 0, 1023, 0, 180);

  // Move the servo
  robotArm.write(angle);

  // Print values
  Serial.print("Potentiometer = ");
  Serial.print(potValue);

  Serial.print("   Angle = ");
  Serial.println(angle);

  delay(15);

}