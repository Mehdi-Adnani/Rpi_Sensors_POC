#include <wiringPi.h>
#include <stdio.h>

#define IR_PIN 17  // GPIO17 (BCM) = wiringPi pin 0

int main(void) {
    if (wiringPiSetupGpio() == -1) {
        printf("wiringPi setup failed!\n");
        return 1;
    }

    pinMode(IR_PIN, INPUT);

    printf("IR Sensor Monitoring Started...\n");

    while (1) {
        if (digitalRead(IR_PIN)) {
            printf("No obstacle detected\n");
        } else {
            printf("Obstacle detected\n");
        }

        delay(500);  // 500ms delay
    }

    return 0;
}
