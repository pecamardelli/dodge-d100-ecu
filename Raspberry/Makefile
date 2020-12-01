CFLAGS=
SLIBS=-lwiringPi

christine_ecu: main.o $(SLIBS)

christine_ecu.o: main.c main.h
	gcc -c main.c

clean:
	rm *.o
