/*
    赤外線送信
    ライブラリ　IRremote(https://github.com/z3t0/Arduino-IRremote)　をインストールしておく必要あり    

    各社の赤外線コードは http://lirc.sourceforge.net/remotes/ にたくさんあるみたい
 */
#include <IRremote.h>

IRsend irsend;

void setup() {}

void loop() {
    // IrReceive を実行して，適当なリモコンの信号を受信する
    // その出力に応じて，
    // 関数を decode_type によって変更, (value, len) とすると良い．
	irsend.sendSony(0xa90, 12); 	
	delay(1000);
}