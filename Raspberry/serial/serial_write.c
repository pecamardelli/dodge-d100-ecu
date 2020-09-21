#include "header.h"

void *serial_write(void *p)
{
	char in_buf[255];

	while(1)
	{
		fflush(stdin);
		scanf("%s", in_buf);
		/*if(strlen(in_buf) < 255)
		{
			in_buf[strlen(in_buf)] = 13;
		}
		else
		{
			in_buf[255] = 13;
		}
		//printf("%d\n", *in_buf);*/

		operacion.sem_op=-1;//ejecuta op se bajada se semaforo
		semop(idsem,&operacion,1);//cambio operacion

		res = write(port,&in_buf,strlen(in_buf)); // n = no of bytes written

		operacion.sem_op=1;//liberar semaforo
		semop(idsem,&operacion,1);

		if(res < 0)
		{
			perror("File descriptor (port)");
		}
	}
}
