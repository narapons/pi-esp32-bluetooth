sudo rfcomm bind 2 E0:E2:E6:D0:F0:E2
echo "Doorと接続しました。"

sudo rfcomm bind 0 E0:E2:E6:D1:08:0A
echo "Sensorと接続しました。"

sudo rfcomm bind 1 E0:E2:E6:D1:3D:A6
echo "Buzzerと接続しました。"

echo "全てのデバイスと接続しました。"
echo "Connected to all devices."
