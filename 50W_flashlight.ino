#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Keypad.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define PWM_PIN 9 // pin connected to N-channel MOSFET's gate

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// keypad init, following the library's example code
const byte rows = 1;
const byte cols = 4;
char keys[rows][cols] = {{'2', '1', '4', '3'},}; //strangely enough, this fits the pinout below
byte rowPins[rows] = {2};
byte colPins[cols] = {6, 5, 4, 3};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
//
uint8_t levels[] = {3, 7, 20, 110, 137, 200, 255}; //arbitralily picked PWM levels
uint8_t brightness = 0; // how bright the LED is
bool softPowerState = 0; // state variable for the soft power-off function
bool turboState = 0; // state variable for the turbo function

void powerStep(bool changeDirection)
{
  //0 = brightness down, 1 - up
  switch (changeDirection) {
    case 0:
      brightness--;
      if (brightness < 0) {
        brightness = 0;
      }
      analogWrite(PWM_PIN, levels[brightness]);
      oledPower();
      break;
    case 1:
      brightness++;
      if (brightness > 6) {
        brightness = 6;
      }
      analogWrite(PWM_PIN, levels[brightness]);
      oledPower();
      break;
  }
}
void oledPower()
{
  int power = (levels[brightness] * 100) / 255;
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("PWR:");
  display.print(power);
  display.print("%");
  display.drawRoundRect(0, 48, 128, 16, 3, SSD1306_WHITE);
  display.fillRoundRect(0, 48, (power * 128) / 100, 16, 3, SSD1306_WHITE);
  display.flip();
  display.display();
}
void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  analogWrite(PWM_PIN, 0); // so that the LED doesn't blind us upon power up
}
void softPowerFunction()
{
  switch(softPowerState)
  {
    case 0:
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(3); 
      display.print("PWR OFF");
      display.flip();
      display.display();
      analogWrite(PWM_PIN, 0);
      display.setTextSize(2);
      break;
    case 1:
      analogWrite(PWM_PIN, levels[brightness]);
      oledPower();
      break;
    default:
      break;
  }
  softPowerState = !softPowerState;
}
void turboFunction()
{
  switch(turboState)
  {
    case 0:
      analogWrite(PWM_PIN, 255);
      display.clearDisplay();
      display.setCursor(0, 0);
      display.setTextSize(3); 
      display.print("TURBO!");
      display.flip();
      display.display();
      display.setTextSize(2);              
      break;
    case 1:
      analogWrite(PWM_PIN, levels[brightness]);
      oledPower();    
      break;
    default:
      break;
  }
  turboState = !turboState;
}
void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY) {
    switch (key)
    {
      case '1':
        powerStep(1);
        break;
      case '2':
        powerStep(0);
        break;
      case '3':      
        turboFunction();
        break;
      case '4':
        softPowerFunction();
        break;
      default:
        break;
    }
  }
}
