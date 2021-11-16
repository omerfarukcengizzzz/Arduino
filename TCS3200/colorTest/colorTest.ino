int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int rColorStrength;
int gColorStrength;
int bColorStrength;

int S2 = 7;
int S3 = 8;
int outPin = 4;

unsigned int pulseWidth;

void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(outPin, INPUT);

  Serial.begin(9600);
  
}

void loop() {
//For RED color input
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);  

  pulseWidth = pulseIn(outPin, 1);
  rColorStrength = pulseWidth / 400  - 1;
  rColorStrength = (255. - rColorStrength);

  delay(100);

//Print the values from the sensor to Serial Monitor
  Serial.print(rColorStrength);
  Serial.print("\n");
}
