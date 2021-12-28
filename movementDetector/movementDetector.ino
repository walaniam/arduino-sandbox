#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define BUZZER_PIN 13

#define WARN_DISTANCE_1 90
#define WARN_DISTANCE_2 60
#define STOP_DISTANCE 30

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  
  long distanceCm = distance();
  Serial.println(distanceCm);

  if (distanceCm <= STOP_DISTANCE) {
    warnSignal(75);
  } else if (distanceCm <= WARN_DISTANCE_2) {
    warnSignal(150);
  } else if (distanceCm <= WARN_DISTANCE_1) {
    warnSignal(300);
  }

  delay(500);
}

void warnSignal(int amplitude) {
  for (int i = 0; i < 2; i++) {
    tone(BUZZER_PIN, 1200);
//    digitalWrite(BUZZER_PIN, HIGH);
    delay(amplitude);
    tone(BUZZER_PIN, 600);
//    digitalWrite(BUZZER_PIN, LOW);
    delay(amplitude);
  }
  noTone(BUZZER_PIN);
}

long distance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long time = pulseIn(ECHO_PIN, HIGH);
  long distanceCm = time / 58; // sound distance in 1s

  return distanceCm;
}
