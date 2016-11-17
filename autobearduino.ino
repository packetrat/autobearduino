
#include <Servo.h>

Servo myservo;
int val = 0; 
char serialData;
boolean animate = false;
void setup()
{
  myservo.attach(9);
  myservo.write(90);
  Serial.begin(9600);
  while (!Serial) {;} // wait for serial port to connect. Needed for Leonardo only
}

void serialEvent()
{
  while(Serial.available())
  {
    serialData = (char)Serial.read();
    if (serialData == 'g'){
      animate = true;
      }
    if (serialData == 'x'){
      animate = false;
    }
  }  
}    
    
void loop()
{
  if (animate == true){
   for (val =100; val >= 1; val -= 10)
   {
    myservo.write(val);
    delay(15);
    }
   for (val = 1; val <= 100; val += 10)
   {
     myservo.write(val);
    delay(10);
   }
      
  }
  else {myservo.write(179);}
}
