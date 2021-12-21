#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("Sensor");
  pinMode(15,INPUT);
}

void loop() {
  int sensor = digitalRead(15);
  if(sensor == 1){
    SerialBT.print(sensor);
  }
  delay(1000);
}
