# define buzzer 3

#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 

int tune[] = {C,f,a};

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
boolean played = false;

void loop() {
  // put your main code here, to run repeatedly:
  while(played==false){
    for (int i=0; i<3; i++) {
    tone(buzzer, tune[i],100);
    delay(100);
    Serial.print(tune[i]);
    Serial.print("    ");
    Serial.println(i);
    if(i==2){
      played = true;
    }
  }
  }

    

}
