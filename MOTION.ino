#define pirPin 23


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  if(motionDetected == HIGH)
  {
    Serial.println("MOTION DETECTED");
  }
  // put your main code here, to run repeatedly:
  delay(500); // this speeds up the simulation
}
