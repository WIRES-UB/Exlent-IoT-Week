# Parking Assistant

## 1. Function of This Project

This project uses an ultrasonic distance sensor to build a parking assistant. The Arduino measures the distance to an object and uses green, yellow, and red LEDs to show whether the object is far away, getting close, or too close.

The buzzer also changes behavior based on distance. It stays silent when the object is far away, beeps when the object is getting closer, and stays on when the object is very close.

## 2. Components Needed

- Arduino Uno
- Breadboard
- HC-SR04 ultrasonic distance sensor
- Active buzzer
- Green LED
- Yellow LED
- Red LED
- Three 220 ohm resistors
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Connect the ultrasonic sensor to Arduino Pins 9 and 10, the buzzer to Pin 8, and the three LEDs to Pins 5, 6, and 7.

1. Connect the ultrasonic sensor VCC pin to 5V.
2. Connect the ultrasonic sensor GND pin to Arduino GND.
3. Connect the ultrasonic sensor Trig pin to Arduino digital Pin 9.
4. Connect the ultrasonic sensor Echo pin to Arduino digital Pin 10.
5. Connect the positive side of the buzzer to Arduino digital Pin 8 and the negative side to GND.
6. Connect Arduino digital Pin 5 to the green LED through a 220 ohm resistor.
7. Connect Arduino digital Pin 6 to the yellow LED through a 220 ohm resistor.
8. Connect Arduino digital Pin 7 to the red LED through a 220 ohm resistor.
9. Connect the short leg of each LED to Arduino GND.
10. Upload the sketch and move an object toward the sensor to test the parking zones.


![Parking Assistant circuit](parking_assist.jpg)
