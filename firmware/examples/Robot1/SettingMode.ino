#include <EEPROM.h>
#include <IRremote.h>
#include "header.hpp"

#define EEPROM_IR_POS 0


void setting_mode() {    
    Serial.println("[ SettingMode ]");
    irrecv.enableIRIn(); 
    pinMode(STAT_LED1, OUTPUT);
    pinMode(STAT_LED2, OUTPUT);    
    char stat_led1 = 0, // no use?
         stat_led2 = 0; // EEPROM access
    toggle_led(STAT_LED1, stat_led1); // always on

    IrCommand commands[4] = {};
    {
        char *pos = (char*)commands;
        for(int i = 0; i < sizeof(commands); i++) {
            *(pos + i) = EEPROM.read(EEPROM_IR_POS + i);
            toggle_led(STAT_LED2, stat_led2);
        }    
    }
    while(true) {        
        Serial.println("select menu");    
        Serial.println("1 : set go forward ir command");
        Serial.println("2 : set go back ir command");
        Serial.println("3 : set go left ir command");
        Serial.println("4 : set go right ir command");    
        Serial.println("5 : save setting");
        Serial.println("exit : change switch and push reset button");

        int c = 0;
        do {                        
            if(c) Serial.println("invalid input.");
            Serial.print(">> ");
            while(!c || c == '\n' || c == '\r') {
                while(Serial.available() == 0);
                c = Serial.read(); 
            }
        } while(c - '0' < 1 || 5 < c - '1' );

        Serial.println((char)c);

        c -= '0';

        if(c == 5) {
            char *pos = (char*)commands;
            for(int i = 0; i < sizeof(commands); i++) {
                EEPROM.write(EEPROM_IR_POS + i, *(pos++));
                toggle_led(STAT_LED2, stat_led2);
            }
            Serial.println("save ok.");
        } else if (1 <= c && c <= 4) {
            Serial.println("please send a signal.");
            while(!irrecv.decode(&results) || results.value == 0xFFFFFFFF || results.value == 0) {
                irrecv.resume();  
                delay(100);
            }
            irrecv.resume();  
            if(results.decode_type != UNKNOWN && !results.overflow) {
                commands[c - 1].type = results.decode_type;
                commands[c - 1].len = results.bits;
                commands[c - 1].value = results.value;
                Serial.print("type : ");    Serial.print(results.decode_type);
                Serial.print(" | value : "); Serial.print(results.value, HEX);
                Serial.print(" | len : ");   Serial.println(results.bits);
                Serial.println("set ok (not saved).");
            } else if(results.overflow) {
                Serial.println("overflow length");   
            } else {
                Serial.println("UNKNOWN command type");
            }                     
        }     

        Serial.println("\r\n-----------------------------\r\n");     
    }
}