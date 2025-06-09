#include <DHT.h>
#define DHTPIN 2 // DHT11 data pin connected to D2
#define DHTTYPE DHT11 // Define sensor type
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
Serial.print("Temp: ");
Serial.print(temperature);
Serial.print(" °C, Humidity: ");
Serial.print(humidity);
Serial.println(" %");
delay(2000);
}
