#include <string.h>
int duty;

/* const int PWM1 = 10; //left front motor
  const int PWM2 = 11; //right front motor
  const int PWM3 = 6; //left rear motor
  const int PWM4 = 9; //right rear motor*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT); //enable B pin, and motor pwm pin (controls speed)
  pinMode(13,OUTPUT); //H-Bridge pin IN4
  pinMode(12,OUTPUT); //H-Bridge pin IN3
  pinMode(6,OUTPUT);//enable A pin
  pinMode(11,OUTPUT); //IN2
  pinMode(10,OUTPUT); //IN1 

  /*
   *****H-Bridge Input Table*************
   
          0 - IN3 0 - IN4 Brakem
          0 - IN3 1 - IN4 Forward
          1 - IN3 0 - IN4 Reverse
          1 - IN3 1 - IN4 Brake
  ****************************************
  */
}


void motorWrite(int PWM, int dutyCycle) { //write to the 4 motors
  //const int PWM1 = 10; //left front motor
  //const int PWM2 = 11; //right front motor
  //const int PWM3 = 12; //left rear motor
  //const int PWM4 = 13; //right rear motor
  int PWM_outpin = PWM;
  analogWrite(PWM, dutyCycle);
  //analogWrite(PWM2,dutyCycle);
  //analogWrite(PWM3,dutyCycle);
  //analogWrite(PWM4,dutyCycle);

}



void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Input which function to run from the following options: \n");
  Serial.print("forward, reverse, right, left \n");
  
  
  //motorWrite(13, 255); //figure out a way to reverse the direction ---- 150 = medium speed, 255 = max

    while(!Serial.available());

    
    if(Serial.available()){
        String s = Serial.readString();
        if(s != "forward" && s != "left" && s!="right" && s!="reverse"){
            Serial.println("Not Understood");
            
        }
        else{
          Serial.println("Enter desired duty cycle (enter value from 0 - 255): ");
          while(!Serial.available());
          duty = Serial.parseInt();
          Serial.parseInt();
        }
        
          if(s == "forward"){
              Serial.println("Forward function executing at: ");
              Serial.print(duty);
              Serial.println("\n");
                digitalWrite(13,HIGH); //1     11,12 control right motor
                digitalWrite(12,LOW);  //0
                
                analogWrite(9,duty); //right motor
                digitalWrite(11,HIGH);  //1    8,9 control left motor
                digitalWrite(10,LOW);   //0
                analogWrite(6,duty); //left motor
                delay(5000);

                  //brake, stop
                digitalWrite(13,LOW); //right
                digitalWrite(12,LOW);
                digitalWrite(11,LOW); //left
                digitalWrite(10,LOW);
                delay(2000);

                Serial.println("Forward function Completed.\n");
              
          }
          else if(s == "reverse"){
        
              Serial.println("Reverse function executing at: ");
              Serial.print(duty);
              Serial.println("\n");
                //reverse
                digitalWrite(13,LOW);  //0
                digitalWrite(12,HIGH); //1
                analogWrite(9,duty); //right
                digitalWrite(11,LOW);   //0
                digitalWrite(10,HIGH);  //1
                analogWrite(6,duty); //left
                delay(5000); 


                  //brake, stop
                digitalWrite(13,LOW); //right
                digitalWrite(12,LOW);
                digitalWrite(11,LOW); //left
                digitalWrite(10,LOW);
                delay(2000);

              Serial.println("Reverse function Completed.\n");
              
          }
          else if(s =="left"){
            Serial.println("Left function executing at: ");
            Serial.print(duty);
            Serial.println("\n");
            //left --- right motor moves forward, left motor stationary
            digitalWrite(13,HIGH);  //1
            digitalWrite(12,LOW);   //0
            analogWrite(9,duty); //right
            digitalWrite(11,LOW);    //1, make left wheels turn reverse for larger pivot
            digitalWrite(10,HIGH);    //0
            analogWrite(6,(int)(duty/2)); //left; cut duty cycle by half to allow the car to effectively turn better
            delay(2000);
          

                  //brake, stop
                digitalWrite(13,LOW); //right
                digitalWrite(12,LOW);
                digitalWrite(11,LOW); //left
                digitalWrite(10,LOW);
                delay(2000);
              
             Serial.println("Left function Completed.\n");
            //analogWrite(3,100);//analogWrite(pin#,0-255)
            
          }
          else if(s == "right"){
              Serial.println("Right function executing at: ");
              Serial.print(duty);
              Serial.println("\n");

              //right --- left motor moves forward, right moves in reverse direction at slower rate
                digitalWrite(13,LOW); //1, make right wheel turn reverse for larger pivot
                digitalWrite(12,HIGH); //0
                analogWrite(9,(int)(duty/2)); //right; cut duty cycle by half to allow the car to effectively turn better
                digitalWrite(11,HIGH); //1
                digitalWrite(10,LOW);  //0
                analogWrite(6,duty); //left
                delay(2000);
              

                  //brake, stop
                digitalWrite(13,LOW); //right
                digitalWrite(12,LOW);
                digitalWrite(11,LOW); //left
                digitalWrite(10,LOW);
                delay(2000);
                
              Serial.println("Right function Completed.\n");
          }

        }

}
