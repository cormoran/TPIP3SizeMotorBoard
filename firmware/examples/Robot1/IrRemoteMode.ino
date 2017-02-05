#include <EEPROM.h>
#include <IRremote.h>
#include "header.hpp"

#define EEPROM_IR_POS 0

void ir_remote_mode() {    
    Serial.println("[ IRRemote Mode ]");
    irrecv.enableIRIn(); 
    pinMode(STAT_LED1, OUTPUT);
    pinMode(STAT_LED2, OUTPUT);    
    
    char stat_led1 = 0, // no use?
         stat_led2 = 0; // EEPROM access
    toggle_led(STAT_LED1, stat_led1); // always on

    IrCommand commands[4] = {};
    { // load
        char *pos = (char*)commands;
        for(int i = 0; i < sizeof(commands); i++) {
            *(pos + i) = EEPROM.read(EEPROM_IR_POS + i);
            toggle_led(STAT_LED2, stat_led2);
        }    
    }
    char prevType = 0, prevLen = 0;
    unsigned long prevValue = 0;
    bool received = false;
    while(true) {     
        received = false;
        if(irrecv.decode(&results)) {
            irrecv.resume(); 
            toggle_led(STAT_LED1, stat_led1);
            Serial.print("type : ");    Serial.print(results.decode_type);
            Serial.print(" | value : "); Serial.print(results.value, HEX);
            Serial.print(" | len : ");   Serial.println(results.bits);  
            char nowType = results.decode_type, nowLen =  results.bits;
            unsigned long nowValue = results.value;
            if(results.value == 0xFFFFFFFF && prevValue > 0) {
                nowValue = prevValue;
                nowLen = prevLen;
                nowType = prevType;
            } 
            for(int i = 0; i < 4; i++) {
                if(nowType == commands[i].type &&
                    nowLen == commands[i].len &&
                    nowValue == commands[i].value) {
                        // execute
                        if(i == 0) {
                            pwm_ic.setPin(PWM_MOTOR0_FIN, 4095);
                            pwm_ic.setPin(PWM_MOTOR0_RIN, 0);    
                            pwm_ic.setPin(PWM_MOTOR2_FIN, 4095);
                            pwm_ic.setPin(PWM_MOTOR2_RIN, 0);
                            Serial.println("forward");
                        } else if(i == 1) {
                            pwm_ic.setPin(PWM_MOTOR0_FIN, 0);
                            pwm_ic.setPin(PWM_MOTOR0_RIN, 4095);    
                            pwm_ic.setPin(PWM_MOTOR2_FIN, 0);
                            pwm_ic.setPin(PWM_MOTOR2_RIN, 4095);
                            Serial.println("back");
                        } else if(i == 2) {
                            pwm_ic.setPin(PWM_MOTOR0_FIN, 4095);
                            pwm_ic.setPin(PWM_MOTOR0_RIN, 0);    
                            pwm_ic.setPin(PWM_MOTOR2_FIN, 0);
                            pwm_ic.setPin(PWM_MOTOR2_RIN, 4095);    
                            Serial.println("left");                           
                        } else if (i == 3) {
                            pwm_ic.setPin(PWM_MOTOR0_FIN, 0);
                            pwm_ic.setPin(PWM_MOTOR0_RIN, 4095);    
                            pwm_ic.setPin(PWM_MOTOR2_FIN, 4095);
                            pwm_ic.setPin(PWM_MOTOR2_RIN, 0);     
                            Serial.println("right");                         
                        }
                        prevValue = results.value;
                        prevLen = results.bits;
                        prevType = results.decode_type;
                        toggle_led(STAT_LED2, stat_led2);  
                        received = true;                                            
                        break;
                    }
            }            
        }         
        delay(50);         
        if(!received) {
            pwm_ic.setPin(PWM_MOTOR0_FIN, 0);
            pwm_ic.setPin(PWM_MOTOR0_RIN, 0);  
            pwm_ic.setPin(PWM_MOTOR1_FIN, 0);
            pwm_ic.setPin(PWM_MOTOR1_RIN, 0);    
            pwm_ic.setPin(PWM_MOTOR2_FIN, 0);
            pwm_ic.setPin(PWM_MOTOR2_RIN, 0);
            pwm_ic.setPin(PWM_MOTOR3_FIN, 0);
            pwm_ic.setPin(PWM_MOTOR3_RIN, 0);
        }
    }
}