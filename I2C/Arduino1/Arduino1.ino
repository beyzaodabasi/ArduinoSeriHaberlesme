#include <Wire.h>
int pot1=A0;
int pot1deger;
int pot2=A1;
int pot2deger;


void setup(){
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  
}
void loop(){
  delay(200);
}
void requestEvent(){
  pot2deger=analogRead(pot2);
  pot2deger=map(pot2deger, 0, 1023, 0, 180);
  Wire.write(pot2deger);
  
  pot1deger=analogRead(pot1);
  pot1deger=map(pot1deger, 0, 1023, 0, 180);
  if(pot1deger<90){
    Wire.write('a');
  }
  else if(pot1deger>90){
    Wire.write('b');
  }
  
}
  
