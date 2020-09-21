#ifndef HEADER_H
  #define HEADER_H

	#include <stdio.h>     // Standard input/output definitions
	#include <string.h>    // String function definitions
	#include <unistd.h>   // UNIX standard function definitions
	#include <fcntl.h>      // File control definitions
	#include <errno.h>     // Error number definitions
	#include <termios.h>  // POSIX terminal control definitions
	#include <stdlib.h>
	#include <signal.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <pthread.h>
	#include <sys/ipc.h>
	#include <sys/sem.h>	
	#include <sys/shm.h>
	#include <time.h>

	union semun {
		int val;
		struct semid_ds *buf;
		unsigned short int *array;
		struct seminfo *_buf;

	};

	int port,res,i,idsem;
	key_t clave;
	struct sembuf operacion;
	union semun arg;

	void *serial_read(void *);
	void *serial_write(void *);

#endif
