# Proximity Alarm

## 1. Function of This Project

This project uses an ultrasonic distance sensor to detect nearby objects. When an object is within 30 cm, the Arduino sounds a buzzer alarm.

The delay between beeps changes with distance, so the alarm beeps faster as the object gets closer.

## 2. Components Needed

- Arduino Uno
- Breadboard
- HC-SR04 ultrasonic distance sensor
- Active buzzer
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Connect the ultrasonic sensor to Arduino Pins 9 and 10, then connect the buzzer to Arduino Pin 8 and GND.

1. Connect the ultrasonic sensor VCC pin to 5V.
2. Connect the ultrasonic sensor GND pin to Arduino GND.
3. Connect the ultrasonic sensor Trig pin to Arduino digital Pin 9.
4. Connect the ultrasonic sensor Echo pin to Arduino digital Pin 10.
5. Connect the positive side of the buzzer to Arduino digital Pin 8.
6. Connect the negative side of the buzzer to Arduino GND.
7. Upload the sketch and move an object toward the sensor to test the proximity alarm.


![Proximity Alarm circuit](Proximity_alarm.jpg)
