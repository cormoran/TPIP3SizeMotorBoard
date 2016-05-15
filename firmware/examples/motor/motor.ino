/*
  2016/05/16
  Motor 0 ~ 3 の動作確認
 */
#include<Wire.h> // PWM出力ICとの通信で使用する
#include<Adafruit_PWMServoDriver.h> // PWM出力ICと通信してくれるライブラリ

Adafruit_PWMServoDriver pwm_ic = Adafruit_PWMServoDriver();

void setup() {
    pinMode(STAT_LED1, OUTPUT);
    pinMode(STAT_LED2, OUTPUT);
    Serial.begin(115200);
    Serial.println("PWM test");
    pwm_ic.begin();
    pwm_ic.setPWMFreq(1000); // 1kHz(ここ、現状適当)

    
    // setPin(ピン番号, 値(0~4095))
    // (analogWriteの感覚で使えばOK)

    // M0 : 順方向回転
    pwm_ic.setPin(PWM_MOTOR0_FIN, 4095); // ここで回転の強さが変わる
    pwm_ic.setPin(PWM_MOTOR0_RIN, 0);
    // M1 : 逆方向回転
    pwm_ic.setPin(PWM_MOTOR1_FIN, 0);
    pwm_ic.setPin(PWM_MOTOR1_RIN, 4095);
    // M2 : ストップ
    pwm_ic.setPin(PWM_MOTOR2_FIN, 4095);
    pwm_ic.setPin(PWM_MOTOR2_RIN, 4095);
    // M3 : フリー
    pwm_ic.setPin(PWM_MOTOR3_FIN, 0);
    pwm_ic.setPin(PWM_MOTOR3_RIN, 0);
}


int cnt = 0;

void loop() {
    digitalWrite(STAT_LED1,   cnt%2 );
    digitalWrite(STAT_LED2, !(cnt%2));
    delay(100);
}
