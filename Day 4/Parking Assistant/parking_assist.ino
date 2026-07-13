// Define Pin Numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

const int greenLed = 5;
const int yellowLed = 6;
const int redLed = 7;

// Variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Clear and trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the bounce-back time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Print for troubleshooting
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // PARKING LOGIC ZONES
  
  if (distance > 30 || distance == 0) {
    // ZONE 1: SAFE (Object is far away)
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(buzzerPin, LOW); // Silent
  } 
  else if (distance <= 30 && distance > 10) {
    // ZONE 2: CAUTION (Object getting closer)
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
    
    // Dynamic intermittent beeping
    digitalWrite(buzzerPin, HIGH);
    delay(40);
    digitalWrite(buzzerPin, LOW);
    
    int beepDelay = map(distance, 11, 30, 60, 350);
    delay(beepDelay);
  } 
  else if (distance <= 10 && distance > 0) {
    // ZONE 3: DANGER! STOP! (Object is too close)
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
    
    // Continuous solid alarm tone
    digitalWrite(buzzerPin, HIGH); 
  }
  
  delay(60); // Small stability delay for the sensor readings
}