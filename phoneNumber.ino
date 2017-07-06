#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool switchState = false;
int phoneDigit;

unsigned long previousMillis = 0;
unsigned long resetInterval = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(8,INPUT);
  
  lcd.begin(16, 2);
  lcd.print("Press Button");
  lcd.setCursor(0, 1);
  lcd.print("to begin");

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  switchState = digitalRead(8);

  if(!switchState){
    lcd.clear();
  }
}
