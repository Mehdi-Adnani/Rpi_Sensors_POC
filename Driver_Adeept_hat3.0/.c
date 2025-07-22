	#include <wiringPi.h>
		#include <softPwm.h>
		#include <stdio.h>
		
		#define SERVO_PIN 1 // wiringPi pin 1 = BCM 18
		
		int main(void) {
			wiringPiSetup();
			softPwmCreate(SERVO_PIN, 0, 200); // Range 0-200
			
			while (1) {
				// Rotate to 0
				softPwmWrite(SERVO_PIN, 5);
				delay(1000);
				
				// Rotate to 90
				softPwmWrite(SERVO_PIN, 15);
				delay(1000);
				
				// Rotate to 180
				softPwmWrite(SERVO_PIN, 25);
				delay(1000);
			}
			
			return 0;
		}