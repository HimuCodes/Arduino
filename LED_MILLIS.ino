#define led1 25
#define led2 26

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

const long interval1 = 1000;
const long interval2 = 1000;

int ledstate1 = LOW;
int ledstate2 = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis1 >= interval1)
  {
    previousMillis1 = currentMillis;
    ledstate1 = !ledstate1;
    digitalWrite(led1,ledstate1);
  }
  else if(currentMillis - previousMillis2 >= interval2)
  {
    previousMillis2 = currentMillis;
    ledstate2 = !ledstate2;
    digitalWrite(led2,ledstate2);
  } 
}