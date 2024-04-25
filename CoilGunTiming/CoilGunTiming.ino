byte button = 4;
unsigned long startTime;
unsigned long endTime;
unsigned long duration;
byte timerRunning;
void setup(){
pinMode (button, INPUT_PULLUP);
Serial.begin(9600);
}
void loop(){
  if (timerRunning == 0 && digitalRead(button) == LOW){ // button pressed & timer not running already
  startTime = millis();
  timerRunning = 1;
  Serial.print ("no");
  }
  if (timerRunning == 1 && digitalRead(button) == HIGH){ // timer running, button released
  endTime = millis();
  timerRunning = 0;
  duration = endTime - startTime;
  Serial.print ("button press time in milliseconds: ");
  Serial.println (duration);
  }
}
