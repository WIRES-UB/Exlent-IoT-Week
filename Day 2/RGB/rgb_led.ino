static uint16_t color[] = {0, 0, 0};

static uint8_t colorChoice = 0;

const uint8_t BUTTON = 2;

const uint8_t RED = 9;
const uint8_t GREEN = 10;
const uint8_t BLUE = 11;

static uint16_t prevChoice;

static unsigned long lastPress;

void setColor() {
  // cycle the color between 0, 1, or 2.
  if (millis() > lastPress + 250) {
    lastPress = millis();
    if (colorChoice++ > 2) {
      colorChoice = 0;
    }
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("started");

  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // add button input
  pinMode(1, INPUT);
  
  // make the "setColor" function run when the button is pressed
  attachInterrupt(digitalPinToInterrupt(BUTTON), setColor, FALLING);
}

void loop() {
  // write the selected color to the LED
  if (analogRead(0) / 4 != prevChoice) {
    color[colorChoice] = analogRead(0) / 4;
    analogWrite(RED, color[0]);
    analogWrite(GREEN, color[1]);
    analogWrite(BLUE, color[2]);
    prevChoice = analogRead(0) / 4;
  }

   
}
