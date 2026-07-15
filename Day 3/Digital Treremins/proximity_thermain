/*
  Arduino Ultrasonic Theremin

  Hardware:
  - Arduino Uno
  - HC-SR04 ultrasonic proximity sensor
  - Passive piezo buzzer

  Move your hand between approximately 5 cm and 50 cm
  from the sensor to change the sound frequency.
*/

const byte TRIG_PIN = 9;
const byte ECHO_PIN = 10;
const byte BUZZER_PIN = 3;

const float MIN_DISTANCE_CM = 5.0;
const float MAX_DISTANCE_CM = 50.0;

const int MIN_FREQUENCY_HZ = 150;
const int MAX_FREQUENCY_HZ = 2000;

float filteredDistance = 25.0;

float measureDistanceCm() {
  // Ensure the trigger pin starts LOW.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond ultrasonic pulse.
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for the returning pulse.
  // Timeout after 30 ms to avoid blocking indefinitely.
  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, 30000UL);

  // No echo was received.
  if (duration == 0) {
    return -1.0;
  }

  // Speed of sound is approximately 0.0343 cm/us.
  // Divide by 2 because the pulse travels to the hand and back.
  return duration * 0.0343 / 2.0;
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  float distance = measureDistanceCm();

  if (distance >= MIN_DISTANCE_CM &&
      distance <= MAX_DISTANCE_CM) {

    // Smooth the measurement to reduce pitch jitter.
    filteredDistance =
        0.75 * filteredDistance + 0.25 * distance;

    /*
      Convert distance to frequency.

      Closer hand  -> higher pitch
      Farther hand -> lower pitch
    */
    int frequency = map(
        constrain((int)(filteredDistance * 10),
                  (int)(MIN_DISTANCE_CM * 10),
                  (int)(MAX_DISTANCE_CM * 10)),
        (int)(MIN_DISTANCE_CM * 10),
        (int)(MAX_DISTANCE_CM * 10),
        MAX_FREQUENCY_HZ,
        MIN_FREQUENCY_HZ
    );

    tone(BUZZER_PIN, frequency);

    Serial.print("Distance: ");
    Serial.print(filteredDistance);
    Serial.print(" cm, Frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");
  } else {
    // Stop playing when no hand is detected in the usable range.
    noTone(BUZZER_PIN);
  }

  delay(20);
}
