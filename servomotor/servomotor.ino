#include <Servo.h>
Servo myservo;  // Creating a servo object

void setup() {
  myservo.attach(5); // Attaching the servo signal pin to pin 5
  myservo.write(0);
  servoStart();     
  delay(1000);       
  servoStop();      
  delay(1000);       
}

void loop() {
  // Empty
}

void servoStop() {
  myservo.write(0);  //  0 degrees
  delay(500); 
}
void servoStart() {
  myservo.write(180);  // 180 degrees
  delay(1000);        
  servoStop(); 
}
