// LED Morse Code SOS
// Dot = 250 ms
// Dash = 750 ms

const int ledPin = 13;

const int dot = 250;
const int dash = 750;
const int symbolGap = 250;      // Gap between dots/dashes
const int letterGap = 750;      // Gap between letters
const int wordGap = 10000;       // Gap after SOS

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // S = ...
  dotBlink();
  dotBlink();
  dotBlink();

  delay(letterGap);

  // O = ---
  dashBlink();
  dashBlink();
  dashBlink();

  delay(letterGap);

  // S = ...
  dotBlink();
  dotBlink();
  dotBlink();

  delay(wordGap);
}

// ---------- Functions ----------

void dotBlink() {
  digitalWrite(ledPin, HIGH);
  delay(dot);

  digitalWrite(ledPin, LOW);
  delay(symbolGap);
}

void dashBlink() {
  digitalWrite(ledPin, HIGH);
  delay(dash);

  digitalWrite(ledPin, LOW);
  delay(symbolGap);
}