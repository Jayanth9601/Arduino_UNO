int SoundSen=9;
int lapstime = 10;  //amound of time to take readings
unsigned long end_time = 0;  //time while ending to take reading
unsigned long present_time; //time at the movement
unsigned long time_elapsed = 0; //time elapsed from start
int soundvalue = 0;

void setup() {
  Serial.begin(9600);     //setting up the serial moniter
  pinMode(SoundSen, INPUT);

}

void loop() {
  present_time = millis(); //reading the present time
  time_elapsed = present_time - end_time;

  if(digitalRead(SoundSen) == LOW)
  {
    soundvalue++;
  }

  if(time_elapsed >= lapstime)
  {
    Serial.println(soundvalue);
    end_time = present_time;
    soundvalue = 0;
  }

}
