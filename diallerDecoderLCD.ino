#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool finalPulse = false;
bool previousState;

int currentState = 13;

unsigned long previousTime = 0;
unsigned long timeElapsed = 0;
unsigned long currentTime;

int digit = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("EdwardTorpy.com");
  lcd.setCursor(0, 1);
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
      digit = digit-1;
      if(digit == 10){
        digit = 0;
      }
      lcd.print(digit);
      digit = 0;
    }
  }
  delay(500);
}
