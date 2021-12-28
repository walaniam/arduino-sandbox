#include <RC5.h>
#include "distance.h"
#include "sounds.h"
#include "remoteServo.h"

#define WARN_DISTANCE_1 90
#define WARN_DISTANCE_2 60
#define STOP_DISTANCE 30
#define TSOP_PIN 3

RC5 rc5(TSOP_PIN);
unsigned char address;
unsigned char command;
unsigned char toggle;

Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(DS_TRIGGER_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(DS_ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);
  servoTurnLeft(servo);
  delay(500);
  servoCenter(servo);
}

void loop() {

  if (rc5.read(&toggle, &address, &command)) {
    rcHandle();
  }

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

  rcClean();
}

void rcHandle() {
  
  Serial.print("A:");
  Serial.print(address);
  Serial.print(" K:");
  Serial.print(command);
  Serial.print(" T:");
  Serial.println(toggle);

  switch (command) {
    case RC_MOVE_FORWARD:
    case RC_MOVE_FORWARD_2:
      servoCenter(servo);
      break;
    case RC_MOVE_LEFT:
    case RC_MOVE_LEFT_2:
      servoTurnLeft(servo);
      break;
    case RC_MOVE_RIGHT:
    case RC_MOVE_RIGHT_2:
      servoTurnRight(servo);
      break;
  }
}

void rcClean() {
  address = 0;
  command = 0;
  toggle = 0;
}
