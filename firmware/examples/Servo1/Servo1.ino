/*
  2016/05/16
  PWM8, 9でサーボモーター動作確認
  指定位置に動かすだけ
 */

// PWM出力ICとの通信で使用する
#include <Wire.h>
// PWM出力ICと通信してくれるライブラリ
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm_ic = Adafruit_PWMServoDriver();

void setup()
{
    pinMode(STAT_LED1, OUTPUT);
    pinMode(STAT_LED2, OUTPUT);
    Serial.begin(115200);
    Serial.println("PWM test");
    pwm_ic.begin();
    pwm_ic.setPWMFreq(60); // 60Hz ~= 16.6ms (サーボは20ms周期くらい)

    // 0.001 ~ 0.002 くらいの間で変更すれば動くはず
    setServoPulse(PWM8, 1.0);  // 1ms
    setServoPulse(PWM9, 1.5); // 1.5ms
}

// Adafruitのライブラリからとってきた関数
// サーボが受け付けるパルス幅は1 ~ 2 [ms] くらい
// n ; ピン番号, pulse : パルス幅(ms)
void setServoPulse(uint8_t n, double pulse)
{
    double pulselength;

    pulselength = 1000000; // 1,000,000 us per second
    pulselength /= 60;     // 60 Hz
    pulselength /= 4096; // 12 bits of resolution
    pulse *= 1000;
    pulse /= pulselength;
    pwm_ic.setPWM(n, 0, pulse);
}

int cnt = 0;

void loop()
{
    digitalWrite(STAT_LED1, cnt % 2);
    digitalWrite(STAT_LED2, !(cnt % 2));
    cnt++;
    delay(100);
}
