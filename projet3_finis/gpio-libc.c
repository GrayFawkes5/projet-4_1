#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define chemin "/ sys / class / gpio / export"

void set_gpio(int pin, int on)
{
    int fichier;
    char buffer[80];

    sprintf(buffer, "/sys/class/gpio/gpio%s", pin);

    fichier = open(buffer, O_RDONLY);

    if (fichier < 0)
    {
        sprintf(buffer, chemin);
        fichier = open(buffer, O_WRONLY);
        write(fichier, pin, strlen(pin));
        close(fichier);
    }

    sprintf(buffer, "/sys/class/gpio/gpio%s/direction", pin);
    fichier = open(buffer, O_WRONLY);
    write(fichier, "out", strlen("out"));
    close(fichier);

    sprintf(buffer, "/sys/class/gpio/gpio%s/value", pin);
    fichier = open(buffer, O_WRONLY);

    if (on == 1)
    {
        write(fichier, "1", strlen("1"));
    }
    else if (on == 0)
    {
        write(fichier, "0", strlen("0"));
    }

    close(fichier);

    return 0;
}