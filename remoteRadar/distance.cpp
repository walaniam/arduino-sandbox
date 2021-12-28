#include "distance.h"

long distance() {
  digitalWrite(DS_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(DS_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(DS_TRIGGER_PIN, LOW);

  long time = pulseIn(DS_ECHO_PIN, HIGH);
  long distanceCm = time / 58; // sound distance in 1s

  return distanceCm;
}
