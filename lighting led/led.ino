void setup() {
  pinMode(7, OUTPUT); // Set pin 7 as an output
}

void loop() {
  digitalWrite(7, HIGH); // Turn on the LED connected to pin 7
  delay(1000); // Wait for 1 second
  digitalWrite(7, LOW); // Turn off the LED connected to pin 7
  delay(1000); // Wait for 1 second
}
