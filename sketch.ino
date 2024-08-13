#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 9, 5, 10, 7,6);

const int buttonPin = 4;
int oldValue = HIGH; // default/idle value for pin 4 is high.

// Define the pin numbers for the columns and rows

const int relayPin = 4; // Define the relay pin

void setup() {
  Serial1.begin(115200);  // Initialize serial communication
  pinMode(relayPin, OUTPUT);  // Set relay pin as output
  lcd.begin(16, 2);
  // you can now interact with the LCD, e.g.:
  lcd.print("Hello World!");
  Serial1.println("Hello World!");
}

void loop() {
  // Read the value of pin 4.
  int newValue = digitalRead(buttonPin);

  // Check if the value was changed,
  // by comparing it with the previous value.
  if(newValue != oldValue)
  {
    if(newValue == LOW)
    {
      Serial.println("The button is pressed.");
    }
    else
    {
      Serial.println("The button is released.");
    }
    // Remember the value for the next time.
    oldValue = newValue;
  }

  // Slow down the sketch.
  // Also for debouncing the button.
  delay(100);
}