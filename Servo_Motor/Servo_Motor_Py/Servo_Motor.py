import RPi.GPIO as GPIO
import time

SERVO_PIN = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(SERVO_PIN, GPIO.OUT)

pwm = GPIO.PWM(SERVO_PIN, 50)  # 50 Hz
pwm.start(0)

try:
    while True:
# Rotate to 0
pwm.ChangeDutyCycle(2.5)
time.sleep(1)

# Rotate to 90
pwm.ChangeDutyCycle(7.5)
time.sleep(1)

# Rotate to 180
pwm.ChangeDutyCycle(12.5)
time.sleep(1)

except KeyboardInterrupt:
pwm.stop()
GPIO.cleanup()