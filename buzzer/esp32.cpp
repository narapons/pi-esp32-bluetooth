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
    char blu = SerialBT.read();
    if(blu == '1'){
       digitalWrite(BZ_PIN,HIGH);
       digitalWrite(LED_PIN,HIGH);
    }
  }
}
