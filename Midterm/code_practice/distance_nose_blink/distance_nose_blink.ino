const int pingPin = 7;
const int nose = 2;
const int buzzer = 3;

long blinkRate;
unsigned long previousMillis = 0;
int ledState = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(nose, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  unsigned long currentMillis = millis();

  long duration;
  long cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);

  if(cm<8 && cm>=6){
    blinkRate = 1000;
      noTone(buzzer);
      if (currentMillis - previousMillis >= blinkRate) {
        previousMillis = currentMillis;
    
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
    
        // set the LED with the ledState of the variable:
        digitalWrite(nose, ledState);
      }
    }else if(cm<6 && cm>=4){
      blinkRate = 200;
      noTone(buzzer);
      if (currentMillis - previousMillis >= blinkRate) {
        previousMillis = currentMillis;
    
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
    
        // set the LED with the ledState of the variable:
        digitalWrite(nose, ledState);
      }
    }else if(cm<4){
      digitalWrite(nose, HIGH);
      tone(buzzer, 1000);
    }else{
      digitalWrite(nose,LOW);
      noTone(buzzer);
    }
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
