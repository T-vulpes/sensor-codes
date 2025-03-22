const int limitSwitch1Pin = 7; 
const int limitSwitch2Pin = 8;
const int limitSwitch3Pin = 9;
const int limitSwitch4Pin = 10;
int ls_1;
int ls_2;
int ls_3;
int ls_4;

void setup() {
  Serial.begin(9600);
  pinMode(limitSwitch1Pin, INPUT_PULLUP); 
  pinMode(limitSwitch2Pin, INPUT_PULLUP);
  pinMode(limitSwitch3Pin, INPUT_PULLUP);
  pinMode(limitSwitch4Pin, INPUT_PULLUP);
}

void loop() {
  int limitSwitch1State = digitalRead(limitSwitch1Pin);
  int limitSwitch2State = digitalRead(limitSwitch2Pin);
  int limitSwitch3State = digitalRead(limitSwitch3Pin);
  int limitSwitch4State = digitalRead(limitSwitch4Pin);

  if (limitSwitch1State == LOW) {
    ls_1 = 1;
    Serial.print("Limit switch 1 activated! ");
    Serial.println(ls_1);
  } else {
    ls_1 = 0;
    Serial.print("Limit switch 1 deactivated. ");
    Serial.println(ls_1);
  }
  
  if (limitSwitch2State == LOW) {
    ls_2 = 1;
    Serial.print("Limit switch 2 activated! ");
    Serial.println(ls_2);
  } else {
    ls_2 = 0;
    Serial.print("Limit switch 2 deactivated. ");
    Serial.println(ls_2);
  }
  
  if (limitSwitch3State == LOW) {
    ls_3 = 1;
    Serial.print("Limit switch 3 activated! ");
    Serial.println(ls_3);
  } else {
    ls_3 = 0;
    Serial.print("Limit switch 3 deactivated. ");
    Serial.println(ls_3);
  }
  
  if (limitSwitch4State == LOW) {
    ls_4 = 1;
    Serial.print("Limit switch 4 activated! ");
    Serial.println(ls_4);
  } else {
    ls_4 = 0;
    Serial.print("Limit switch 4 deactivated. ");
    Serial.println(ls_4);
  }

}
