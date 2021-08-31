#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("Door");
  pinMode(15,INPUT);
}

void loop() {
  int door = digitalRead(15);
  SerialBT.print(door);
  delay(1000);
}
