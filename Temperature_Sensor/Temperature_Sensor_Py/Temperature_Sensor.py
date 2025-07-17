import Adafruit_DHT
import time

SENSOR = Adafruit_DHT.DHT11 
SENSOR_PIN = 4  

try:
    while True:
        humidity, temperature = Adafruit_DHT.read_retry(SENSOR, SENSOR_PIN)

        if humidity is not None and temperature is not None:
            print(f"Temp: {temperature:.1f}°C | Humidity: {humidity:.1f}%")
        else:
            print("Failed to retrieve data from sensor")

        time.sleep(2)

except KeyboardInterrupt:
    print("Program stopped by user")
