import RPi.GPIO as GPIO
import time

IN1 = 17
IN2 = 27
ENA = 18

GPIO.setmode(GPIO.BCM)
GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(ENA, GPIO.OUT)

pwm = GPIO.PWM(ENA, 1000)  # 1kHz PWM
pwm.start(50)  # 50% speed

try:
    GPIO.output(IN1, GPIO.HIGH)
GPIO.output(IN2, GPIO.LOW)
time.sleep(5)
except KeyboardInterrupt:
pass

pwm.stop()
GPIO.cleanup()