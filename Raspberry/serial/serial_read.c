#include "header.h"

void *serial_read(void *p)
{
	char c;

	while(1)
	{
		operacion.sem_op=-1;//ejecuta op se bajada se semaforo
		semop(idsem,&operacion,1);//cambio operacion
		//out_buf = (char *) malloc (256);
		if(read(port,&c,1) > 0)
		{
			printf("%c", c);
		}

		operacion.sem_op=1;//liberar semaforo
		semop(idsem,&operacion,1);
		//free(out_buf);
		usleep(1000);
	}
}
