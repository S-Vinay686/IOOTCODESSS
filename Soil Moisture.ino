// USING DIGITAL PIN
#define SENSOR_PIN 8 // Digital pin connected to sensor's DOUT
void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set SENSOR_PIN as input
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // Read the digital value from the sensor
  int sensorValue = digitalRead(SENSOR_PIN);

  // Print sensor status
  if (sensorValue == HIGH) {
    Serial.println("Soil is DRY");
  } else {
    Serial.println("Soil is WET");
  }

  // Delay before the next reading
  delay(1000);
}

// USING ANALOG PIN
const int sensorPin = A0; // Analog pin connected to the sensor
int sensorValue = 0;

void setup() {
    Serial.begin(9600); // Start Serial Monitor
}

void loop() {
    sensorValue = analogRead(sensorPin); // Read sensor value
    Serial.print("Soil Moisture Level: ");
    Serial.println(sensorValue); // Print value to Serial Monitor
    delay(1000); // Wait for 1 second
}
