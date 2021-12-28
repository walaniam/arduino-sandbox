#ifndef SOUNDS_H
#define SOUNDS_H

#include <Arduino.h>

const int LED_PIN = 13;
const int BUZZER_PIN = 10;

void diode(int times);

void sound(int times);

void beep();

void warnSignal(int amplitude);

#endif
