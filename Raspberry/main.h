#ifndef _MAIN_H_
#define _MAIN_H_

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

#include "./libbmp/libbmp.h"

#define MAX_LINE_LEN    256

#define LOG_INFO        "INFO"
#define LOG_WARNING     "WARN"
#define LOG_ERROR       "ERROR"
#define LOG_SYSTEM      "SYSTEM"

#define CENTER_SCREEN	9999
#define	MIDDLE_SCREEN	9998

#define RELAY1			0
#define RELAY2			2
#define RELAY3			3
#define RELAY4			12
#define FLOWMETER		15

/* ---------- CONSTANTS ---------- */
const char  *log_file               = "/var/log/ecu.log";
const char  *frame_buffer_device    = "/dev/fb0"  

/* ---------- FUNCTION DEFINITION ---------- */
void    logger(char *str, int type);
void    pin_setup();
void    startup();

/* ---------- GLOBAL VARS ---------- */
bmp_img         *image;
unsigned char   screen_ok;
#endif