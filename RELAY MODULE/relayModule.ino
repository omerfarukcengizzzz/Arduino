int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  
  }

void loop() {
  digitalWrite(relayPin, 1);
  delay(1000);
  digitalWrite(relayPin, 0);
  delay(1000);
  }
