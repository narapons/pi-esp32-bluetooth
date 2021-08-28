import serial
import time

serial = serial.Serial('/dev/rfcomm1')

while 1:
 print(serial.write(b'1'))
 time.sleep(3)
 print(serial.write(b'0'))
 time.sleep(1)
 break
