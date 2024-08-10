#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 9, 5, 10, 7,6);

// Define the number of rows and columns in the keypad
const uint8_t ROWS = 4;
const uint8_t COLS = 4;

// Define the key map for the keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the pin numbers for the columns and rows
uint8_t colPins[COLS] = {21, 20, 19, 18}; // C1, C2, C3, C4
uint8_t rowPins[ROWS] = {28, 27, 26, 22}; // R1, R2, R3, R4

// Initialize the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int relayPin = 4; // Define the relay pin

void setup() {
  Serial1.begin(115200);  // Initialize serial communication
  pinMode(relayPin, OUTPUT);  // Set relay pin as output
  lcd.begin(16, 2);
  // you can now interact with the LCD, e.g.:
  lcd.print("Hello World!");
}

void loop() {
  char key = keypad.getKey();  // Get the key pressed

  if (key != NO_KEY) {  // If a key is pressed
    Serial1.println(key);  // Print the key to the serial monitor

    // Control relay based on key press (example)
    if (key == 'A') {
      digitalWrite(relayPin, HIGH);  // Turn relay ON
    } else if (key == 'B') {
      digitalWrite(relayPin, LOW);   // Turn relay OFF
    }
  }
}