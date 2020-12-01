#include "main.h"
#include "./libbmp/libbmp.c"

#include "./core/reset_screen.c"
#include "./core/screen_setup.c"
#include "./core/flowmeter.c"

#include "./utils/pin_setup.c"

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
	
	while (wait(NULL) > 0) {
		usleep(1000);
    }
	
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}
