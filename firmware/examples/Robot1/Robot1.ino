/*
    ロボットにするサンプル
    依存 : 
        IRremote(https://github.com/z3t0/Arduino-IRremote)
        Adafruit_PWMServoDriver(https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library)
    
    TODO : 
        赤外線が不安定すぎてまともに動かない...
        ライブラリがデコードできてない
        ノイズ？　バグ？
 */

// PWM出力ICとの通信で使用する
#include <Wire.h>
// PWM出力ICと通信してくれるライブラリ
#include <Adafruit_PWMServoDriver.h>
#include <IRremote.h>

#include "header.hpp"

Adafruit_PWMServoDriver pwm_ic = Adafruit_PWMServoDriver();

int RECV_PIN = IR_RECEIVE;
IRrecv irrecv(RECV_PIN); // blink led は禁止(13がoutputになって死亡)
decode_results results;


void toggle_led(char port, char &value) {
    value = (value + 1) % 2;
    digitalWrite(port, value);    
}

void setup()
{
  pinMode(SW0, INPUT_PULLUP);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);

  pwm_ic.begin();
  pwm_ic.setPWMFreq(1000); // 1kHz(ここ適当)
  pwm_ic.setPin(PWM_MOTOR0_FIN, 0);
  pwm_ic.setPin(PWM_MOTOR0_RIN, 0);  
  pwm_ic.setPin(PWM_MOTOR1_FIN, 0);
  pwm_ic.setPin(PWM_MOTOR1_RIN, 0);    
  pwm_ic.setPin(PWM_MOTOR2_FIN, 0);
  pwm_ic.setPin(PWM_MOTOR2_RIN, 0);
  pwm_ic.setPin(PWM_MOTOR3_FIN, 0);
  pwm_ic.setPin(PWM_MOTOR3_RIN, 0);

  Serial.begin(115200);
  Serial.println("Start Sample Robot1");
  delay(10);
  char mode = 0; // 2^4 = 16
  mode |= !digitalRead(SW0) << 0;
  mode |= !digitalRead(SW1) << 1;
  mode |= !digitalRead(SW2) << 2;
  mode |= !digitalRead(SW3) << 3;
  Serial.print("mode : "); Serial.println(mode, BIN);
  if(mode & (1 << 0)) 
  {
      // 設定
      setting_mode();
  }
  else if (mode & (1 << 1)) 
  {
      // 赤外線制御
      ir_remote_mode();
  }
  else if (mode & (1 << 2))
  {
      
  }
  else if (mode & (1 << 3)) 
  {
      
  }
}

void loop() {
}