#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define BZ_PIN 15
#define LED_PIN 23

void LED(){
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW);
  delay(500);
}

void getBuzzer(){
  int buzzer = digitalRead(BZ_PIN);
  char blu = SerialBT.read();
}

void setup() {
  SerialBT.begin("Buzzer");
  pinMode(BZ_PIN,OUTPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  if (SerialBT.available()){
    getBuzzer();
    while(blu == '1'){
       digitalWrite(BZ_PIN,HIGH);
       LED();
       getBuzzer();
    }
    digitalWrite(BZ_PIN,LOW);
    digitalWrite(LED_PIN,LOW);
  }
}
