import serial
import time

serial_sensor = serial.Serial('/dev/rfcomm0')
serial_buzzer = serial.Serial('/dev/rfcomm1')

while 1:
 print(serial_sensor.readline(1))
    
 if serial_sensor.readline(1) == b'1':
    print(serial_buzzer.write(b'1'))
    time.sleep(3)
    print(serial_buzzer.write(b'0'))
    time.sleep(1)
