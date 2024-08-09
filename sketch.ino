// Now turn this trash into treasure!

const int relaypin = 4;
void setup() {
  pinMode(relaypin, OUTPUT);
}
void loop() {
  digitalWrite(relaypin, HIGH);
  delay(1000);
  digitalWrite(relaypin, LOW);
  delay(1000);
}