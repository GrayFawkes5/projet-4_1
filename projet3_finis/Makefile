CC=gcc
CFLAGS=-lwiringpi

wpi:	main.c gpio-wpi.c
	$(CC) -o rpi-gpio main.c gpio-wpi.c $(CFLAGS)
	
libc: main.c gpio-libc.c
		$(CC) -o rpi-gpio main.c gpio-libc.c