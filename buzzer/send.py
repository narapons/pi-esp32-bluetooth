import serial
import time

serial = serial.Serial('/dev/rfcomm1')

while 1:
 print(serial.write(b'1'))
 break
