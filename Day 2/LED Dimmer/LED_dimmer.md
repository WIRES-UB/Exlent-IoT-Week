# LED Dimmer

## 1. Function of This Project

This project controls the brightness of an LED using a potentiometer. The Arduino reads the potentiometer value from analog Pin A0, converts it to a PWM brightness value, and sends that value to the LED on Pin 9.

Students can turn the potentiometer to see how analog input values can control an output device in real time.

## 2. Components Needed

- Arduino Uno
- Breadboard
- LED
- 220 ohm resistor
- Potentiometer
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Connect the potentiometer to Arduino Pin A0 and connect the LED and resistor in series between Arduino Pin 9 and GND.

1. Connect one outside leg of the potentiometer to 5V.
2. Connect the other outside leg of the potentiometer to GND.
3. Connect the middle leg of the potentiometer to Arduino analog Pin A0.
4. Connect Arduino digital Pin 9 to the 220 ohm resistor.
5. Connect the other side of the resistor to the long leg of the LED.
6. Connect the short leg of the LED to Arduino GND.
7. Upload the sketch and turn the potentiometer to change the LED brightness.


![LED Dimmer circuit](LED_dimmer.jpg)
