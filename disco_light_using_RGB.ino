int redpin=5;
int bluepin=6;
int greenpin=7;
int del=500;

void setup() {
pinMode(redpin, OUTPUT);
pinMode(bluepin, OUTPUT);
pinMode(greenpin, OUTPUT);
}

void loop() {
analogWrite(redpin, 225);
  analogWrite(greenpin, 225);
  analogWrite(bluepin, 0);

}
