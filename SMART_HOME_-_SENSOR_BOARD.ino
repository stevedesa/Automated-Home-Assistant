void setup() {
  pinMode(2, INPUT);          //Sets digital pin 2 as input pin - FIRE SENSOR 1
  pinMode(3, INPUT);          //Sets digital pin 3 as input pin - FIRE SENSOR 2
  pinMode(4, INPUT);          //Sets digital pin 4 as input pin - FIRE SENSOR 3
  pinMode(5, INPUT);          //Sets digital pin 5 as input pin - WATER DETECTOR
  pinMode(6, INPUT);          //Sets digital pin 6 as input pin - FRONT DOOR TOUCH SENSOR
  pinMode(7, OUTPUT);         //Sets digital pin 7 as output pin - BUZZER 1
  pinMode(8, OUTPUT);         //Sets digital pin 8 as output pin - BUZZER 2
  pinMode(9, OUTPUT);         //Sets digital pin 9 as output pin - BUZZER 3
  pinMode(10, OUTPUT);        //Sets digital pin 10 as output pin - BUZZER 4
  pinMode(11, OUTPUT);        //Sets digital pin 11 as output pin - BUZZER 5
  pinMode(12, OUTPUT);        //Sets digital pin 12 as output pin - FIRE ALARM BLINKING LED
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin - FRONT DOOR TOUCH SENSOR DETECTOR LED
}

void loop() {
 // IF DETECTED CASES
 if(digitalRead(2)== HIGH) //FIRE ALARM 1
 {
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
 }
 if(digitalRead(3)== HIGH) //FIRE ALARM 2
 {
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
 }
 if(digitalRead(4)== HIGH) //FIRE ALARM 3
 {
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
 }
 if(digitalRead(5)== HIGH) //WATER DETECTOR
 {
  digitalWrite(10, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
  delay(2000);
 }
 if(digitalRead(6)== HIGH) //FRONT DOOR TOUCH SENSOR DETECTOR
 {
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
 }

 // IF NOT DETECTED CASES
 if(digitalRead(2)== LOW) //FIRE ALARM 1
 {
  digitalWrite(6, LOW);
 }
 if(digitalRead(3)== LOW) //FIRE ALARM 2
 {
  digitalWrite(7, LOW);
 }
 if(digitalRead(4)== LOW) //FIRE ALARM 3
 {
  digitalWrite(8, LOW);
 }
 if(digitalRead(5)== LOW)//WATER DETECTOR
 {
  digitalWrite(9, LOW);
 }
 if(digitalRead(6)== LOW)//FRONT DOOR TOUCH SENSOR DETECTOR
 {
  digitalWrite(11, LOW);
  digitalWrite(13, LOW);
 }
 
}
