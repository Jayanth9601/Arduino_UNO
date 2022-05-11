/**
 Author : Jayanth.s
 Date : 10/8/2020
 **/
#include <Servo.h>
int vrx=A0; //pin of vrx
int vry=A2; //pin of vry
int sw=3;   //pin of switch
int Xvalue; //variable to store X axis value
int Yvalue; //variable to store Y axis value
int Svalue; //variavle to store switch value
int ser=6;  //pin of servo
float angle;  //variable to servo values
int del=100; //delay time period
int buzzer=8;  //buzzer pin
Servo myservo; //name of my servo

void setup() {
  Serial.begin(9600); //setting up the serial port
  myservo.attach(ser); //indicating myservo is connected to pin 6(ser)
  pinMode(vrx, INPUT); //vrx is input terminal
  pinMode(vry, INPUT); //vry is input terminal
  pinMode(sw, INPUT); //switch is input terminal
  pinMode(ser, OUTPUT); //Servo terminal is output 
  pinMode(buzzer, OUTPUT); //Buzzer terminal is output
  digitalWrite(sw, HIGH); //Setting servo pin high
}

void loop() {
  Xvalue = analogRead(vrx); //reading values from vrx and storing into Xvalue
  Yvalue = analogRead(vry); //reading values from vry and storing into Yvalue
  Svalue = digitalRead(sw); //reading switch value
  Serial.println(Svalue);
  angle = ((180./1023.)*Xvalue);

  if(Svalue == 0){
     digitalWrite(buzzer, HIGH);  //telling the buzzer to buzz if sw is 0
     delay(del);
     digitalWrite(buzzer, LOW);
  }
  
  myservo.write(angle);
  delay(del);

}
