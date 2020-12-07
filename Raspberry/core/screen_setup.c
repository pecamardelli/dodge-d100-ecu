#include "../main.h"

unsigned char screen_setup() {
    fbfd = open(FRAME_BUFFER_DEVICE, O_RDWR);
	if (!fbfd) {
        perror(strerror(errno));
        return 0x0;
	}

	if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)) {
        perror(strerror(errno));
        return 0x0;
	}

	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        perror(strerror(errno));
        return 0x0;
	}

	screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

	fbp = (char *) mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	
	if ((void *)fbp == MAP_FAILED) {
		perror(strerror(errno));
		return 0x0;
	}

	return 0xFF;
}