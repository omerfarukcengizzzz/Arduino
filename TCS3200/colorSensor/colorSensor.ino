int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int rColorStrength;
int gColorStrength;
int bColorStrength;

int S2 = 6;
int S3 = 5;
int outPin = 7;

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

  pulseWidth = pulseIn(outPin, LOW);
  rColorStrength = pulseWidth / 400  - 1;
  rColorStrength = (255. - rColorStrength);

//For GREEN color input
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);  

  pulseWidth = pulseIn(outPin, LOW);
  gColorStrength = pulseWidth / 400  - 1;
  gColorStrength = (255. - gColorStrength);

//For BLUE color input
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);  

  pulseWidth = pulseIn(outPin, LOW);
  bColorStrength = pulseWidth / 400  - 1;
  bColorStrength = (255. - bColorStrength);  


    if(rColorStrength>gColorStrength && gColorStrength>bColorStrength){
       rColorStrength = 255;
       gColorStrength = gColorStrength * .5;
       bColorStrength = 0;
       }  
    if(rColorStrength>bColorStrength && bColorStrength>gColorStrength){
       rColorStrength = 255;
       bColorStrength = bColorStrength * .5;
       gColorStrength = 0;
       }
    if(gColorStrength>rColorStrength && rColorStrength>bColorStrength){
       gColorStrength = 255;
       rColorStrength = rColorStrength * .5;
       bColorStrength = 0;
       }
    if(gColorStrength>bColorStrength && bColorStrength>rColorStrength){
       gColorStrength = 255;
       bColorStrength = bColorStrength * .5;
       rColorStrength = 0;
       }
    if(bColorStrength>rColorStrength && rColorStrength>gColorStrength){
       bColorStrength = 255;
       rColorStrength = rColorStrength * .5;
       gColorStrength = 0;
       }
    if(bColorStrength>gColorStrength && gColorStrength>rColorStrength){
       bColorStrength = 255;
       gColorStrength = gColorStrength * .5;
       rColorStrength = 0;
       } 

//To get all colors 
  bColorStrength = bColorStrength * .5;
  gColorStrength = gColorStrength * .75;

//Write the color values to the RGB LED
  analogWrite(redPin, rColorStrength);
  analogWrite(greenPin, gColorStrength);
  analogWrite(bluePin, bColorStrength);  

//Print the values from the sensor to Serial Monitor
  Serial.print(rColorStrength);
  Serial.print(" , ");
  Serial.print(gColorStrength);
  Serial.print(" , ");
  Serial.print(bColorStrength);
  Serial.print("\n");


  delay(100);        
}
