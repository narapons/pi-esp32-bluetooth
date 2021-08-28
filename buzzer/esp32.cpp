#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("Buzzer");
  pinMode(15,OUTPUT);
}

void loop() {
  if (SerialBT.available()){
    int buzzer = digitalRead(15);;
    char blu = SerialBT.read();
    if(blu == '1'){
      digitalWrite(15,HIGH);
    }else if(blu == '0'){
      digitalWrite(15,LOW);
    }
  }
}
