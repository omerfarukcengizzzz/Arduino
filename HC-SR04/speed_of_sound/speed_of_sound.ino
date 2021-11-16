int trigPin = 13;
int echoPin = 11;
float pingTime;
float distance = 10;  //10 cm
float speedOfSound;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTime = pulseIn(echoPin, HIGH);
  
  speedOfSound = 2 * distance / pingTime;
  speedOfSound = speedOfSound * 10000;     // in meters per second
  Serial.println(speedOfSound);
  delay(2000);
  
}
