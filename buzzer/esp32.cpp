#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define BZ_PIN 15
#define LED_PIN 23

void setup() {
  SerialBT.begin("Buzzer");
  pinMode(BZ_PIN,OUTPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  if (SerialBT.available()){
    int buzzer = digitalRead(BZ_PIN);
    char blu = SerialBT.read();
    SerialBT.print(buzzer);
    if(blu == '1'){
       digitalWrite(BZ_PIN,HIGH);
       digitalWrite(LED_PIN,HIGH);
    }else{
      digitalWrite(BZ_PIN,LOW);
      digitalWrite(LED_PIN,LOW);
    }
  }
}
