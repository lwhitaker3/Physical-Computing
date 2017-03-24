/****************************************
Example Sound Level Sketch for the 
Adafruit Microphone Amplifier
****************************************/

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

boolean changing = false;

//const int happy = 8;
//const int surprised = 9;
//const int mad = 10;

int faces[] = {8, 9, 10};
int index = 0;

void setup() 
{
   Serial.begin(9600);

   for(int i=0; i<3; i++){
    pinMode(faces[i], OUTPUT);
   }
}


void loop() 
{
   unsigned long startMillis= millis();  // Start of sample window
   unsigned int peakToPeak = 0;   // peak-to-peak level

   unsigned int signalMax = 0;
   unsigned int signalMin = 1024;

   // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
   {
      sample = analogRead(0);
      if (sample < 1024)  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;  // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;  // save just the min levels
         }
      }
   }
   peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
   double volts = (peakToPeak * 5.0) / 1024;  // convert to volts

       Serial.println(volts);


   if(volts>1 && changing == false){
    changing == true;
    digitalWrite(faces[index], HIGH);
    if (index == 0){
      digitalWrite(faces[2], LOW);
    }else{
      digitalWrite(faces[index-1], LOW);
    };
    index++;
    if (index > 2){
      index = 0;
    }
//    Serial.println(index);
    changing = false;
   }
    
}
