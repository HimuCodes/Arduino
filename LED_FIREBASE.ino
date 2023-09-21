/* Firebase Receive */

#include <WiFi.h>
#include <Firebase_ESP_Client.h>

// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "HIMU"
#define WIFI_PASSWORD "12345678"
#define LED_PIN1 25 
#define LED_PIN2 27
// Replace 2 with the actual pin number where the LED is connected


// Insert Firebase project API Key
#define API_KEY ""

// Insert RTDB URL
#define DATABASE_URL "https://unique-nebula-386818-default-rtdb.firebaseio.com/" 

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue1;
int intValue2;
bool signupOK = false;

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  pinMode(LED_PIN1, OUTPUT);

  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) 
  {
    Serial.println("ok");
    signupOK = true;
  }
  else 
  {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() 
{
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 1500 || sendDataPrevMillis == 0)) 
  {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/test/LED1")) 
    {
      if (fbdo.dataType() == "int") 
      {
        intValue1 = fbdo.intData();
        Serial.println(intValue1);
                if (intValue1 == 1) 
                {
            digitalWrite(LED_PIN1, HIGH);
            Serial.println("LED IS ON");
            } 
            else 
            {
            digitalWrite(LED_PIN1, LOW);
            Serial.println("LED IS OFF");
            }

      }
    }
    else 
    {
      Serial.println(fbdo.errorReason());
    }
    
    if (Firebase.RTDB.getInt(&fbdo, "/test/LED2")) 
    {
      if (fbdo.dataType() == "int") 
      {
        intValue2 = fbdo.intData();
        Serial.println(intValue2);
        if (intValue2 == 1) 
                {
            digitalWrite(LED_PIN2, HIGH);
            Serial.println("LED IS ON");
            } 
            else 
            {
            digitalWrite(LED_PIN2, LOW);
            Serial.println("LED IS OFF");
            }

      }
    }
    else 
    {
      Serial.println(fbdo.errorReason());
    }
  }
}
