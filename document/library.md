# ライブラリリファレンス

> このボードの場合，ライブラリというほどのものではないが．

ArduinoIDEでは，ボードを選択すると自動的にincludeしてくれるヘッダファイルを作っておくことができる．

ここにはピンの名前定義などを入れておく．

[ボードの登録](assign-board.md)で，`hardware`にフォルダをコピーしてもらったが，その一部である

`firmware/RokkoOroshiTPIPMotorBoard/avr/variants/tpip_md/`

にこのボードの，自動インクルードされるヘッダファイルが置いてある．

ピンシンボルとして，`DO`，`A1`などの代わりに，以下のシンボルが使える．

```
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
```