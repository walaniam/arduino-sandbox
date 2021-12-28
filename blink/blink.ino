const int redLightPin = 10;
const int yellowLightPin = 9;
const int greenLightPin = 8;
const int buzzerPin = 6;
const int buttonPin = 2;

volatile int buttonState = HIGH;
volatile bool stateChangeConsumed = true;

void setup() {
  
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
//  pinMode(buttonPin, INPUT_PULLUP);

//  attachInterrupt(digitalPinToInterrupt(buttonPin), switchState, FALLING);

  for (int i = 0; i < 1; i++) {
    blinkYellow(true);
  }
  
}

void loop() {
  runTrafficLights();
}

void runTrafficLights() {
  if (buttonState == LOW) {
    blinkYellow(false);
  } else {
    trafficLightsOn();
  }
  stateChangeConsumed = true;
}

void switchState() {
  if (stateChangeConsumed) {
    buttonState = !buttonState;
    stateChangeConsumed = false;
  }
}

void trafficLightsOn() {
  digitalWrite(redLightPin, HIGH);
  buzzOnWait(5000);
  digitalWrite(yellowLightPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(1500);
  
  digitalWrite(redLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(greenLightPin, HIGH);
  delay(8000);
  digitalWrite(greenLightPin, LOW);
  digitalWrite(yellowLightPin, HIGH);
  delay(2000);
  digitalWrite(yellowLightPin, LOW);  
}

void buzzOnWait(int totalWaitMillis) {
  int times = totalWaitMillis / 1000;
  for (int i = 0; i < times; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
}

void blinkYellow(bool withSound) {
  digitalWrite(yellowLightPin, HIGH);
  if (withSound) {
    digitalWrite(buzzerPin, HIGH);
  }
  delay(750);
  digitalWrite(yellowLightPin, LOW);
  digitalWrite(buzzerPin, LOW);
  delay(750);
}
