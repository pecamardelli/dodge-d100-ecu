#ifndef __LIBBMP_H__
#define __LIBBMP_H__

#define BMP_MAGIC 19778

#define BMP_GET_PADDING(a) ((a) % 4)

typedef struct _bmp_header {
	//unsigned short	bfType;
	unsigned int   bfSize;
	unsigned int   bfReserved;
	unsigned int   bfOffBits;
	
	unsigned int   biSize;
	int            biWidth;
	int            biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int   biCompression;
	unsigned int   biSizeImage;
	int            biXPelsPerMeter;
	int            biYPelsPerMeter;
	unsigned int   biClrUsed;
	unsigned int   biClrImportant;
} bmp_header;

typedef struct _bmp_pixel {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} bmp_pixel;

// This is faster than a function call
#define BMP_PIXEL(r,g,b) ((bmp_pixel){(b),(g),(r)})

typedef struct _bmp_img {
	bmp_header   *img_header;
	bmp_pixel 	**img_pixels;
} bmp_img;

// BMP_HEADER

bmp_header		*bmp_header_read	(FILE*);
void			show_header			(bmp_header *);

// BMP_IMG
void            bmp_img_alloc		(bmp_img*);
void            bmp_img_free		(bmp_img*);
bmp_img			*bmp_img_read		(const char*);
void 			draw_image			(bmp_img *,int, int, short, unsigned char);

// MISC
void 			reset_screen		(unsigned char, unsigned char, unsigned char);
void			set_pins			();
void			flowmeter			();

struct 			fb_var_screeninfo 	vinfo;
struct 			fb_fix_screeninfo 	finfo;
int 			fbfd;
long int 		screensize;
char 			*fbp;

#endif /* __LIBBMP_H__ */
