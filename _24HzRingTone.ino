/*
Generates a -9V to 9V square wave using a 9V battery and an H-Bridge.
*/


void setup() {
  // initialize digital pin 10 as an output.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  //delayMicroseconds(halfWavePeriod);
  delay(20);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  //delayMicroseconds(halfWavePeriod);
  delay(20);
}
