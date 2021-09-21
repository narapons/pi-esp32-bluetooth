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
  while(door == 0) digitalWrite(LED_PIN,HIGH);
  digitalWrite(LED_PIN,LOW);
  delay(1000);
}
