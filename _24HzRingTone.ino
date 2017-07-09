/*
Generates a square wave using a DC power supply and an H-Bridge.  
The amount of rings and delays are set to make it sound close to the Australian phone ring.
*/


void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

}

// the loop function runs over and over again forever
void loop() {

  for (int rings = 0; rings < 2; rings++) {
    for (int bellHits = 0; bellHits < 20; bellHits++){
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      delay(20);
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      //delayMicroseconds(halfWavePeriod);
      delay(20);
    }
    delay(150);
  }

  delay(800);
}
