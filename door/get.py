import sys
import serial

serial = serial.Serial('/dev/rfcomm2')

try:
    while True:
        print(serial.readline(1))
except KeyboardInterrupt:
    sys.exit(0)
