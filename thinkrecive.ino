//Write a program on Arduino / Raspberry Pi to receive temperature and humidity data from Thing speak cloud. 

//PROGRAM 
#include <ThingSpeak.h> 
#include <ESP8266WiFi.h> 
#include <Wire.h> 
//--WiF_i device/router credentials--// 
const char ssid[] = "  "; // your network SSID (name) 
const char pass[] = "  "; // your network password 
int statusCode = 0; 
WiFiClient client; 
//---------Channel and field Details -------- // 
unsigned long ChannelID = 2340960; 
// Channel ID 
const char * myCounterReadAPIKey = "TEUW37GZWJDCPYMW"; // Read API Key 
const int FieldNumber1 = 1; 
const int FieldNumber2 = 2; 
//-------------------// 
void setup() 
{ 
Serial.begin(9600); 
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
delay(1000); 
} 
void loop() 
{ 
// 
Read Field 1 
// 
long humidity = ThingSpeak.readLongField(ChannelID, FieldNumber1, myCounterReadAPIKey); 
statusCode = ThingSpeak.getLastReadStatus(); 
if (statusCode == 200) 
{ 
Serial.print("% RH= "); 
Serial.println(humidity);
} 
else 
{ 
Serial.println("Unable to read channel data or No internet"); 
} 
delay(1000); 
// 
End of Field 1 
// 
Read Field 2 
// 
// 
long temp = ThingSpeak.readLongField(ChannelID, FieldNumber2, myCounterReadAPIKey); 
statusCode = ThingSpeak.getLastReadStatus(); 
if (statusCode == 200) 
{ 
Serial.print( "Temperature in degree celcius= ");Serial.println(temp); 
} 
else 
{ 
Serial.println("Unable to read channel data or No internet"); 
} 
delay(15000); 
// 
End of Field 2 
} 
