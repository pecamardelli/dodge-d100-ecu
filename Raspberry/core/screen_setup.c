#include "../main.h"

int screen_setup() {
    fbfd = open(frame_buffer_device, O_RDWR);
	if (!fbfd) {
        printf("Error: cannot open framebuffer device.\n");
        return NULL;
	}

	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        printf("Error reading fixed information.\n");
        return NULL;
	}

	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        printf("Error reading variable information.\n");
        return NULL;
	}

	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	
	if ((int)fbp == -1) {
		printf("Error: failed to map framebuffer device to memory.\n");
		return NULL;
	}

	return 0xFF;
}