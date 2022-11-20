#define _MAIN_H_

#include <math.h>
#include <Arduino.h>
#include <PS2X_lib.h>

#define PS2_DAT 12
#define PS2_CMD 11
#define PS2_SEL 10
#define PS2_CLK 13
#define pressures false
#define rumble    false

#define LF 3
#define LB 5
#define RF 6
#define RB 9

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1

#define V_PWM 150
#define H_PWM 50

void set_velocity(bool motor, int velocity) {
    bool direction = (velocity>=0);
    velocity = abs(velocity);
    if (velocity>255) velocity = 255;
    if (motor) {
        analogWrite(RF,(direction)?(velocity):(0));
        analogWrite(RB,(direction)?(0):(velocity));
    } else {
        analogWrite(LF,(direction)?(velocity):(0));
        analogWrite(LB,(direction)?(0):(velocity));
    }
}

void setPinMode(){
    pinMode(LF,OUTPUT);
    pinMode(RF,OUTPUT);
    pinMode(LB,OUTPUT);
    pinMode(RB,OUTPUT);
}