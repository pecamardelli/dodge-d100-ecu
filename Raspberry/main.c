#include "main.h"

int main() {
	pin_setup();
	screen_ok = screen_setup();
	startup();
	
	if (fork() != 0) {
		flowmeter();
	}
	
	/*
	sleep(2);
	
	char filename[64];
		
	for(int i=1;i<=36;i++){
		sprintf(filename, "/var/ecu/images/gauge/v%02d.bmp", i);
		//printf("%s\n", filename);
		image	= bmp_img_read(filename);
		draw_image(image,500,MIDDLE_SCREEN);
		bmp_img_free(image);
		//sleep(1);
		delay(100);
	}
	*/
	
	wait(NULL);
	
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}
