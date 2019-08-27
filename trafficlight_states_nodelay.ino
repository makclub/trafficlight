const unsigned long baseInterval = 500;
const unsigned long redSpan = 8;
const unsigned long yellowSpan = 3;
const unsigned long greenSpan = 10;

unsigned long lastLightCheck = 0;
unsigned long currentIntervalsSkipped = 0;

int currentState = 0; //Red: 0, Yellow: 1, Green: 2

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if ((now - lastLightCheck) >= baseInterval) {
    if (currentState == 0) {
      if (currentIntervalsSkipped > redSpan) {
        changeToGreen();
      } else {
        currentIntervalsSkipped++;
      }
    }
    if (currentState == 1) {
      if (currentIntervalsSkipped > yellowSpan) {
        changeToRed();
      } else {
        currentIntervalsSkipped++;
      }
    }
    if (currentState == 2) {
      if (currentIntervalsSkipped > greenSpan) {
        changeToYellow();
      } else {
        currentIntervalsSkipped++;
      }
    }
    lastLightCheck = now;
  }
}

void changeToRed() {
  currentState = 0;
  currentIntervalsSkipped = 0;
  digitalWrite(A0, HIGH);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
}

void changeToGreen() {
  currentState = 2;
  currentIntervalsSkipped = 0;
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
}

void changeToYellow() {
  currentState = 1;
  currentIntervalsSkipped = 0;
  digitalWrite(A0, LOW);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
}