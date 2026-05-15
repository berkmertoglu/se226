int LED1pin = 46;
int LED2pin = 45;
int LED3pin = 44;
int LED4pin = 43;

int button1pin = 41;
int button2pin = 40;
int button3pin = 39;
int button4pin = 38;

bool systemOn = false;
int mode = 1;

int previousButton1State = LOW;
int previousButton2State = LOW;

void setup() {
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);

  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
  pinMode(button3pin, INPUT);
  pinMode(button4pin, INPUT);

  allLEDsOff();
}

void loop() {
  checkButtons();

  if (systemOn == false) {
    allLEDsOff();
    return;
  }

  if (mode == 1) {
    mode1();
  } else if (mode == 2) {
    mode2();
  } else if (mode == 3) {
    mode3();
  }
}

void checkButtons() {
  int button1State = digitalRead(button1pin);
  int button2State = digitalRead(button2pin);

  if (button1State == HIGH && previousButton1State == LOW) {
    systemOn = !systemOn;
    delay(200);

    if (systemOn == false) {
      allLEDsOff();
    }
  }

  if (button2State == HIGH && previousButton2State == LOW) {
    if (systemOn == true) {
      mode++;

      if (mode > 3) {
        mode = 1;
      }

      allLEDsOff();
      delay(200);
    }
  }

  previousButton1State = button1State;
  previousButton2State = button2State;
}

void waitAndCheckButtons() {
  for (int i = 0; i < 100; i++) {
    checkButtons();

    if (systemOn == false) {
      allLEDsOff();
      return;
    }

    delay(10);
  }
}

void allLEDsOff() {
  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
  digitalWrite(LED3pin, LOW);
  digitalWrite(LED4pin, LOW);
}

void allLEDsOn() {
  digitalWrite(LED1pin, HIGH);
  digitalWrite(LED2pin, HIGH);
  digitalWrite(LED3pin, HIGH);
  digitalWrite(LED4pin, HIGH);
}

void mode1() {
  allLEDsOn();
  waitAndCheckButtons();

  if (systemOn == false || mode != 1) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  waitAndCheckButtons();
}

void mode2() {
  allLEDsOff();
  digitalWrite(LED1pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 2) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED2pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 2) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED3pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 2) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED4pin, HIGH);
  waitAndCheckButtons();
}

void mode3() {
  allLEDsOff();
  digitalWrite(LED4pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 3) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED3pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 3) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED2pin, HIGH);
  waitAndCheckButtons();

  if (systemOn == false || mode != 3) {
    allLEDsOff();
    return;
  }

  allLEDsOff();
  digitalWrite(LED1pin, HIGH);
  waitAndCheckButtons();
}