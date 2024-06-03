#include <Wire.h>
#include <VL6180X.h>

#define ADDRESS1 0x29
#define ADDRESS2 0x52

VL6180X sensor1;
VL6180X sensor2;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  sensor1.init();
  sensor2.init();
  
  sensor1.configureDefault();
  sensor2.configureDefault();
  
  sensor1.setAddress(ADDRESS1);
  sensor2.setAddress(ADDRESS2);

  // Uncomment the following lines if you want to set scaling and timeout
  // sensor1.setScaling(SCALING);
  // sensor2.setScaling(SCALING);
  sensor1.setTimeout(500);
  sensor2.setTimeout(500);
}

void loop() {
  Serial.print(sensor1.readRangeSingle());
  Serial.print(" mm\t\t");
  Serial.print(sensor2.readRangeSingle());
  Serial.print(" mm");
  Serial.println();
}
