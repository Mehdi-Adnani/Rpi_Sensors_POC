#include <wiringPi.h>
		#include <softPwm.h>
		#include <stdio.h>
		
		#define IN1 0 // GPIO17
		#define IN2 2 // GPIO27
		#define ENA 1 // GPIO18
		
		int main(void) {
			wiringPiSetup();
			
			pinMode(IN1, OUTPUT);
			pinMode(IN2, OUTPUT);
			softPwmCreate(ENA, 0, 100);
			
			digitalWrite(IN1, HIGH);
			digitalWrite(IN2, LOW);
			softPwmWrite(ENA, 50); // 50% speed
			
			delay(5000); // Run motor for 5 seconds
			
			softPwmWrite(ENA, 0);
			return 0;
		}