#include "gpio.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define MAX_GPIO 26

int main(char argc[], char *argv[])
{
    int etat;
    unsigned int pin = 0;
    int i = 0;

    // convertion de mon string en int

    while (argv[1][i] != '\0')
    {
        pin *= 10;
        pin += (argv[1][i] - '0'); // valeur en ascii - 48 ('0')
        i++;
    }

    if (pin > MAX_GPIO)
    {
        return 0; //  Si pin est superieur, alors je sors de mon programme
    }

    if (argv[2][1] == 'n')
    {
        etat = 1;
    }

    else if (argv[2][1] == 'f')
    {
        etat = 0;
    }

    set_gpio(pin, etat);

    return 0;
}