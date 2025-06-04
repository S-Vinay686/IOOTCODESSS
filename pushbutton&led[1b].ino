int ledpin = 12;
int switchpin = 2;
int val = 0;
void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(switchpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(switchpin);
  if (val==HIGH)
  {
    digitalWrite(ledpin, HIGH);
    Serial.println("Button is pressed, LED is ON");
  }
  else {
  digitalWrite(ledpin, LOW);
  Serial.println("Button is released, LED is OFF");
  }
  delay(500);
}
