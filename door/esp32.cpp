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
  SerialBT.print(door);
  if(door == 0){
    digitalWrite(LED_PIN,HIGH);
  }else{
    digitalWrite(LED_PIN,LOW);
  }
}
