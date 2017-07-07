/*
Generates a 0V to 5V square wave on pin 10.  The frequency can be set from 1 hertz to 500kHz.  
A voltage divider circuit can be used if less than 5V is required
*/

int frequencyInHertz = 500; //Change this number to your required frequency

float wavePeriodInMicroSeconds = (1.0 / frequencyInHertz) * 1000000;
float halfWavePeriod = wavePeriodInMicroSeconds / 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 10 as an output.
  pinMode(10, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, HIGH);
  delayMicroseconds(halfWavePeriod);
  digitalWrite(10, LOW);
  delayMicroseconds(halfWavePeriod);
}
