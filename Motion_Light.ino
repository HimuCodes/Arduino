#define pirPin 23

#define PIN_RED 25
#define PIN_BLUE 32
#define PIN_GREEN 33



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
   pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  if(motionDetected == HIGH)
  {
    Serial.println("MOTION DETECTED");
    analogWrite(PIN_RED, 255);
  analogWrite(PIN_GREEN, 0);
  analogWrite(PIN_BLUE, 0);
  
  }
  else
  {
      analogWrite(PIN_RED, 0);
  analogWrite(PIN_GREEN, 255);
  analogWrite(PIN_BLUE, 0);
  


  }
  // put your main code here, to run repeatedly:
  delay(500); // this speeds up the simulation
}