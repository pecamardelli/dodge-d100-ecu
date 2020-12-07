#include "../main.h"

void flowmeter() {
	int 			state 		= HIGH;
	int 			laststate	= HIGH;
	unsigned int	pulses		= 0;
	//unsigned int	lastpulse	= 0;
	
	char			filename[64];
	bmp_img *image;
	
	while (1) {
		state	= digitalRead(FLOWMETER);
		if (state != laststate) {
			laststate = state;
			pulses++;
			//printf("\t%d\n", pulses);
			
			sprintf(filename,"/var/ecu/images/gauge/g%02d_big.bmp", pulses);
			image	= bmp_img_read(filename);
			draw_image(image,CENTER_SCREEN,MIDDLE_SCREEN,2,1);
			bmp_img_free(image);
		}
		usleep(1000);
	}
	exit(0);
}