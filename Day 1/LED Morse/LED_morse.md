# LED Morse Code SOS

## 1. Function of This Project

This project flashes an LED in Morse code to send the SOS signal. The sketch uses custom timing variables for dots, dashes, gaps between symbols, gaps between letters, and the pause before repeating the message.

The SOS pattern is:

- S: three short flashes
- O: three long flashes
- S: three short flashes

## 2. Components Needed

- Arduino Uno
- Breadboard
- LED
- 220 ohm resistor
- Jumper wires
- USB cable for programming and power

## 3. Circuit

Connect the LED and resistor in series between Arduino Pin 13 and GND.

1. Connect Arduino digital Pin 13 to the 220 ohm resistor.
2. Connect the other side of the resistor to the long leg of the LED.
3. Connect the short leg of the LED to Arduino GND.
4. Upload the sketch and observe the SOS flash sequence.


![LED Morse circuit](LED_morse.jpg)
