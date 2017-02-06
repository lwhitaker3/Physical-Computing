#define ledRed 3
#define switchRed 2

#define ledGreen 12
#define switchGreen 13

int switchRedState = 0;
int switchGreenState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(ledRed, OUTPUT);
  pinMode(switchRed, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(switchGreen, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledRed,switchRedState);
  digitalWrite(ledGreen,switchGreenState);


  switchRedState = digitalRead(switchRed);
  switchGreenState = digitalRead(switchGreen);
  
  Serial.print("switchRedState: ");
  Serial.print(switchRedState);
  Serial.print("   switchGreenState: ");
  Serial.println(switchGreenState);

}
