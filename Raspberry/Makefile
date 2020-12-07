CC		= gcc
CFLAGS	= -Wall -g
SLIBS	= -lwiringPi

CORE_DIR	= core
CORE_OBJS	= $(CORE_DIR)/flowmeter.o $(CORE_DIR)/reset_screen.o $(CORE_DIR)/screen_setup.o

BMP_DIR		= libbmp
BMP_OBJS	= $(BMP_DIR)/libbmp.o

UTILS_DIR	= utils
UTILS_OBJS	= $(UTILS_DIR)/logger.o $(UTILS_DIR)/pin_setup.o

MISC_DIR	= misc
MISC_OBJS	= $(MISC_DIR)/startup.o

OBJS		= main.o $(CORE_OBJS) $(BMP_OBJS) $(UTILS_OBJS) $(MISC_OBJS)

ecu: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(SLIBS)
	make clean

clean:
	rm -f *.o $(CORE_DIR)/*.o $(BMP_DIR)/*.o $(UTILS_DIR)/*.o $(MISC_DIR)/*.o
