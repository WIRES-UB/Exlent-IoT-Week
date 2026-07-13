// LED Dimmer using a Potentiometer

const int potPin = A0;
const int ledPin = 9;

int sensorValue = 0;
int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Read potentiometer (0-1023)
  sensorValue = analogRead(potPin);

  // Convert to PWM value (0-255)
  brightness = map(sensorValue, 0, 1023, 0, 255);

  // Set LED brightness
  analogWrite(ledPin, brightness);

  // Display values in Serial Monitor
  Serial.print("Potentiometer: ");
  Serial.print(sensorValue);

  Serial.print("    Brightness: ");
  Serial.println(brightness);

  delay(10);
}