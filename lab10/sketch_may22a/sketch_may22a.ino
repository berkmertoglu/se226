#include <LiquidCrystal.h>

int aPin = 22;
int bPin = 23;
int cPin = 24;
int dPin = 25;
int ePin = 26;
int fPin = 27;
int gPin = 28;
int dpPin = 29;

int digit1 = 36;
int digit2 = 35;
int digit3 = 34;
int digit4 = 33;

LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

unsigned long previousTime = 0;
unsigned long counterInterval = 1000;

int segmentOn = HIGH;
int segmentOff = LOW;

int digitOn = HIGH;
int digitOff = LOW;

void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dpPin, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  allDigitsOff();
  allSegmentsOff();

  lcd.begin(16, 2);
  lcd.clear();
  updateLCD();
}

void loop() {
  displayNumber();

  if (millis() - previousTime >= counterInterval) {
    previousTime = millis();
    incrementCounter();
    updateLCD();
  }
}

void incrementCounter() {
  dig1++;

  if (dig1 >= 10) {
    dig1 = 0;
    dig2++;
  }

  if (dig2 >= 10) {
    dig2 = 0;
    dig3++;
  }

  if (dig3 >= 10) {
    dig3 = 0;
    dig4++;
  }

  if (dig4 >= 10) {
    dig4 = 0;
  }
}

void updateLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);
  lcd.print("   ");
}

void displayNumber() {
  showDigit(dig4, digit1);
  showDigit(dig3, digit2);
  showDigit(dig2, digit3);
  showDigit(dig1, digit4);
}

void showDigit(int number, int digitPin) {
  allDigitsOff();
  setNumber(number);
  digitalWrite(digitPin, digitOn);
  delay(4);
  digitalWrite(digitPin, digitOff);
}

void allDigitsOff() {
  digitalWrite(digit1, digitOff);
  digitalWrite(digit2, digitOff);
  digitalWrite(digit3, digitOff);
  digitalWrite(digit4, digitOff);
}

void allSegmentsOff() {
  digitalWrite(aPin, segmentOff);
  digitalWrite(bPin, segmentOff);
  digitalWrite(cPin, segmentOff);
  digitalWrite(dPin, segmentOff);
  digitalWrite(ePin, segmentOff);
  digitalWrite(fPin, segmentOff);
  digitalWrite(gPin, segmentOff);
  digitalWrite(dpPin, segmentOff);
}

void setSegments(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  digitalWrite(aPin, a ? segmentOn : segmentOff);
  digitalWrite(bPin, b ? segmentOn : segmentOff);
  digitalWrite(cPin, c ? segmentOn : segmentOff);
  digitalWrite(dPin, d ? segmentOn : segmentOff);
  digitalWrite(ePin, e ? segmentOn : segmentOff);
  digitalWrite(fPin, f ? segmentOn : segmentOff);
  digitalWrite(gPin, g ? segmentOn : segmentOff);
  digitalWrite(dpPin, segmentOff);
}

void setNumber(int number) {
  if (number == 0) {
    setSegments(true, true, true, true, true, true, false);
  } else if (number == 1) {
    setSegments(false, true, true, false, false, false, false);
  } else if (number == 2) {
    setSegments(true, true, false, true, true, false, true);
  } else if (number == 3) {
    setSegments(true, true, true, true, false, false, true);
  } else if (number == 4) {
    setSegments(false, true, true, false, false, true, true);
  } else if (number == 5) {
    setSegments(true, false, true, true, false, true, true);
  } else if (number == 6) {
    setSegments(true, false, true, true, true, true, true);
  } else if (number == 7) {
    setSegments(true, true, true, false, false, false, false);
  } else if (number == 8) {
    setSegments(true, true, true, true, true, true, true);
  } else if (number == 9) {
    setSegments(true, true, true, true, false, true, true);
  }
}