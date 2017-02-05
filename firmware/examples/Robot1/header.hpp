#pragma once

extern IRrecv irrecv;
extern decode_results results;
extern Adafruit_PWMServoDriver pwm_ic;

struct IrCommand {
    unsigned char type;
    unsigned char len;
    unsigned long value;
};


extern void setting_mode();
extern void ir_remote_mode();

extern void toggle_led(char port, char &value);