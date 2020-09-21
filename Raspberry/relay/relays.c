#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define RELAY1		0
#define RELAY2		2
#define RELAY3		3

int main( void )
{
	printf( "Raspberry Pi wiringPi relay test\n" );
	uint8_t	state = LOW;

	if ( wiringPiSetup() == -1 )
                exit( 1 );

	pinMode( RELAY1, OUTPUT );
	delay( 18 );
	pinMode( RELAY2, OUTPUT );
	delay( 18 );
	pinMode( RELAY3, OUTPUT );
	delay( 18 );


	while ( 1 )
	{
		digitalWrite( RELAY1, state );
		delay( 1000 );
		digitalWrite( RELAY2, state );
		delay( 1000 );
		digitalWrite( RELAY3, state );
		delay( 1000 );

		state	= 1 - state;
	}

	return(0);
}
