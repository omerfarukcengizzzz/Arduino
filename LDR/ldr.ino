int ldr = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(ldr);
  Serial.println(val);
  delay(10);
}
