const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
bool pressStarted = false;
bool pressFinished = false;
int motorState = 0;
void
setup()
{
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void
loop()
{
 // see if switch pressed down
  switchState = digitalRead(switchPin);
  // if haven't recorded press start and switch pressed down 
  if (!pressStarted && switchState == HIGH) {
      pressStarted = true;
  }
  // if we have recorded press start and switch is no longer pressed down
  // set state to press finished
  if (pressStarted && switchState == LOW) {
      pressStarted = false;
      pressFinished = true;
  }
  // when press finished switch the motor on->off or off->on
  if (pressFinished) {
      if (motorState == LOW) {
          motorState = HIGH;
      } else {
          motorState = LOW;
      }
      digitalWrite(motorPin,motorState);
      pressFinished = false;
  }
}