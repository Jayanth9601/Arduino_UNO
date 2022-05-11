int buzzValue; //varialble to take the potentiometer value in
int buzzer=8; //setting variable buzzer as 8
int potentiometer=A0; //setting variable potentiometer as A0

void setup() {
Serial.begin(9600); //setting up serial port
pinMode(buzzer, OUTPUT); //indicating buzzer as an output terminal
pinMode(potentiometer, INPUT); // indicating potentiometer as input terminal
}

void loop() {
buzzValue=analogRead(potentiometer); // reading potentiometer
Serial.println(buzzValue);
if(buzzValue>700) //Creating if conduction to buzz if buzzValue is greater than 700
{
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}
delay(2000);

}
