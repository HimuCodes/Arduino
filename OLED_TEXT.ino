#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(115200);
  
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("Fialed to start SSD1306 OLED"));
    while(1);
  }
  delay(2000);

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(0,10);
  oled.println("DEUS EX MACHINA");
  oled.display();
}

void loop()
{
  
}
