#include "../main.h"

void startup() {
    if (screen_ok) {
		bmp_img	*background	= bmp_img_read("/var/ecu/images/background/bg04.bmp");
		
		reset_screen(0,0,0);
		draw_image(background,CENTER_SCREEN,MIDDLE_SCREEN, 0, 0);
		bmp_img_free(background);
		sleep(5);
		
		reset_screen(0,0,0);
	}
}