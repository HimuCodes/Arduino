
#define uS_TO_S_FACTOR 1000000  
#define TIME_TO_SLEEP  60
#define LED_PIN 26        

RTC_DATA_ATTR int bootCount = 0;

void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  Serial.println("Going to sleep now");

  esp_deep_sleep_start();
  Serial.println("This will never be printed");
}

void loop()
{

}
 