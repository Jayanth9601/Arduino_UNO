
int datapin = 12;    //the data pin DS is connected to pin 12
int latchpin = 11;   //the latch pin ST_CP is connected to pin 11
int clockpin = 9;    //the clock pin SH_CP is connected to pin 9
int  del = 500;
byte mybyte = 0xAA;     //the led output value

void setup() {
  Serial.begin(9600); //setting up the serial moniter
  pinMode(datapin, OUTPUT);   //datapin take output from arduino
  pinMode(latchpin, OUTPUT);   //latchpin take output from arduino
  pinMode(clockpin, OUTPUT);   //clockpin take output from arduino
}

void loop() {
  digitalWrite(latchpin, LOW);  //Saying that data is entering to shift IC
  shiftOut(datapin, clockpin, LSBFIRST, mybyte);  //giving input ot the shift registor 
  digitalWrite(latchpin, HIGH);  //Saying that data has stopped entering to shift IC
  Serial.println(mybyte, BIN);
  
  //mybyte = mybyte / 2;    //command used for right shift of the bytes

  mybyte *= 2;              //command used for left shift of the bytes
  delay(del);
}
