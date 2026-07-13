# Waving Robot

## 1. Function of This Project

This project controls a servo motor with a potentiometer. The Arduino reads the potentiometer value from analog Pin A0, converts it to an angle from 0 to 180 degrees, and moves the servo on Pin 9.

Students can attach a simple arm to the servo and turn the potentiometer to make the robot wave.

## 2. Components Needed

- Arduino Uno
- Breadboard
- Servo motor
- Potentiometer
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Connect the potentiometer to Arduino Pin A0 and connect the servo signal wire to Arduino Pin 9.

1. Connect one outside leg of the potentiometer to 5V.
2. Connect the other outside leg of the potentiometer to GND.
3. Connect the middle leg of the potentiometer to Arduino analog Pin A0.
4. Connect the servo signal wire to Arduino digital Pin 9.
5. Connect the servo power wire to 5V.
6. Connect the servo ground wire to GND.
7. Upload the sketch and turn the potentiometer to move the servo arm.


![Waving Robot circuit](Moving_moter.jpg)
