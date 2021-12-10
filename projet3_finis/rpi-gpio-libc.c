
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define chemin "/ sys / class / gpio / export"

void main(char argc[], char *argv[])
{
    int fichier;
    char buffer[80];

    sprintf(buffer, "/sys/class/gpio/gpio%s", argv[1]);

    fichier = open(buffer, O_RDONLY);

    if (fichier < 0)
    {
        sprintf(buffer, chemin);
        fichier = open(buffer, O_WRONLY);
        write(fichier, argv[1], strlen(argv[1]));
        close(fichier);
    }

    sprintf(buffer, "/sys/class/gpio/gpio%s/direction", argv[1]);
    fichier = open(buffer, O_WRONLY);
    write(fichier, "out", strlen("out"));
    close(fichier);

    sprintf(buffer, "/sys/class/gpio/gpio%s/value", argv[1]);
    fichier = open(buffer, O_WRONLY);

    if (argv[2][1] == 'n')
    {
        write(fichier, "1", strlen("1"));
    }

    else if (argv[2][1] == 'f')
    {
        write(fichier, "0", strlen("0"));
    }

    close(fichier);

    return 0;
}