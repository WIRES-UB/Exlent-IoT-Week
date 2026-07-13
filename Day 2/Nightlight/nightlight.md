# Nightlight

## 1. Function of This Project

This project builds an automatic nightlight using a photoresistor. The Arduino reads the light level from analog Pin A0 and turns an LED on when the room gets dark.

The sketch uses two threshold values so the LED does not flicker when the light level is close to the switching point.

## 2. Components Needed

- Arduino Uno
- Breadboard
- LED
- 220 ohm resistor
- Photoresistor
- 10k ohm resistor
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Create a voltage divider with the photoresistor and 10k ohm resistor, then connect the LED and resistor in series between Arduino Pin 9 and GND.

1. Connect one side of the photoresistor to 5V.
2. Connect the other side of the photoresistor to Arduino analog Pin A0.
3. Connect a 10k ohm resistor between analog Pin A0 and GND.
4. Connect Arduino digital Pin 9 to the 220 ohm resistor.
5. Connect the other side of the resistor to the long leg of the LED.
6. Connect the short leg of the LED to Arduino GND.
7. Upload the sketch and cover the photoresistor to turn the nightlight on.


![Nightlight circuit](nightlight.jpg)
