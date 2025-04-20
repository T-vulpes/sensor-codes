int sensorPin = A0; 
float sensorValue = 0;
float current = 0;
float sensitivity = 0.185; // sensitivity of the sensor in mV/A

void setup() {
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(sensorPin); 
  float voltage = (sensorValue * 5.0) / 1024.0; // convert the analog value to voltage
  
  // For ACS712 sensor, the output voltage is around 2.5V at zero current (check this value from the datasheet)
  float zeroCurrentVoltage = 2.5; // Adjust this value according to your sensor
  current = (voltage - zeroCurrentVoltage) / sensitivity; // Calculate the actual current
  
  Serial.print("Current: ");
  Serial.print(current);
  Serial.println(" A");
  delay(1000); 
}
