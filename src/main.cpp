#include <main.h>
PS2X ps2x;

void setup() {
    setPinMode();
    Serial.begin(9600);
    bool error = true;
    while (error) {
        delay(100);
        error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
        if (!error) {
            Serial.println("Connected");
            break;
        }
    }
}
int valX, valY;
void loop() {
    ps2x.read_gamepad(0,0);
    valX = ps2x.Analog(PSS_LX);
    valY = ps2x.Analog(PSS_LY);
    valX = map(valX,0,255,-H_PWM,H_PWM); 
    valY = map(valY,0,255,V_PWM,-V_PWM);
    Serial.print("X: ");
    Serial.print(valX);
    Serial.print(", Y: ");
    Serial.println(valY);
    if (valY>=0) {
        set_velocity(LEFT_MOTOR,valY-valX);
        set_velocity(RIGHT_MOTOR,valY+valX);
    } else {
        set_velocity(LEFT_MOTOR,valY+valX);
        set_velocity(RIGHT_MOTOR,valY-valX);
    }
    if (ps2x.ButtonPressed(PSB_CIRCLE)) {
        analogWrite(RF,255);
        analogWrite(RB,255);
        analogWrite(LF,255);
        analogWrite(LB,255);
        while (ps2x.ButtonPressed(PSB_CIRCLE));
    }
}