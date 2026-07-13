// Define Pin Numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

// Variables
long duration;
int distance;

void setup() {
  // Initialize pin states
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by sending a 10-microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin; returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance (Speed of sound is ~0.034 cm/us)
  distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Proximity Logic
  if (distance > 0 && distance <= 30) {
    // If an object is within 30cm, sound the alarm
    digitalWrite(buzzerPin, HIGH);
    delay(50); // Short beep duration
    digitalWrite(buzzerPin, LOW);
    
    // The delay between beeps changes dynamically based on distance.
    // Closer = shorter delay = faster beeping!
    // We map a 2cm to 30cm distance to a 50ms to 400ms delay.
    int beepDelay = map(distance, 2, 30, 50, 400);
    delay(beepDelay);
  } else {
    // If nothing is within 30cm, ensure buzzer stays off
    digitalWrite(buzzerPin, LOW);
    delay(100); 
  }
}