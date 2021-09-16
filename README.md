# Arduino flashlight

## Features
- OLED screen displaying current power output (as percentage of maximum, seeing as there's no current shunt or sensor)
- several arbitrarily picked PWM levels
- four-button control - PWM level up, down, maximum power, soft power-off

## BOM
* 5V Arduino Pro Micro
* 50W-100W LED
    * a radiator suitable for the LED
    * a lens + reflector kit
* suitable CC/CV step up converter
* 2x step down converter (5V for the Arduino, 12V for the fan)
* a power supply capable of supplying from 5W to 100W at 10-24V
* assorted perfboards, headers
* N-channel MOSFET, I used a IRF520N
* 0.96 inch, SSD1306-based OLED display

If you decide

## Pinout



## Additional information
- If you need to use the `flip()` function, you need to add this it to the library. You can follow [this guide](http://nerdclub-uk.blogspot.com/2016/03/adding-flip-function-to-adafruits.html) for that.

## Showcase

![PIC1](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(1).jpg)
![PIC2](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(2).jpg)
![PIC3](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(3).jpg)
![PIC4](https://github.com/Syverynx/Arduino-flashlight/blob/master/Images/Light%20(4).jpg)
