const int ldrPin = A0;
const int ledPin = 9;

const int darkThreshold = 550;
const int brightThreshold = 650;

bool ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(ldrPin);

  if (!ledState && light < darkThreshold) {
    ledState = true;
  }
  else if (ledState && light > brightThreshold) {
    ledState = false;
  }

  digitalWrite(ledPin, ledState);

  Serial.println(light);

  delay(50);
}