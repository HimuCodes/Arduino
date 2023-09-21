#define PIN_RED    25   // Led red pin is connected to 23
#define PIN_GREEN  33   // Led green pin is connected to 22
#define PIN_BLUE   32   // Led blue pin is connected to 21

void setup() 
{
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() 
{
  // Red color code
  analogWrite(PIN_RED,   255);
  analogWrite(PIN_GREEN, 0);
  analogWrite(PIN_BLUE,  0);
  delay(1000); // Keep the color for 1 second

  // Green color code
  analogWrite(PIN_RED,   0);
  analogWrite(PIN_GREEN, 255);
  analogWrite(PIN_BLUE,  0);
  delay(1000); // Keep the color for 1 second

  // Blue color code
  analogWrite(PIN_RED,   0);    
  analogWrite(PIN_GREEN, 0);
  analogWrite(PIN_BLUE,  255);
  delay(1000); // Keep the color for 1 second
}