int vrx=A0; //pin vrx is connected to A0
int vry = A3; //pin vry is connected to A3
int sw=2;  //switch pin is connected to 2
int Xvalue; //variable to store X axis value
int Yvalue; //variable to store Y axis value
int Svalue; //variable to store Switch value
int del=500; //delay time period

void setup() {
  Serial.begin(9600); //setting up the serial port
  pinMode(vrx, INPUT); //saying vrx terminal is input terminal
  pinMode(vry, INPUT); //saying vry terminal is input terminal
  pinMode(sw, INPUT); //saying switch terminal is input terminal
  digitalWrite(sw, HIGH); 

}

void loop() {
  Xvalue = analogRead(vrx); //reading the joystick's x axis potentiometer value
  Yvalue = analogRead(vry); //reading the joystick's y axis potentiometer value
  Svalue = digitalRead(sw);  //reading switch value from joystick
  Serial.print("The VRX value is = ");
  Serial.print(Xvalue);
  Serial.print("  The VRY value is = ");
  Serial.print(Yvalue);
  Serial.print("  Switch value = ");
  Serial.println(Svalue);
  delay(del);

}
