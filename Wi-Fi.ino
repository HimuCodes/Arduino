#include<WiFi.h>

const char* WIFI_SSID = "Board_Room";
const char* WIFI_PASSWORD = "12345678";

void setup()
{
Serial.begin(115200);
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
Serial.print("Connecting To Wi-Fi");
while(WiFi.status() !=WL_CONNECTED)
{
  Serial.print(".");
  delay(300);
}
Serial.println();
Serial.print("Connected With IP:  ");
Serial.println(WiFi.localIP());
}
void loop()
{

}