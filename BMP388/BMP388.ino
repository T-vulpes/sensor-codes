#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP3XX.h>

Adafruit_BMP388 bmp; // BMP388 sensor

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP388 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  float temperature, pressure;

  temperature = bmp.readTemperature(); 
  pressure = bmp.readPressure() / 100.0F; 

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");

  delay(1000); 
}
