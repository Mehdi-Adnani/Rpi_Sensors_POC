import RPi.GPIO as GPIO
import time

SENSOR_PIN = 17

GPIO.setmode(GPIO.BCM)
GPIO.setup(SENSOR_PIN, GPIO.IN)

try:
    while True:
        if GPIO.input(SENSOR_PIN):
            print("No obstacle detected")
        else:
            print("Obstacle detected")
        time.sleep(0.5)
except KeyboardInterrupt:
    GPIO.cleanup()
