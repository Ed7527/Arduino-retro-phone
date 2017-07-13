int currentState = 2;
bool previousState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Number:\n");
  pinMode(currentState, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeElapsedInMilliSeconds = 0;
  unsigned long currentTime = millis();
  unsigned long previousTime;
  
  bool finalPulse = false;
  int digit = 0;
  
  while(digitalRead(currentState) == LOW){
    previousState = LOW;
    digitalWrite(3, LOW);
  }

  // goes from low to high.  Get the digit
  while(!finalPulse){
    
    //add +1 each time state goes from low to high
    if((previousState == LOW) && (currentState == HIGH)){
      digit++;
      previousState = HIGH;
    }

    // Reset timer to 0
    if ((previousState == HIGH) && (currentState == LOW)){
      timeElapsedInMilliSeconds = 0;
      previousTime = currentTime;
      previousState = LOW;
    }
    
    timeElapsedInMilliSeconds = currentTime - previousTime;
    // it's the final pulse if currentState has been low for more than 100ms.

    if((currentState == LOW) && (timeElapsedInMilliSeconds < 150)){
      finalPulse = true;
      Serial.print(digit);
    }
  }

  
  
  digitalWrite(3, HIGH);
}
