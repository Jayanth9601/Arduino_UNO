int buttonval1; //button 1 state value
int buttonval2; //button 2 state value 
int button1=9; //button 1 is connected to pin 9
int button2=10; // button 2 is connected to pin 10
int LEDpin=6; //led is connected to pin 8
int LED=0; //Variable which will store ths led brigtness value
int buzzer=2; //buzzer is connected to the pin 8
int del=100; //delay time period
int DEL1=1000; //delay time period of buzzer

void setup() {
  Serial.begin(9600); //setting up the serial port
  pinMode(button1, INPUT); //Button 1 gets input from user
  pinMode(button1, INPUT); //Button 2 gets input from user
  pinMode(LED, OUTPUT); //led gives the output to the user
  pinMode(buzzer, OUTPUT);
}

void loop() {
  
  buttonval1 = digitalRead(button1); //reading value from button 1
  buttonval2 = digitalRead(button2); //reading value from button 2
  
  Serial.print("Button 1 = ");
  Serial.print(buttonval1);
  Serial.print("  Button 2 = ");
  Serial.println(buttonval2);

  if(buttonval1 == 0){     //If button 1 value is 0 then increase the
    LED = LED + 5;        //LED brightness by 5 
    
  }

  if(buttonval2 ==0){    //if button 2 value is 0 then decrease the
    LED = LED - 5;      //LED brightness by 5
   
  }

  if(LED >= 255){
    LED = 255;       //The value of LED should not be greater than 255
    digitalWrite(buzzer, HIGH);
    delay(DEL1);
    digitalWrite(buzzer, LOW);
  }

  if(LED <=0){
    LED = 0;         //the value of LED should not be less than 0
     digitalWrite(buzzer, HIGH);
     delay(DEL1);
     digitalWrite(buzzer, LOW);
  }

  Serial.print("LED = ");
  Serial.println(LED);
  analogWrite(LEDpin, LED);
  delay(del);

}
