#include <Wire.h>
#include <VL6180X.h>

VL6180X sensor;

void setup() {
  Wire.begin();
  sensor.init();
  sensor.configureDefault();
  Serial.begin(9600);
}

void loop() {
  int distance = sensor.readRangeSingle();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");
  delay(500);
}
