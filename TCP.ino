#include <ESP8266WiFi.h>
#include <DHT.h>
const char* ssid = "XYZ";            // Wi-Fi SSID
const char* password = "123";  // Wi-Fi password
#define DHTPIN D6                     // DHT data pin
#define DHTTYPE DHT11                // DHT type
DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(8888);             // Create server on port 8888

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("Server started. Connect via Telnet.");
}

void loop() {
  WiFiClient client = server.available(); // Check for incoming clients
  if (client && client.connected()) {
    Serial.println("Client connected");

    while (client.connected()) {
    
      if (client.available()) {
        String request = client.readStringUntil('\r');
        
        if (request.indexOf("/humidity") != -1) {
          float h = dht.readHumidity();
          client.println("Humidity: " + String(h) + "%");
        }
      }
    }

    client.stop();
    Serial.println("Client disconnected");
  }
}
