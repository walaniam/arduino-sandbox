#include "sounds.h"

void diode(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
  }
}

void sound(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(250);
    digitalWrite(BUZZER_PIN, LOW);
    delay(250);
  }
}

void beep() {
  
}

void warnSignal(int amplitude) {
  for (int i = 0; i < 2; i++) {
    
    digitalWrite(LED_PIN, HIGH);
    //tone(BUZZER_PIN, 1200);
    delay(amplitude);
    digitalWrite(LED_PIN, LOW);
    
    //tone(BUZZER_PIN, 600);    
    digitalWrite(LED_PIN, HIGH);
    delay(amplitude);
    digitalWrite(LED_PIN, LOW);
  }
  noTone(BUZZER_PIN);
}
