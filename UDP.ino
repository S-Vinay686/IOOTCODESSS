//Write a program to create UDP server on Arduino / Raspberry Pi and respond with humidity data to UDP client when requested. 

//PROGRAM

#include <ESP8266WiFi.h> 
#include <WiFiUdp.h> 
#include <DHT.h> 
#define DHTPIN D6 
#define DHTTYPE DHT11 
const char* ssid = " "; // hotspot device SSID 
const char* password = " "; // Hotspot Deveice 
unsigned int UDPport = 2390; 
char packetBuffer[255]; 
char ReplyBuffer[255]; 
WiFiUDP Udp; 
DHT dht(DHTPIN, DHTTYPE); 
void setup() 
{ 
dht.begin(); 
Serial.begin(115200); 
Serial.println(); 
Serial.printf("Connecting to %s ", ssid); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) 
{ 
delay(500); 
Serial.print("."); 
} 
Serial.println(" connected"); 
Udp.begin(UDPport); 
Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), UDPport); 
}
void loop() { 
int packetSize = Udp.parsePacket(); 
if (packetSize) { 
Serial.print("Received packet of size "); 
Serial.println(packetSize); 
IPAddress remoteIp = Udp.remoteIP(); 
Serial.print("From "); 
Serial.print(remoteIp); 
Serial.print(", port "); 
Serial.println(Udp.remotePort()); 
int len = Udp.read(packetBuffer, 255); 
if (len > 0) { 
packetBuffer[len] = 0; 
} 
Serial.println("Contents:"); 
Serial.println(packetBuffer); 
float h = dht.readHumidity(); 
float t = dht.readTemperature(); 
if (isnan(h) || isnan(t)) { 
Serial.println("Failed to read from DHT sensor!"); 
return; 
} 
sprintf(ReplyBuffer, "Humidity: %0.1f%%, Temperature: %0.1f°C", h, t); 
Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); 
Udp.write(ReplyBuffer); 
Udp.endPacket(); 
} 
} 
