import sys
import serial
import time
import json
import collections as cl

serial_sensor = serial.Serial('/dev/rfcomm0')
serial_buzzer = serial.Serial('/dev/rfcomm1')
serial_door = serial.Serial('/dev/rfcomm2')
buzzer = "0"

try:
    while True:
        sensor = serial_sensor.readline(1)
        door = serial_door.readline(1)
        data = cl.OrderedDict()
        data["DATA"] = [{"sensor":sensor, "door":door, "buzzer":buzzer}]
        with open('data.json', mode='wt') as file:
            json.dump(data, file)
        print("checking...")
        if sensor == b'1' or door == b'0':
            print(serial_buzzer.write(b'1'))
            buzzer = "1"
            time.sleep(3)
        else:
            print(serial_buzzer.write(b'0'))
            buzzer = "0"
except KeyboardInterrupt:
    sys.exit(0)
