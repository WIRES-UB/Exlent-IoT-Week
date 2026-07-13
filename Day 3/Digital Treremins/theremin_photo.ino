const int ldrPin = A0;
const int buzzerPin = 8;

int notes[] = {
  262, // C4
  294, // D4
  330, // E4
  349, // F4
  392, // G4
  440, // A4
  494, // B4
  523  // C5
};

void setup() {}

void loop() {
  int light = analogRead(A0);

  int index = map(light, 0, 1023, 0, 7);
  index = constrain(index, 0, 7);

  tone(buzzerPin, notes[index]);

  delay(20);
}