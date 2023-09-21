#define TOUCH_PIN 4
#define LED_PIN 26

int touchValue = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP32 TOUCH");

}

void loop()
{
  touchValue = touchRead(TOUCH_PIN);
  if(touchValue <= 30)
  {
    digitalWrite(LED_PIN,HIGH);
    Serial.println("LED IS ON");
  }
  else
  {
    
   digitalWrite(LED_PIN,LOW);
    Serial.println("LED IS OFF");
  }
  Serial.println(touchValue);
  delay(100);
}
