#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main(char argc[], *char argv[])
{
    int pin;

    wiringPiSetup();

    pinMode(argv[1], OUTPUT);

    pin = atoi(argv[1]);

    if (argv[2][1] == 'n')
    {
        digitalWrite(pin, (int)HIGH);
    }
    else if (argv[2][1] == 'f')
    {
        digitalWrite(pin, (int)LOW);
    }

    return 0;
}
