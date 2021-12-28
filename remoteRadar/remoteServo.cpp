#include "remoteServo.h"

void servoTurnLeft(Servo servo) {
  if (servo.read() != 0) {
    servo.write(0);
  }
}

void servoTurnRight(Servo servo) {
  if (servo.read() != 180) {
    servo.write(180);
  }
}

void servoCenter(Servo servo) {
  if (servo.read() != SERVO_CENTER_INDEX) {
    servo.write(SERVO_CENTER_INDEX);
  }
}
