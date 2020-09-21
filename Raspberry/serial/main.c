#include "header.h"

// function to open the port
int open_port(void)
{
	int port;
	char *tty = "/dev/ttyACM0";
	char log[256];

	port = open(tty, O_RDWR | O_NOCTTY | O_NONBLOCK);

	if (port == -1){
		 // Could not open the port
		sprintf(log, "open_port: Unable to open %s", tty);
		perror(log);
	}else{
		fcntl(port, F_SETFL, O_RDWR | O_NOCTTY | O_NONBLOCK); //leave this
	}
	return (port);
}

void free_resources(int sig)
{
	if(sig != 0)
	{
		close(port);
		exit(sig);
	}
}

int main()
{
	struct termios oldtio, newtio;
	pthread_t th_read, th_write;
	int err_hilo;
	const char cr = 13;
	long BAUD;                      // derived baud rate from command line
	long DATABITS;
	long STOPBITS;
	long PARITYON;
	long PARITY;

	clave= ftok (".",33);
	idsem= semget (clave,1,0666|IPC_CREAT); 
	arg.val=0;
	semctl (idsem,0,SETVAL,&arg);
	operacion.sem_num=0;
	operacion.sem_op=1;
	operacion.sem_flg=0;
	semop(idsem,&operacion,1);//ejecuto operacion

	//termios - structure contains options for port manipulation
	struct termios specs; 				// for setting baud rate 
	struct sigaction saio;              //definition of signal action

	port = open_port();

	if(port == -1)
	{
		free_resources(2);
	}

	BAUD = B9600;
	DATABITS = CS8;
	STOPBITS = 1;
	PARITYON = 0;
    PARITY = 0;

	newtio.c_cflag = BAUD | DATABITS | STOPBITS | PARITYON | PARITY | FASYNC | CLOCAL | CREAD;
	newtio.c_iflag = IGNPAR;
	newtio.c_oflag = 0;
	newtio.c_lflag = 0;       //ICANON;
	newtio.c_cc[VMIN]=1;
	newtio.c_cc[VTIME]=0;
	tcflush(port, TCIFLUSH);
	tcsetattr(port,TCSANOW,&newtio);

	signal(SIGINT, free_resources);
	signal(SIGTERM, free_resources);

	do
	{
		res = write(port,"INIT",4);
		usleep(50000);
	}while(res < 1);

	if(pthread_create(&th_read, 0, serial_read, 0) != 0){
		perror("SERIAL_READ");
		exit(-1);
	}

	if(pthread_create(&th_write, 0, serial_write, 0) != 0){
		perror("SERIAL_WRITE");
		exit(-1);
	}

	pthread_join(th_read, NULL);
	pthread_join(th_write, NULL);
	free_resources(0);

	return(0);
} 

