

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Number:\n");
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == LOW){
    digitalWrite(3, LOW);
  } else {
    digitalWrite(3, HIGH);
  }
}
