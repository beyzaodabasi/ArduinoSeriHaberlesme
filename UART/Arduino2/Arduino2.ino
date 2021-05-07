#include <Servo.h>
Servo servo;

int dcmotor1=2;
int dcmotor2=3;
int led1=12;
int led2=13;
int servoMotor=7;

void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(dcmotor1, OUTPUT);
  pinMode(dcmotor2, OUTPUT);
  servo.attach(servoMotor);
  
}
void loop() {
  if (Serial.available() > 0) {   
    
    int y = Serial.read();
    Serial.println(y);
    servo.write(y);
    y=0;
    
    char x = Serial.read();
    Serial.print(x);
    if (x == 'a') { 
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      digitalWrite(dcmotor2, HIGH);
      digitalWrite(dcmotor1, LOW);
    }
    else if (x == 'b') { 
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(dcmotor1, HIGH);
      digitalWrite(dcmotor2, LOW);    
    } 
    
  }
}
