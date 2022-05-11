/**
 Author : Jayanth.s
 Date : 16/8/2020
 **/

int dir1 = 10;                  //IN1 is connected to pin 10
int dir2 = 11;                  //IN2 is connected to pin 11
int speedpin = 9;               //EN1 is connected to pin 9
float mspeed;                     //variable to store the speed of the motor
int vry = A3;                   //VRY Pin is connected to pin A1
int ValY;                       //variable to store the y axis value of joystick

void setup() {
  Serial.begin(9600);          //setting up the serial moniter
  pinMode(dir1, OUTPUT);       //directionpin1 will give the output to motor
  pinMode(dir2, OUTPUT);       //directionpin2 will give the output to motor
  pinMode(speedpin, OUTPUT);   //Speedpin will give the output to motor
  pinMode(vry, INPUT);         //VRY pin will get the input from joystick y axis
}

void loop() {
  ValY = analogRead(vry);      //taking input from joystick

  Serial.println(ValY);

  if(ValY < 504){                //if y axis value is in between 0 and 504 then enter the statement  
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);                       //Let the motor spin clockwise at the speed of mspeed
    mspeed = ( ((-255./504.) * ValY) + 255);
    analogWrite(speedpin, mspeed);   
  }

  else if(ValY > 504){          //if y axis value is in between 504 and 1023 then enter the statement
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);                       //Let the motor spin anticlockwise at the speed of mspeed
    mspeed = ( (255./519.) * (ValY-504) );
    analogWrite(speedpin, mspeed);   
  }

  else if(ValY == 504){                           //if y axis value is equal 512 then enter the statement
    digitalWrite(speedpin, 0);                    //let the motor de off
  }

}
