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
        sensor = serial_sensor.readline(1)
        door = serial_door.readline(1)
        buzzer = serial_buzzer.readline(1)
        print(sensor)
        data = cl.OrderedDict()
        data["DATA"] = [sensor, door, buzzer]
        json = open('myu_s.json', 'w')
        json.dump(data, json, indent=4)

        if serial_sensor.readline(1) == b'1' or serial_door.readline(1) == b'0':
            print(serial_buzzer.write(b'1'))
            time.sleep(3)
            print(serial_buzzer.write(b'0'))
except KeyboardInterrupt:
    sys.exit(0)
