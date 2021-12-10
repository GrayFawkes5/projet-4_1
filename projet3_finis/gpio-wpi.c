#include "gpio.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

void set_gpio(int pin, int on)
{

    wiringPiSetup();

    pinMode(pin, OUTPUT);

    if (on == 1)
    {
        digitalWrite(pin, (int)HIGH);
    }
    else if (on == 0)
    {
        digitalWrite(pin, (int)LOW);
    }

    return 0;
}