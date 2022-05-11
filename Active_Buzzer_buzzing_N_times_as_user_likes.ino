int buzzNumb; //variable to store the no of buzz's
int buzzer=8; //setting buzzer variable as 8
int del=500; //delay time period
int i; //looping variable

void setup() {
Serial.begin(9600); //Setting up the serial moniter
pinMode(buzzer, OUTPUT); //indicating buzzer as output device
}

void loop() {
Serial.println("Enter the no. of buzz's you would like : "); //asking for input
while(Serial.available()==0){
  
} //waiting for input
buzzNumb=Serial.parseInt(); //taking input

for(i=1; i<=buzzNumb; i++) //creating a loop for buzzer
{
   digitalWrite(buzzer, HIGH);
   delay(del);
   digitalWrite(buzzer, LOW);
   delay(del);
}

}
