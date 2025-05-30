//program to interface an Ultrasonic Sensor with Arduino.

// Define pins for the ultrasonic sensor
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Set TRIG_PIN as output and ECHO_PIN as input
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
void loop() {
  // Send a 10-microsecond pulse to trigger the sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  // Read the pulse duration from the echo pin
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in centimeters
  float distance = (duration * 0.034) / 2;
  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  // Delay before the next reading
  delay(1000);
}
