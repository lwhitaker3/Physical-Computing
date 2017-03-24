/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/
#define transPin 3 

int val;    // variable to read the value from the analog pin

void setup() {
  Serial.begin(9600);
  pinMode(transPin, OUTPUT);
}

void loop() {
  val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 255);
  Serial.println(val);
  // scale it to use it with the servo (value between 0 and 180)
  analogWrite(transPin, val);
}

