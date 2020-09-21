#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <wiringPi.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <time.h>

#include "christine_ecu.h"
#include "lib/libbmp.c"
#include "core/reset_screen.c"
#include "core/set_pins.c"
#include "core/flowmeter.c"

int main()
{
	set_pins();
	
	bmp_img *image;

	fbfd = open("/dev/fb0", O_RDWR);
	if (!fbfd) {
			printf("Error: cannot open framebuffer device.\n");
			exit(1);
	}

	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
			printf("Error reading fixed information.\n");
			exit(2);
	}

	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
			printf("Error reading variable information.\n");
			exit(3);
	}

	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	
	if ((int)fbp == -1) {
		printf("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	
	reset_screen(0,0,0);
	
	image	= bmp_img_read("/var/ecu/images/background/bg04.bmp");
	draw_image(image,CENTER_SCREEN,MIDDLE_SCREEN, 0, 0);
	bmp_img_free(image);
	sleep(5);
	
	reset_screen(0,0,0);
	
	if(fork() != 0){
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
	
	while (wait(NULL) > 0)
    {
		usleep(1000);
    }
	
	
	munmap(fbp, screensize);
	close(fbfd);
	return 0;
}
