import serial

serial = serial.Serial('/dev/rfcomm0')

while 1:
    print(serial.readline(1))
