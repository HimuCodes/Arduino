#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <BluetoothSerial.h>

#define DHT_SENSOR_PIN 13
#define DHT_SENSOR_TYPE DHT11

#define PIN_RED 25
#define PIN_GREEN 32
#define PIN_BLUE 33

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

BluetoothSerial SerialBT;
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
float tempC;
String tempstring;

TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;
TaskHandle_t Task4;

void Task1code(void* pvParameters) {
  for (;;) {
     tempC = dht_sensor.readTemperature();

    if (!isnan(tempC)) {
      Serial.print("Task1 - Temperature: ");
      Serial.print(tempC);
      Serial.println("°C");
    }

    delay(1000);
  }
}

void Task2code(void* pvParameters) {
  for (;;) {


    if (tempC <= 30) {
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      digitalWrite(PIN_BLUE, LOW);
    } else {
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      digitalWrite(PIN_BLUE, LOW);
    }

    delay(1000);
  }
}

void Task3code(void* pvParameters) {
  for (;;) {


    Serial.print("Task3 - Temperature: ");
    Serial.print(tempC);
    Serial.println("°C");

    oled.clearDisplay();
    oled.setTextSize(2);
    oled.setTextColor(WHITE);
    oled.setCursor(10, 0);
    oled.println("Temp: ");
    oled.print(tempC);
    oled.print("°C");
    oled.display();

    delay(1000);
  }
}

void Task4code(void* pvParameters) {

  for (;;) {
    tempstring = String(tempC);
    SerialBT.println(tempstring);

    delay(1000);
  }
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("HIMU ATR");

  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);

  dht_sensor.begin();

  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Failed to start SSD1306 OLED"));
    while (1)
      ;
  }

  xTaskCreatePinnedToCore(Task1code, "Task1", 2000, NULL, 1, &Task1, 0);
  xTaskCreatePinnedToCore(Task2code, "Task2", 2000, NULL, 1, &Task2, 1);
  xTaskCreatePinnedToCore(Task3code, "Task3", 4000, NULL, 1, &Task3, 0);
  xTaskCreatePinnedToCore(Task4code, "Task4", 4000, NULL, 1, &Task4, 1);

  delay(10);
}

void loop() {
}