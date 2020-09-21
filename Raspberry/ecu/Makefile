CFLAGS=
SLIBS=-lwiringPi

christine_ecu: christine_ecu.o $(SLIBS)

christine_ecu.o: christine_ecu.c christine_ecu.h
	gcc -c christine_ecu.c

clean:
	rm *.o
