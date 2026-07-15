/*
  Smart Alarm System with Latched Flags

  Components:
  - Photoresistor          -> A0
  - HC-SR501 PIR Sensor    -> D8
  - HC-SR04 Ultrasonic
        Trig               -> D9
        Echo               -> D10
  - Passive Buzzer         -> D3
*/

// ---------------- Pin Definitions ----------------
const int LIGHT_PIN = A0;
const int PIR_PIN = 8;

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int BUZZER_PIN = 3;

// ---------------- Thresholds ----------------
const int LIGHT_THRESHOLD = 900;       // 0-1023
const float DISTANCE_THRESHOLD = 7.0; // cm

// ---------------- Latched Flags ----------------
bool motionFlag = false;
bool distanceFlag = false;
bool lightFlag = false;

void setup()
{
  Serial.begin(9600);

  pinMode(PIR_PIN, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("=================================");
  Serial.println(" Smart Alarm System");
  Serial.println(" Waiting for PIR warm-up...");
  Serial.println("=================================");

  // Allow PIR sensor to stabilize
  delay(30000);

  Serial.println("System Ready!");
}

void loop()
{
  //-----------------------------
  // Read Sensors
  //-----------------------------
  bool motionDetected = digitalRead(PIR_PIN);
  int lightValue = analogRead(LIGHT_PIN);
  float distance = getDistance();

  bool lightDetected = (lightValue < LIGHT_THRESHOLD);
  bool distanceDetected =
      (distance > 0 && distance < DISTANCE_THRESHOLD);

  //-----------------------------
  // Latch Flags
  //-----------------------------
  if (motionDetected)
    motionFlag = true;

  if (lightDetected)
    lightFlag = true;

  if (distanceDetected)
    distanceFlag = true;

  //-----------------------------
  // Alarm
  //-----------------------------
  if (motionFlag && lightFlag && distanceFlag)
  {
    tone(BUZZER_PIN, 1000);
    delay(10000);
    motionFlag = false;
    lightFlag = false;
    distanceFlag = false;

    noTone(BUZZER_PIN);

    Serial.println("System Reset");
  }
  else
  {
    noTone(BUZZER_PIN);
  }

  //-----------------------------
  // Reset when ALL sensors are OFF
  //-----------------------------
  
  

  //-----------------------------
  // Print Status
  //-----------------------------
  Serial.print("Motion=");
  Serial.print(motionDetected);

  Serial.print(" Light=");
  Serial.print(lightValue);

  Serial.print(" Distance=");
  Serial.print(distance);

  Serial.print(" M=");
  Serial.print(motionDetected);

  Serial.print(" L=");
  Serial.print(lightDetected);

  Serial.print(" D=");
  Serial.println(distanceDetected);

  Serial.print("| M_flag=");
  Serial.print(motionFlag);

  Serial.print(" L_flag=");
  Serial.print(lightFlag);

  Serial.print(" D_flag=");
  Serial.println(distanceFlag);

  delay(100);
}

//===================================================
// Measure distance using HC-SR04
//===================================================
float getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0)
    return -1;

  return duration * 0.0343 / 2.0;
}