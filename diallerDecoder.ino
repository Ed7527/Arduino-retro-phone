bool finalPulse = false;
bool previousState;

int currentState = 2;

unsigned long previousTime = 0;
unsigned long timeElapsed = 0;

int digit = 0;

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
  while(digitalRead(currentState) == LOW){
    digitalWrite(3, LOW);
  }

  while(!finalPulse){
    digitalWrite(3, HIGH);

    unsigned long currentTime = millis();
    timeElapsed = currentTime - previousTime;

    if(digitalRead(currentState) == HIGH) {
      previousState = HIGH;
    }

    if((digitalRead(currentState) == LOW)  && (previousState == HIGH)){
    //Happens when the state has gone from high to low
    previousTime = currentTime;
    previousState = LOW;
    digit++;
    }

    if(digitalRead(currentState) == LOW){
      previousState =LOW;
    }

    if ((timeElapsed < 300) && (digitalRead(currentState) == LOW)){
      finalPulse = true;
      Serial.print(digit);
      Serial.print("\n");
      digit = 0;
    }
  }
  finalPulse = false;
  
}
