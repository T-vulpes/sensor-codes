// Pin Definitions
const int pirPin = 2;   // HC-SR501 OUT pin connected to digital pin 2
const int ledPin = 13;  // LED connected to digital pin 13

int pirState = LOW;     // Default state is LOW

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(pirPin);
  
  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;  
      digitalWrite(ledPin, HIGH); 
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;  
      digitalWrite(ledPin, LOW); 
    }
  }
}
