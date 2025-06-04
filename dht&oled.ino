#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHT11);
void setup()
{
Serial.begin(9600);
// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
display.display();
delay(2000); // Pause for 2 seconds
// Clear the buffer
display.clearDisplay();
dht.begin();
}
void loop()
{
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();
display.clearDisplay();
display.setTextSize(1);
// Normal 1:1 pixel scale
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print("% RH= ");
display.println(humidity);
display.setCursor(0, 10);
display.print("Temp in Deg= ");
display.println(temperature);
display.setCursor(0, 20);
display.println(" ECE AIEMS ");
display.display();
display.startscrollright(0x00, 0x0F);
Serial.print("Realtive Humidity %:");Serial.println(humidity);
Serial.print("Temperature in degree celcius:");Serial.println(temperature);
delay(2000);
}
