#define buzzer 3
#define pingPin 7
#define nose 2
#define mic 0

#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 

int tune[] = {C,f,a};

long blinkRate;
unsigned long pingMillis = 0;
unsigned long blinkMillis = 0;
int ledState = LOW;

boolean played = false;

const int sampleWindow = 250; // Sample window width in mS (250 mS = 4Hz)
unsigned int knock;
int ledPin = 8;
int interval = 1000;
long detectionSpanInitial = 0;
long detectionSpan = 0;
boolean lightState = false;
int claps = 0;

int mouths[] = {8, 9, 10};
int index = 0;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(nose, OUTPUT);
  for(int i=0; i<3; i++){
    pinMode(mouths[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  distanceDetector();
  clapDetector();
}

void distanceDetector(){
  unsigned long currentMillis = millis();
  long duration;
  long cm;
  
  if (currentMillis - pingMillis >= 100) {
    pingMillis = currentMillis;
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
  
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
  
    cm = microsecondsToCentimeters(duration);
  
//    Serial.print(cm);
//    Serial.print("cm");
//    Serial.println();

    if(cm<12 && cm>=8){
      blinkRate = 400;
      played = false;
      if (currentMillis - blinkMillis >= blinkRate) {
        blinkMillis = currentMillis;
    
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
    
        // set the LED with the ledState of the variable:
        Serial.print("blink");

        digitalWrite(nose, ledState);
      }
    }else if(cm<8 && cm>=4){
      blinkRate = 200;
      played = false;
      if (currentMillis - blinkMillis >= blinkRate) {
        blinkMillis = currentMillis;
    
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
    
        // set the LED with the ledState of the variable:
        digitalWrite(nose, ledState);
        Serial.print("blink");

      }
    }else if(cm<4){
      digitalWrite(nose, HIGH);
      playTune();
    }else{
      digitalWrite(nose,LOW);
      played = false;
    }
  }

}

void playTune(){
  while(played==false){
    for (int i=0; i<3; i++) {
      tone(buzzer, tune[i],100);
      delay(100);
//      Serial.print(tune[i]);
//      Serial.print("    ");
//      Serial.println(i);
      if(i==2){
        played = true;
      }
    }
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void clapDetector(){
 unsigned long start = millis();  // Start of sample window
 unsigned int peakToPeak = 0;   // peak-to-peak level

 unsigned int signalMax = 0;
 unsigned int signalMin = 1024;

 // collect data for 250 miliseconds
 while (millis() - start < sampleWindow)
 {
   knock = analogRead(mic);
      if (knock < 1024)  //This is the max of the 10-bit ADC so this loop will include all readings
      {
         if (knock > signalMax)
         {
           signalMax = knock;  // save just the max levels
         }
      else if (knock < signalMin)
        {
         signalMin = knock;  // save just the min levels
         }
     }
 }
 peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
 double volts = (peakToPeak * 3.3) / 1024;  // convert to volts

 Serial.println(volts);
 if (volts >=1.0){
    if (claps == 0)
    {
      detectionSpanInitial = detectionSpan = millis();
      claps++;
    }
    else if (claps > 0 && millis()-detectionSpan >= 50)
    {
      detectionSpan = millis();
      claps++;
    }
 } 
 
 if (millis()-detectionSpanInitial >= 400) {
    if (claps == 2) {
      digitalWrite(mouths[index], HIGH);
      if (index == 0){
        digitalWrite(mouths[2], LOW);
      }else{
        digitalWrite(mouths[index-1], LOW);
      };
      index++;
      if (index > 2){
        index = 0;
      }
    }
    claps = 0;
  }
}

