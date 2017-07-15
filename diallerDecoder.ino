bool finalPulse = false;
bool previousState;

int currentState = 2;

unsigned long previousTime = 0;
unsigned long timeElapsed = 0;
unsigned long currentTime;

int digit = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Number:\n");
  pinMode(currentState, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(digitalRead(currentState) == LOW){

  }

  while(digitalRead(currentState) == HIGH){

    previousState = HIGH;
    previousTime = 0;
    finalPulse = false;
  }

  
  while(finalPulse == false){
    currentTime = millis();

    if((digitalRead(currentState) == HIGH)&& (previousState == LOW)) {
      previousState = HIGH;
      digit++;
    }

    if((digitalRead(currentState) == LOW)  && (previousState == HIGH)){
      previousTime = currentTime;
      previousState = LOW;
    }

    if((digitalRead(currentState) == LOW) && (previousState == LOW)){
      timeElapsed = currentTime - previousTime;
    }

    if ((timeElapsed > 400) && (digitalRead(currentState) == LOW)){
      finalPulse = true;
      
      if(digit == 10){
        digit = 0;
      }
      Serial.print(digit);
      digit = 0;
    }
  }
  delay(500);
}
