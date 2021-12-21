#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("Sensor");
  pinMode(15,INPUT);
}

void loop() {
  int sensor = digitalRead(15);
  SerialBT.print(sensor);
}
