/**
 Author : Jayanth.s
 Date : 20/8/2020
 **/
int buttpin1 = 2;               //button is connected to the pin no 2
int buttpin2 = 3;               //button is connected to the pin no 3
int butt1;                      //variable to store the button1 state
int butt2;                     //variable to store the button2 state
int dir1 = 8;                  //IN1 is connected to pin 8
int dir2 = 9;                  //IN2 is connected to pin 9
int mspeed = 0;                //variable to store the speed of the motor
int speedpin = 10;             //EN is connected to pin 10
int del = 1000;                  //delay time period
int restdel = 3000;              //delay time period if speed is less than 100 or greater than -100

void setup() {
  Serial.begin(9600);           //setting up the serial moniter
  pinMode(dir1, OUTPUT);        //directionpin1 will give the output to motor
  pinMode(dir2, OUTPUT);        //directionpin2 will give the output to motor
  pinMode(speedpin, OUTPUT);    //Speedpin will give the output to motor
  pinMode(buttpin1, OUTPUT);     //butten pin 1 is output button state
  pinMode(buttpin2, OUTPUT);     //butten pin 2 is output button state
  digitalWrite(buttpin1, HIGH);    //Setting the butt1 high
  digitalWrite(buttpin2, HIGH);    //Setting the butt2 high

}

void loop() {

  butt1 = digitalRead(buttpin1);  //reading button state from button 1
  butt2 = digitalRead(buttpin2);  //reading button state from button 2
  
  if(butt1 == 0)
  {
    mspeed  = mspeed + 10;        //increase the speed by 10rpm if buttonis pushed
    delay(del);
  }

  if(butt2 == 0)
  {
    mspeed = mspeed - 10;        //decrease the speed by 10rpm if buttonis pushed
    delay(del);
  }

  if(mspeed == 15){
    mspeed = 110;                //if the mspeed is 10 then set it to 100
  }

  if(mspeed == -15){
    mspeed = -110;              //if the mspeed is -10 then set it to -100
  }

  if((mspeed == 100) || (mspeed == -100)){
    mspeed = 0;                            //if the speed decrease less than 100 or greater than -100 then reset it to 90
    delay(restdel);
  }

  if(mspeed > 255){  
     mspeed = 255;                //if the speed is greater than 255 than reset it to 255
  }

  if(mspeed < -255){  
     mspeed = -255;                //if the speed is less than -255 than reset it to -255
  }

  if(mspeed > 109){
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      analogWrite(speedpin, mspeed);   //sending the motor speed to the motor
  }

  if(mspeed < -109){
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      analogWrite(speedpin, -mspeed);   //sending the motor speed to the motor
  }
  
  Serial.print("motor speed :  ");
  Serial.println(mspeed);
  Serial.println(butt1);
  Serial.println(butt2);
  
}
