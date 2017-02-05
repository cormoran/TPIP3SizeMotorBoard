/*
    赤外線受信
    ライブラリ　IRremote(https://github.com/z3t0/Arduino-IRremote)　をインストールしておく必要あり    
 */

#include <IRremote.h>

int RECV_PIN = IR_RECEIVE;
IRrecv irrecv(RECV_PIN); // blink led は禁止(13がoutputになって死亡)
decode_results results;

void setup()
{    
  Serial.begin(115200);
  Serial.println("Start IR Receive");
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    // ソース参照
    // https://github.com/z3t0/Arduino-IRremote/blob/master/IRremote.h
    Serial.print("type : ");    Serial.print(results.decode_type);
    Serial.print(" | value : "); Serial.print(results.value, HEX);
    Serial.print(" | len : ");   Serial.println(results.bits);
    irrecv.resume();
  }
  delay(100);
}