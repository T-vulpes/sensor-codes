#include <Wire.h>
int ADXL345 = 0x53; // ADXL345 device address

float X_out, Y_out, Z_out; // variables to store the acceleration values

void setup() {
  Serial.begin(9600); 
  Wire.begin(); // initialize I2C communication
  
  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register
  Wire.write(8); // Select 'Measure' mode (0x08)
  Wire.endTransmission();
  delay(10);
}

void loop() {
  // Request six bytes of data from ADXL345 starting from 0x32 register
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32); // starting with register 0x32 (DATA_X0)
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true); // request 6 bytes from the device
  
  X_out = (Wire.read() | Wire.read() << 8);
  X_out = X_out / 256; // convert to 'g'
  Y_out = (Wire.read() | Wire.read() << 8);
  Y_out = Y_out / 256; // convert to 'g'
  Z_out = (Wire.read() | Wire.read() << 8);
  Z_out = Z_out / 256; // convert to 'g'
  
  Serial.print("Xa= ");
  Serial.print(X_out);
  Serial.print("   Ya= ");
  Serial.print(Y_out);
  Serial.print("   Za= ");
  Serial.println(Z_out);
  
  delay(1000); 
}
