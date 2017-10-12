#include <Wire.h>
#include<Servo.h>
#include "RTClib.h"
RTC_Millis rtc;
//Motor A
const int motorPin1  = 12;  
const int motorPin2  = 11;  
//Motor B
const int motorPin3  = 10; 
const int motorPin4  = 9; 
//Motor c
const int motorPin5  = 8; 
const int motorPin6  = 7;
//Motor D
const int motorPin7  = 6;
const int motorPin8  = 5;

int gyro_x, gyro_y, gyro_z;
long acc_x, acc_y, acc_z;
int type=0;
int temp_code[4];
int code[4];
byte element=0;
int tim;
int tim_last;
int x=0,y=0,z=0;
boolean enter=HIGH;
boolean act=LOW;
void setup() {
rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
Serial.begin(115200);
cal();
Serial.print("calibrating");
for(int i=0;i<5;++i)
{
  delay(200);
  Serial.print('.'); 
}
Serial.println();
Serial.println("Ready");
// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(motorPin5, OUTPUT);
    pinMode(motorPin6, OUTPUT);
    pinMode(motorPin7, OUTPUT);
    pinMode(motorPin8, OUTPUT);    
}

void loop() {
  low();
  DateTime now = rtc.now();
  enter=HIGH;
  read_mpu_6050_data();
  var();
   tim=now.second();
   if(act==LOW)
   tim_last=tim;
   type=process();
  if(enter==HIGH)
  if(type!=0)
  {
    Serial.println(type);
      tim=now.second();
     if(tim_last-tim<-5)
     {
      enter=LOW;
      clear_code();
      Serial.println("Reseting");
     }
     else
     {
      if(codef()==HIGH)
      {
      Serial.println("sequence registered"); 
      responce(check());
      }
     }
    
    delay(1000);
  }
}
