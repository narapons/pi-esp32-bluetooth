
import serial

serial = serial.Serial('/dev/rfcomm2')

while 1:
 print(serial.readline(1))
