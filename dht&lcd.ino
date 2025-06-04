// ORIGINAL CODE FROM THE BOOK
#define DHTPIN 2
#define DHTTYPE DHT11
DHT11 dht11(2);
LiquidCrystal lcd(12,11,10,9,8,7);
void setup()
{
lcd.begin(16, 2);
lcd.clear();
Serial.begin(9600);
}
void loop()
{
float humidity = dht11.readHumidity();
float temperature = dht11.readTemperature();
lcd.setCursor(0,0);
lcd.print("RH:");
lcd.print(humidity);
lcd.print("%");
float tempC1=dht11.readTemperature();
lcd.setCursor(0,1);
lcd.print("Temp:");
lcd.print(temperature);
lcd.print((char)223); //used to display degree symbol on display lcd.print("C\n");
Serial.print("Realtive Humidity %:");Serial.println(humidity);
Serial.print("Temperature in degree celcius:");Serial.println(temperature);
delay(400);
}

// UPDATED CODE WITHOUT ERROR USING GPT
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12,11,10,9,8,7);
void setup()
{
lcd.begin(16, 2);
lcd.clear();
Serial.begin(9600);
}
void loop()
{
float humidity = dht.readHumidity();
float temperature = dht.readTemperature();
lcd.setCursor(0,0);
lcd.print("RH:");
lcd.print(humidity);
lcd.print("%");
float tempC1=dht.readTemperature();
lcd.setCursor(0,1);
lcd.print("Temp:");
lcd.print(temperature);
lcd.print((char)223); //used to display degree symbol on display lcd.print("C\n");
Serial.print("Realtive Humidity %:");Serial.println(humidity);
Serial.print("Temperature in degree celcius:");Serial.println(temperature);
delay(400);
}
