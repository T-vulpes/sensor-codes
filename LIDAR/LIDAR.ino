#include <Wire.h>

const int LIDARLite_Address = 0x62; // Default I2C Address of LIDAR-Lite.
const int LIDARLite_Measure = 0x00; // Register to write to initiate ranging.
const int LIDARLite_Distance = 0x8f; // Register to get 2 byte distance.

void setup() {
  Wire.begin(); 
  Serial.begin(9600);
}

void loop() {
  int distance;
  distance = getDistance(); 
  Serial.println(distance); 
  delay(100);
}

int getDistance() {
  Wire.beginTransmission(LIDARLite_Address);
  Wire.write(LIDARLite_Measure);
  Wire.endTransmission();
  delay(20);
  Wire.requestFrom(LIDARLite_Address, 2);
  while (Wire.available() < 2) { 
    delay(1);
  }
  byte distanceMSB = Wire.read(); 
  byte distanceLSB = Wire.read();
  int distance = (distanceMSB << 8) + distanceLSB; 
  return distance;
}

