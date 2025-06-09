#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
}
void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(10, 10);
display.print("Temp: ");
display.print(temperature);
display.println(" C");
display.setCursor(10, 30);
display.print("Humidity: ");
display.print(humidity);
display.println(" %");
display.display();
delay(2000);
}
void setup() {
Serial.begin(9600);
dht.begin();
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
}
void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(10, 10);
display.print("Temp: ");
display.print(temperature);
display.println(" C");
display.setCursor(10, 30);
display.print("Humidity: ");
display.print(humidity);
display.println(" %");
display.display();
delay(2000);
}
