char data = 0;                //Variable for storing received data
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(2, OUTPUT);        //Sets digital pin 2 as output pin
  pinMode(3, OUTPUT);        //Sets digital pin 3 as output pin
  pinMode(4, OUTPUT);        //Sets digital pin 4 as output pin
  pinMode(5, OUTPUT);        //Sets digital pin 5 as output pin
  pinMode(6, OUTPUT);        //Sets digital pin 6 as output pin
  pinMode(7, OUTPUT);        //Sets digital pin 7 as output pin
  digitalWrite(2, LOW);     //Switch relay1 off
  digitalWrite(3, LOW);     //Swtich relay2 off
  digitalWrite(4, LOW);     //Swtich relay3 off
  digitalWrite(5, LOW);     //Swtich relay4 off
  digitalWrite(6, LOW);     //Swtich relay5 off
  digitalWrite(7, LOW);     //Swtich relay6 off

}
void loop()
{
  if(Serial.available() > 0)  // Send data only when you receive data:
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line
    
    {
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(2, HIGH);  //If value is 1 then Relay turns ON
    else if(data == 'A')       //Checks whether value of data is equal to 0
      digitalWrite(2, LOW);   //If value is 0 then Relay turns OFF
  
    if(data == '2')            //Checks whether value of data is equal to 1 
      digitalWrite(3, HIGH);  //If value is 2 then Relay turns ON
    else if(data == 'B')       //Checks whether value of data is equal to 0
      digitalWrite(3, LOW);   //If value is 0 then Relay turns OFF
   
    if(data == '3')            //Checks whether value of data is equal to 1 
      digitalWrite(4, HIGH);  //If value is 3 then Relay turns ON
    else if(data == 'C')       //Checks whether value of data is equal to 0
      digitalWrite(4, LOW);   //If value is 0 then Relay turns OFF
 
    if(data == '4')            //Checks whether value of data is equal to 1 
      digitalWrite(5, HIGH);  //If value is 4 then Relay turns ON
    else if(data == 'D')       //Checks whether value of data is equal to 0
      digitalWrite(5, LOW);   //If value is 0 then Relay turns OFF
 
    if(data == '5')            //Checks whether value of data is equal to 1 
      digitalWrite(6, HIGH);  //If value is 5 then Relay turns ON
    else if(data == 'E')       //Checks whether value of data is equal to 0
      digitalWrite(6, LOW);   //If value is 0 then Relay turns OFF
  
    if(data == '6')            //Checks whether value of data is equal to 1 
      digitalWrite(7, HIGH);  //If value is 6 then Relay turns ON
    else if(data == 'F')       //Checks whether value of data is equal to 0
      digitalWrite(7, LOW);   //If value is 0 then Relay turns OFF
      
    if(data == '7')            //Checks whether value of data is equal to 1
   { 
      digitalWrite(2, HIGH);     //Switch relay1 on
      digitalWrite(3, HIGH);     //Swtich relay2 on
      digitalWrite(4, HIGH);     //Swtich relay3 on
      digitalWrite(5, HIGH);     //Swtich relay4 on
      digitalWrite(6, HIGH);     //Swtich relay5 on
      digitalWrite(7, HIGH);     //Swtich relay6 on
   }   
    else if(data == 'G')       //Checks whether value of data is equal to 0
   { 
      digitalWrite(2, LOW);     //Switch relay1 off
      digitalWrite(3, LOW);     //Swtich relay2 off
      digitalWrite(4, LOW);     //Swtich relay3 off
      digitalWrite(5, LOW);     //Swtich relay4 off
      digitalWrite(6, LOW);     //Swtich relay5 off
      digitalWrite(7, LOW);     //Swtich relay6 off
   }   
  }                              
}                 
