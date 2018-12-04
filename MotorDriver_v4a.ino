#include <string.h>
int duty;

/* const int PWM1 = 10; //left front motor
  const int PWM2 = 11; //right front motor
  const int PWM3 = 12; //left rear motor
  const int PWM4 = 13; //right rear motor*/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT); //enable pin, and motor pwm pin (controls speed)
  pinMode(12,OUTPUT); //H-Bridge pin IN4
  pinMode(11,OUTPUT); //H-Bridge pin IN3
  pinMode(10,OUTPUT);//enable A pin
  pinMode(9,OUTPUT); //IN2
  pinMode(8,OUTPUT); //IN1 

  /*
   *****H-Bridge Input Table*************
   
          0 - IN3 0 - IN4 Brakem
          0 - IN3 1 - IN4 Forward
          1 - IN3 0 - IN4 Reverse
          1 - IN3 1 - IN4 Brake
  ****************************************
  */
}

/*void motorDrive(int dutyCycle,bool val){
  const int PWM1 = 10; //left front motor
  const int PWM2 = 11; //right front motor
  const int PWM3 = 12; //left rear motor
  const int PWM4 = 13; //right rear motor
  if(val ==true){
  forward(dutyCycle);
  }
  else{
  reverse(dutyCycle);
  }
  }*/
/*void forward(int dutyCycle) { //move all motors forward at same speed
  digitalWrite(12,1);
  digitalWrite(11,0);
  motorWrite(13, 255);*/
  /*motorWrite(PWM2,255);
    motorWrite(PWM3,255);
    motorWrite(PWM4,255);
  delay(2000); // continue for 2 seconds
  motorWrite(13, 0); //stop all the motors
  /*motorWrite(PWM2,0);
    motorWrite(PWM3,0);
    motorWrite(PWM4,0);*/

/*void reverse(int dutyCycle) { //move all motors backwards at same speed
  digitalWrite(12,0);
  digitalWrite(11,1);
  motorWrite(13, 255); //figure out a way to reverse the direction ---- 150 = medium speed, 255 = max
  /*motorWrite(PWM2,255);
    motorWrite(PWM3,255);
    motorWrite(PWM4,255);
  delay(2000); // continue for 2 seconds*/

 // motorWrite(13, 0); //stop all the motors
  /*motorWrite(PWM2,0);
    motorWrite(PWM3,0);
    motorWrite(PWM4,0);*/


/*void right(int dutyCycle){ //move the two front
  //digitalWrite(hb1,1);
  //digitalWrite(hb2,0);
  //motorWrite(dutycle);
  delay(2000); // continue for 2 seconds
  motorWrite(PWM13,0); //stop all the motors
  motorWrite(PWM2,0);
  motorWrite(PWM3,0);
  motorWrite(PWM4,0);
  }
  /*void left(int dutyCycle){
  //digitalWrite(hb1,1);
  //digitalWrite(hb2,0);
  //motorWrite(dutycle);
  delay(2000); // continue for 2 seconds
  motorWrite(13,0); //stop all the motors
  /*motorWrite(PWM2,0);
  motorWrite(PWM3,0);
  motorWrite(PWM4,0);
  }*/
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
  
//  //forward(255);
//  digitalWrite(12,1);
//  digitalWrite(11,0);
//  digitalWrite(13,HIGH);
//  digitalWrite(10,HIGH);
//  delay(5000);
//
//  //brake, stop
//  digitalWrite(12,0);
//  digitalWrite(11,0);
//  delay(2000);
//  
// 
//  //reverse
//  digitalWrite(12,0);
//  digitalWrite(11,1);
//  digitalWrite(13,HIGH);
//  digitalWrite(10,HIGH);
//  delay(5000); 
//
//  
//  //brake, stop
//  digitalWrite(12,0);
//  digitalWrite(11,0);
//  delay(2000);
//
//
//  //left
//  digitalWrite(12,1);
//  digitalWrite(11,0);
//  digitalWrite(13,HIGH);
//  //digitalWrite(10,HIGH);
//  delay(5000);
//
//  //brake, stop
//  digitalWrite(12,0);
//  digitalWrite(11,0);
//  delay(2000);
//  //analogWrite(3,100);//analogyWrite(pin#,0-255)

  //right
//  digitalWrite(12,1);
//  digitalWrite(11,0);
//  //digitalWrite(13,HIGH);
//  digitalWrite(10,HIGH);
//  delay(5000);
  
  
  //motorWrite(13, 255); //figure out a way to reverse the direction ---- 150 = medium speed, 255 = max

    while(!Serial.available());

    
    if(Serial.available()){
        String s = Serial.readString();
        if(s != "forward" && s != "left" && s!="right" && s!="reverse"){
            Serial.println("Not Understood");
            
        }
        else{
          Serial.println("Duty Cycle has been set to 255 by default.");
          //while(!Serial.available());
          //duty = Serial.parseInt();
          //Serial.parseInt();
        }
        
       
        
          if(s == "forward"){
              Serial.println("Forward function will execute\n");
               //forward(255);
                digitalWrite(12,HIGH); //1     11,12 control right motor
                digitalWrite(11,LOW);  //0
                digitalWrite(13,HIGH); //right motor
                digitalWrite(9,HIGH);  //1    8,9 control left motor
                digitalWrite(8,LOW);   //0
                digitalWrite(10,HIGH); //left motor
                delay(5000);

                  //brake, stop
                digitalWrite(12,LOW); //right
                digitalWrite(11,LOW);
                digitalWrite(9,LOW); //left
                digitalWrite(8,LOW);
                delay(2000);
              
          }
          else if(s == "reverse"){
        
              Serial.println("Reverse function will execute\n");
                //reverse
                digitalWrite(12,LOW);  //0
                digitalWrite(11,HIGH); //1
                digitalWrite(13,HIGH); //right
                digitalWrite(9,LOW);   //0
                digitalWrite(8,HIGH);  //1
                digitalWrite(10,HIGH); //left
                delay(5000); 

  
                //brake, stop
                digitalWrite(12,LOW);//right
                digitalWrite(11,LOW);
                digitalWrite(9,LOW); //left
                digitalWrite(8,LOW);
                delay(2000);

          }
          else if(s =="left"){
            Serial.println("Left function will execute\n");
            
            //left --- right motor moves forward, left motor stationary
            digitalWrite(12,HIGH);  //1
            digitalWrite(11,LOW);   //0
            digitalWrite(13,HIGH); //right
            digitalWrite(9,LOW);    //0
            digitalWrite(8,LOW);    //0
            digitalWrite(10,HIGH); //left
            delay(2000);
          
            //brake, stop
            digitalWrite(12,LOW);
            digitalWrite(11,LOW);
            digitalWrite(9,LOW);
            digitalWrite(8,LOW);
            delay(2000);
            //analogWrite(3,100);//analogyWrite(pin#,0-255)
            
          }
          else if(s == "right"){
            Serial.println("Right function will execute\n");

              //right --- left motor moves forward, right motor stationary
                digitalWrite(12,LOW); //0
                digitalWrite(11,LOW); //0
                digitalWrite(13,HIGH); //right
                digitalWrite(9,HIGH); //1
                digitalWrite(8,LOW);  //0
                digitalWrite(10,HIGH); //left
                delay(2000);
              
                //brake, stop
                digitalWrite(12,LOW);//right
                digitalWrite(11,LOW);
                digitalWrite(9,LOW); //left
                digitalWrite(8,LOW);
                delay(2000);
          }

        }

}
