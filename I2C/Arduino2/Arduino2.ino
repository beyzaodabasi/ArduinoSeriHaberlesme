#include <Wire.h>
#include <Servo.h>

Servo servo;
int dcmotor1=2;
int dcmotor2=3;
int led1=12;
int led2=13;
int servoMotor=7;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(dcmotor1, OUTPUT);
  pinMode(dcmotor2, OUTPUT);
  servo.attach(servoMotor);
}
void loop() {
  Wire.requestFrom(8, 4);
  while(Wire.available()){
    
    int y = Wire.read();
    Serial.println(y);
    servo.write(y);
    y=0;
    
    char x = Wire.read();
    Serial.println(x); 
    if (x == 'a') { 
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(dcmotor1, HIGH);
      digitalWrite(dcmotor2, LOW);
    }
    else if (x == 'b') { 
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(dcmotor2, HIGH);
      digitalWrite(dcmotor1, LOW);    
    }
  }
  
}
