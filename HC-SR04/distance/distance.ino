int trigPin = 24;         // Tell Arduino that trigPin is hooked to 13
int echoPin = 22;         // Tell Arduino that echoPin is hooked to 12

float pingTime;           // Define the pingTime varaible
float distance;           // Define the distance varaible
float speedOfSound = 1264.07;  // Speed of sound is 346.13 m/s at 25 C which is 1246.07 km/h

void setup() {
  Serial.begin(9600);     // Start the serial monitor

  pinMode(trigPin, OUTPUT);   // trigPin is an OUTPUT
  pinMode(echoPin, INPUT);    // echoPin is an INPUT

}

void loop() {
  digitalWrite(trigPin, LOW);    // Set the trigPin initially to LOW
  delayMicroseconds(2000);       // Wait for 2 miliseconds 
  digitalWrite(trigPin, HIGH);   // Set the trigPin to HIGH
  delayMicroseconds(20);         // Send trigger for 20 microseconds 
  digitalWrite(trigPin, LOW);    // Stop sending trigger

  pingTime = pulseIn(echoPin, HIGH);    // Start to listen the triggers from echoPin
  pingTime = pingTime / 1000000.;           // 1 second is equal to 10^6 microseconds
  pingTime = pingTime / 3600.;

  distance = pingTime * speedOfSound;   // Distance = Speed x Time
  distance = distance / 2.;              
  distance = distance * 100000.;           // Convert to cm

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1500);
  

}
