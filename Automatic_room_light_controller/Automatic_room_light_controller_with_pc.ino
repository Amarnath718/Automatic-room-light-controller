#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define irsensor_in 2   // Entrance sensor connected to digital 2 
#define irsensor_out 3  // Exit sensor connected to digital 3
#define relay 7         // Relay to control bulb is connected to digtal 7 (Relay in Normally open config.)

int count = 0; // Initializing people inside room as 0

void setup()
{
  pinMode(irsensor_in, INPUT);       // Input IR Sensor set as input
  pinMode(irsensor_out, INPUT);      // Output IR Sensor set as input 
  pinMode(relay, OUTPUT);            // Relay as output
  Serial.begin(9600);                // Initializing serial monitor with baud rate 9600

 //Initializing oled display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  updateDisplay();
}

void loop()
{
  while (count>=0)
  {
    int in_value = digitalRead(irsensor_in);        // Reading values of IR sensors
    int out_value = digitalRead(irsensor_out);

    if (in_value == LOW)
    {
      count++;
      Serial.print("Person Entered - Count: ");
      Serial.println(count);
      updateDisplay();         // Update OLED
      delay(1000);
    }

    if (out_value == LOW && count > 0)
    {
      count--;
      Serial.print("Person Exit - Count: ");
      Serial.println(count);
      updateDisplay();  // Update OLED
      delay (1000);
    }

    if (count>count || count<count)
    {
      delay (2600);
    }

    if (count == 0)
    {
      updateDisplay();
      digitalWrite(relay, HIGH);
    }
    else
    {
      digitalWrite(relay, LOW);
    }
  }
}
// Function to update the OLED display
void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 20); 
  display.print("Count: ");
  display.print(count);
  display.display();
}