import sys
import serial
import time

serial = serial.Serial('/dev/rfcomm1')

try:
    while True:
        print(serial.write(b'1'))
except KeyboardInterrupt:
    sys.exit(0)
