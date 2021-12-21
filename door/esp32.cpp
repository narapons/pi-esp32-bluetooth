#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

#define DOOR_PIN 15
#define LED_PIN 23

void setup() {
  SerialBT.begin("Door");
  pinMode(DOOR_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  int door = digitalRead(DOOR_PIN);
  if(door == 0){
    SerialBT.print(door);
    digitalWrite(LED_PIN,HIGH);
  }else{
    digitalWrite(LED_PIN,LOW);
  }
}
