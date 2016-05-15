#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

/*
  Arduino - AVR
  ---------
  D0  - PD0
  D1  - PD1
  D2  - PD2
  D3  - PD3
  D4  - PD4
  D5  - PD5
  D6  - PD6
  D7  - PD7
  ---------
  D8  - PB0
  D9  - PB1
  D10 - PB2
  D11 - PB3
  D12 - PB4
  D13 - PB5
  ---------
  A0  - PC0
  A1  - PC1
  A2  - PC2
  A3  - PC3
  A4  - PC4
  A5  - PC5
  (32pin Only)
  A6  - ADC6
  A7  - ADC7
 */


// Digital Pin
static const uint8_t TMPERATURE_SENSOR = 2;
static const uint8_t IR_LED   =  3;
static const uint8_t IR_RECEIVE =  4;
static const uint8_t IO_PAD =  5;
static const uint8_t STAT_LED1=  6;
static const uint8_t STAT_LED2=  7;

static const uint8_t SW0   =  10;
static const uint8_t SW1   =  11;
static const uint8_t SW2   =  12;
static const uint8_t SW3   =  13;


// Analog
static const uint8_t LOGIC_BAT_SENS = 20;
static const uint8_t MOTOR_BAT_SENS = 21;

static const uint8_t PWM_MOTOR0_FIN = 0;
static const uint8_t PWM_MOTOR0_RIN = 1;
static const uint8_t PWM_MOTOR1_FIN = 2;
static const uint8_t PWM_MOTOR1_RIN = 3;
static const uint8_t PWM_MOTOR2_FIN = 4;
static const uint8_t PWM_MOTOR2_RIN = 5;
static const uint8_t PWM_MOTOR3_FIN = 6;
static const uint8_t PWM_MOTOR3_RIN = 7;

static const uint8_t PWM8 = 8;
static const uint8_t PWM9 = 9;

#endif
