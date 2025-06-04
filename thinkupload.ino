//Write a program on Arduino / Raspberry Pi to upload temperature and humidity data to using Thing speak cloud 

//PROGRAM 
#include <ThingSpeak.h> 
#include <ESP8266WiFi.h> 
#include <SoftwareSerial.h> 
#include <DHT.h> 
#define DHTTYPE DHT11 
#define DHTPin D5 
DHT dht(DHTPin, DHTTYPE); 
unsigned long ch_no =2340960; //Replace with ThingSpeak Channel number 
const char * write_api = "HM5YR2KI9MVW72UH"; //Replace with ThingSpeak write API 
char ssid[ ] = " "; //use your mobile data user name 
char pass[ ] = " "; // use your internet password 
volatile float temperature=0, humidity=0; 
WiFiClient client; 
void setup() 
{ 
pinMode(DHTPin ,INPUT); 
dht.begin(); 
Serial.begin(9600); 
WiFi.begin(ssid, pass); 
while (WiFi.status() != WL_CONNECTED) 
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println("WiFi connected"); 
Serial.println(WiFi.localIP()); 
ThingSpeak.begin(client); 
} 
void loop() 
{ 
temperature = dht.readTemperature(); 
humidity= dht.readHumidity(); 
Serial.print("Temperature ="),Serial.print(temperature),Serial.println( "Degree Celcius"); 
Serial.print("Humidity ="),Serial.print(humidity),Serial.println( "%RH"); 
ThingSpeak.setField(1,humidity); 
ThingSpeak.setField(2,temperature); 
ThingSpeak.writeFields(ch_no, write_api); 
delay(5000); 
} 
