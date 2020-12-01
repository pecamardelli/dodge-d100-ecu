#include "../main.h"

void startup() {
    if (screen_ok) {
		reset_screen(0,0,0);
		
		image	= bmp_img_read("/var/ecu/images/background/bg04.bmp");
		draw_image(image,CENTER_SCREEN,MIDDLE_SCREEN, 0, 0);
		bmp_img_free(image);
		sleep(5);
		
		reset_screen(0,0,0);
	}
}