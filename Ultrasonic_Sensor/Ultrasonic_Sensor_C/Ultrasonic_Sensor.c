#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#define TRIG 23
#define ECHO 24

long getMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(void) {
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);

    digitalWrite(TRIG, LOW);
    delay(500);

    while (1) {
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIG, LOW);

        while (digitalRead(ECHO) == LOW);
        long start = getMicroseconds();

        while (digitalRead(ECHO) == HIGH);
        long end = getMicroseconds();

        float distance = (end - start) * 0.01715;

        printf("Distance: %.2f cm\n", distance);
        delay(1000);
    }

    return 0;
}
