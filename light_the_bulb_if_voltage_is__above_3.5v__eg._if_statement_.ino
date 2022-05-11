int vpin=A0;//pin which is reading voltage from potentiometer
int alert=9; //pin which send's the alert signal if voltage is greater than 3.5v
float output; //variable which will store the read voltage
int del=500; //delay time

void setup() {
Serial.begin(9600);
pinMode(vpin, INPUT); //indecating that vpin is getting input
pinMode(alert, OUTPUT); //indecating that alert is a output giving pin
}

void loop() {
output=analogRead(vpin); //reading analog voltage from potentiometer
output=(5./1023)*output; //converting it 1023 into voltage
Serial.println(output);//printing output in serial moniter
if(output>3.5) // saying that execute the below statement if voltage is greater than 3.5v
{
  digitalWrite(alert, HIGH); //light the alert bulb if V > 3.5
}
else{
  digitalWrite(alert, LOW); //off the alert bulb if v < 3.5
}
delay(del);
} 
