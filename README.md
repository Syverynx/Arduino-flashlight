# Arduino flashlight
"How far can we get with minimal effort?"
## Features
- OLED screen displaying current power output (as percentage of maximum, seeing as there's no current shunt or sensor)
- several arbitrarily picked PWM levels
- four-button control - PWM level up, down, maximum power, soft power-off

## BOM
* 5V Arduino Pro Mini
* 50W-100W LED
    * a radiator suitable for the LED
    * a lens + reflector kit suitable for the LED
    * CC/CV step up converter suitable for the LED
* 2x step down converter (5V for the Arduino, 12V for the fan)
* a power supply capable of supplying from 5W to 100W at 10-24V

* N-channel MOSFET, I used a IRF520N
* 0.96 inch, SSD1306-based OLED display
* 4 individual buttons, or a 4x1 matrix keypad
* assorted perfboards, headers, wires and connectors

If you decide to build the "enclosure" the same way I did:
* two pieces of wood, laminate, or any thin but strong material
* [handle, 3d-printed.](https://www.thingiverse.com/thing:4619895) Consider mounting after assembly, so that you can balance your flashlight properly.
* connecting pillars, 3d-printed. 

## Pinout

* OLED and Arduino powered by a step-down converter set to 5V
* Cooling fan powered by a step-down converter set to 10-12V
* Arduino pin A4 - OLED's SCK
* Arduino pin A5 OLED's SDA
* Arduino pins 2,3,4,5,6 to the keypad - 2 is common.
* Arduino pin 9 to MOSFET's gate
* MOSFET's source to LED driver ground
* MOSFET's drain to LED's negative contact

Everything else should be self-explanatory.

## Additional information
- If you need to use the `flip()` function, you need to add this it Adafruit's library yourself. You can follow [this guide](http://nerdclub-uk.blogspot.com/2016/03/adding-flip-function-to-adafruits.html) for help.

## Showcase

![PIC1](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(1).jpg)
![PIC2](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(2).jpg)
![PIC3](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(3).jpg)
![PIC4](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(4).jpg)
