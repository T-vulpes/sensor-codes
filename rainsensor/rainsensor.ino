const int rainSensorPin = A0; 

void setup() {
  pinMode(rainSensorPin, INPUT); 
  Serial.begin(9600);            
}
void loop() {
  int sensorValue = analogRead(rainSensorPin); 
  float voltage = sensorValue * (5.0 / 1023.0); 
  float waterLevel = map(sensorValue, 0, 1023, 0, 100); // Map the sensor value to a water level percentage (0-100)

  Serial.print("Sensor Value: "); 
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage);
  Serial.print("V | Water Level: ");
  Serial.print(waterLevel);
  Serial.println("%");

  delay(500); 
}
