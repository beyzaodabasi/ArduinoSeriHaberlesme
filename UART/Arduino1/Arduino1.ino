int pot1=A0;
int pot1deger; 
int pot2=A1;
int pot2deger;

void setup(){
  
  Serial.begin(9600);
  
}
void loop(){
  
  pot2deger=analogRead(pot2);
  pot2deger=map(pot2deger, 0, 1023, 0, 180);
  Serial.write(pot2deger);
  pot2deger=0;
  
  pot1deger=analogRead(pot1);
  pot1deger=map(pot1deger, 0, 1023, 0, 180);
  
  if(pot1deger>90){
    Serial.write('a');
  }
  else if(pot1deger<90){
    Serial.write('b');
  } 
    
}
