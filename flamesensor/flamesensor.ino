//Required Components:
//Arduino UNO
//Flame Sensor
//LED
//220-ohm resistor
//Jumper wires
//Breadboard
//Connections:
//Flame Sensor:

//VCC -> Arduino 5V
//GND -> Arduino GND
//D0 -> Arduino digital pin 2 (or A0 for analog)
//LED:

//Long leg (anode) -> 220-ohm resistor -> Arduino digital pin 13
//Short leg (cathode) -> Arduino GND

const int flameSensorPin = 2; 
const int ledPin = 13;        

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);        
  Serial.begin(9600);             
}

void loop() {
  int flameState = digitalRead(flameSensorPin); 

  if (flameState == LOW) { 
    digitalWrite(ledPin, HIGH); 
    Serial.println("Fire detected!"); 
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No fire detected."); 
  }
  
  delay(500); 
}
