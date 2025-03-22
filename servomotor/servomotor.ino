#include <Servo.h>
Servo myservo;  

void setup() {
  myservo.attach(5); 
  myservo.write(0);
  servoStart();     
  delay(1000);       
  servoStop();      
  delay(1000);       
}

void loop() {}

void servoStop() {
  myservo.write(0);  
  delay(500); 
}
void servoStart() {
  myservo.write(180);  
  delay(1000);        
  servoStop(); 
}
