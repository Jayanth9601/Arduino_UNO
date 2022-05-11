byte mybyt = 0xF8;
int del = 1000;

void setup() {
Serial.begin(9600);
}

void loop() {
Serial.print(mybyt, HEX);
Serial.print("   ");
Serial.print(mybyt, BIN);
Serial.print("   ");
Serial.print(mybyt, DEC);
Serial.println("   ");

mybyt = mybyt + 1;
delay(del);

}
