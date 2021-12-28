#ifndef REMOTE_SERVO_H
#define REMOTE_SERVO_H

#include <Arduino.h>
#include <Servo.h>

const int SERVO_PIN = 11;
const byte SERVO_CENTER_INDEX = 90;
const byte SERVO_MOVE_STEP = 6;

// ### Remote Control ###
#define RC_MODE 10
#define RC_MOVE_FORWARD 2
#define RC_MOVE_FORWARD_2 80
#define RC_MOVE_BACK 8
#define RC_MOVE_BACK_2 81
#define RC_MOVE_LEFT 4
#define RC_MOVE_LEFT_2 85
#define RC_MOVE_RIGHT 6
#define RC_MOVE_RIGHT_2 86
#define RC_STOP 5
#define RC_STOP_2 87

void servoTurnRight(Servo servo);

void servoTurnLeft(Servo servo);

void servoCenter(Servo servo);

#endif
