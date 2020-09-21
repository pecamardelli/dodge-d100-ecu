CFLAGS=-I/usr/include/mysql -DBIG_JOINS=1  -fno-strict-aliasing   -g -DNDEBUG
SLIBS=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -ldl

main: main.o serial_read.o serial_write.o

	gcc -o serial $(CFLAGS) main.o serial_read.o serial_write.o $(SLIBS)

main.o: main.c header.h
	gcc -c main.c

serial_read.o: serial_read.c header.h
	gcc -c serial_read.c

serial_write.o: serial_write.c header.h
	gcc -c serial_write.c

clean:
	rm *.o
