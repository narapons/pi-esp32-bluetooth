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
        sensor = int(serial_sensor.readline(1))
        door = int(serial_door.readline(1))
        buzzer = int(serial_buzzer.readline(1))
        data = cl.OrderedDict()
        data["DATA"] = {"sendor":sensor, "door":door, "buzzer":buzzer}
        with open('data.json', mode='w') as file:
            json.dump(data, file)
        if serial_sensor.readline(1) == 1 or serial_door.readline(1) == 0:
            print(serial_buzzer.write(b'1'))
            time.sleep(3)
            print(serial_buzzer.write(b'0'))
except KeyboardInterrupt:
    sys.exit(0)
