#include <stdio.h>
#include <pigpio.h>

#define DHT_PIN 4  // GPIO pin number

int main() {
    if (gpioInitialise() < 0) return 1;

    int bit = 0;
    int data[5] = {0};
    uint32_t startTick, pulseLength;

    gpioSetMode(DHT_PIN, PI_OUTPUT);
    gpioWrite(DHT_PIN, 0);
    gpioDelay(18000);
    gpioWrite(DHT_PIN, 1);
    gpioSetMode(DHT_PIN, PI_INPUT);

    while (gpioRead(DHT_PIN) == 1);
    while (gpioRead(DHT_PIN) == 0);
    while (gpioRead(DHT_PIN) == 1);

    for (bit = 0; bit < 40; bit++) {
        while (gpioRead(DHT_PIN) == 0);
        startTick = gpioTick();
        while (gpioRead(DHT_PIN) == 1);
        pulseLength = gpioTick() - startTick;

        data[bit / 8] <<= 1;
        if (pulseLength > 50) data[bit / 8] |= 1;
    }

    gpioTerminate();

    int temperature = data[2];
    printf("Temperature: %d°C\n", temperature);

    return 0;
}
