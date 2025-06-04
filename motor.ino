#define BUTTON_PIN 7 // Arduino pin connected to button's pin
#define MT_RELAY_PIN 3 // Arduino pin connected to relay's pin
void setup() {
Serial.begin(9600);
// initialize serial
pinMode(BUTTON_PIN, INPUT_PULLUP); // set Arduino pin to input pull-up mode
pinMode(MT_RELAY_PIN, OUTPUT);
// set Arduino pin to output mode
}
void loop()
{
int buttonState = digitalRead(BUTTON_PIN); // read new state
if (buttonState == HIGH)
{
Serial.println("The button is being pressed, the motor is ON");
digitalWrite(MT_RELAY_PIN, HIGH); // turn on
}
else
if (buttonState == LOW )
{
Serial.println("The button is released, he motor is OFF");
digitalWrite(MT_RELAY_PIN, LOW);
}
delay(200);
}
