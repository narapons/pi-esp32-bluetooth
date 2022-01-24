import sys
import serial
import time
import json
import collections as cl

serial_sensor = serial.Serial('/dev/rfcomm0')
serial_buzzer = serial.Serial('/dev/rfcomm1')
serial_door = serial.Serial('/dev/rfcomm2')

try:
    while True:
        print("checking...")
        sensor = serial_sensor.readline(1)
        door = serial_door.readline(1)
        data = cl.OrderedDict()
        if sensor == b'1' or door == b'0':
            print(serial_buzzer.write(b'1'))
            door = 1
            buzzer = 1
        else:
            door = 0
            buzzer = 0
        with open('data.json', mode='wt') as file:
            data = [{"sensor":sensor, "door":door, "buzzer":buzzer}]
            json.dump(data, file)
except KeyboardInterrupt:
    sys.exit(0)
