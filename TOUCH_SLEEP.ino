#define THRESHOLD 30
#define LED_PIN 26 


RTC_DATA_ATTR int bootCount = 0;
touch_pad_t touchpin;

void setup(){       

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  touchSleepWakeUpEnable(T0, THRESHOLD);
  Serial.println("going to sleep now");
  esp_deep_sleep_start();
  Serial.println("this wil never ber printed");
  
}
void loop()
{

}