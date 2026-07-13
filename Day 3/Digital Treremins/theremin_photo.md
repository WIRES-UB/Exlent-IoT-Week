# Digital Theremin

## 1. Function of This Project

This project creates a simple light-controlled musical instrument. The Arduino reads a photoresistor on analog Pin A0 and maps the light value to one of eight musical notes played through a buzzer on Pin 8.

Students can move their hand over the photoresistor to change the amount of light and hear the pitch change.

## 2. Components Needed

- Arduino Uno
- Breadboard
- Photoresistor
- 10k ohm resistor
- Passive buzzer
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Create a voltage divider with the photoresistor and 10k ohm resistor, then connect the buzzer to Arduino Pin 8 and GND.

1. Connect one side of the photoresistor to 5V.
2. Connect the other side of the photoresistor to Arduino analog Pin A0.
3. Connect a 10k ohm resistor between analog Pin A0 and GND.
4. Connect the positive leg of the buzzer to Arduino digital Pin 8.
5. Connect the negative leg of the buzzer to Arduino GND.
6. Upload the sketch and change the light on the photoresistor to play different notes.


![Digital Theremin circuit](digital_theremin.jpg)
