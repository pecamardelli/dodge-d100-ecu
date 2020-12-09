#include "../ecu.h"

void set_images(){
	int xres	= vinfo.xres;
	int yres	= vinfo.yres;
	int	dist	= (xres - SYMBOL_WIDTH * SYMBOL_UPPER_NUM) / (SYMBOL_UPPER_NUM + 1);
	//int upper_y	= 20;
	
	// ----------------------------- //
	// -------- BACKGROUNDS -------- //
	// ----------------------------- //
	
	sprintf(background.filename, "%s%s%sbg04.bmp",sys.main_dir,sys.image_dir,sys.bg_dir);
	background.x		= CENTER_SCREEN;
	background.y		= MIDDLE_SCREEN;
	background.color	= RED;
	background.alpha	= TRANSPARENT;
	
	sprintf(christine.filename, "%s%s%schristine.bmp",sys.main_dir,sys.image_dir,sys.bg_dir);
	christine.x		= CENTER_SCREEN;
	christine.y		= MIDDLE_SCREEN;
	christine.color	= RED;
	christine.alpha	= TRANSPARENT;
	
	// ----------------------------- //
	// ------- UPPER SYMBOLS ------- //
	// ----------------------------- //
	
	sprintf(left_arrow.filename, "%s%s%slarrow.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	left_arrow.x		= xres / 2 - SYMBOL_WIDTH * 3.5 - dist * 3;
	left_arrow.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	left_arrow.color	= GREEN;
	left_arrow.alpha	= TRANSPARENT;	
	
	sprintf(brakes.filename, "%s%s%sbrakes.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	brakes.x		= xres / 2 - SYMBOL_WIDTH * 2.5 - dist * 2;
	brakes.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	brakes.color	= RED;
	brakes.alpha	= TRANSPARENT;
	
	sprintf(fog_lights.filename, "%s%s%sfaux.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	fog_lights.x		= xres / 2 - SYMBOL_WIDTH * 1.5 - dist;
	fog_lights.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	fog_lights.color	= YELLOW;
	fog_lights.alpha	= TRANSPARENT;
	
	sprintf(low_beams.filename, "%s%s%slbeams.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	low_beams.x		= xres / 2 - SYMBOL_WIDTH * 0.5;
	low_beams.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	low_beams.color	= GREEN;
	low_beams.alpha	= TRANSPARENT;
	
	sprintf(high_beams.filename, "%s%s%shbeams.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	high_beams.x		= xres / 2 + SYMBOL_WIDTH * 0.5 + dist;
	high_beams.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	high_beams.color	= BLUE;
	high_beams.alpha	= TRANSPARENT;
	
	sprintf(emergency_lights.filename, "%s%s%selights.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	emergency_lights.x		= xres / 2 + SYMBOL_WIDTH * 1.5 + dist * 2;
	emergency_lights.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	emergency_lights.color	= RED;
	emergency_lights.alpha	= TRANSPARENT;
	
	sprintf(right_arrow.filename, "%s%s%srarrow.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	right_arrow.x		= xres / 2 + SYMBOL_WIDTH * 2.5 + dist * 3;
	right_arrow.y		= yres * 0.15 - SYMBOL_HEIGHT / 2;
	right_arrow.color	= GREEN;
	right_arrow.alpha	= TRANSPARENT;	
	
	// ---------- MIDDLE-UP SYMBOLS ---------- //
	
	sprintf(heater.filename, "%s%s%sheater.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	heater.x		= xres * 0.2 - SYMBOL_WIDTH / 2;
	heater.y		= yres * 0.4 - SYMBOL_HEIGHT / 2;
	heater.color	= YELLOW;
	heater.alpha	= TRANSPARENT;
	
	sprintf(fan.filename, "%s%s%sfan.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	fan.x		= xres * 0.3 - SYMBOL_WIDTH / 2;
	fan.y		= yres * 0.4 - SYMBOL_HEIGHT / 2;
	fan.color	= GREEN;
	fan.alpha	= TRANSPARENT;
	
	sprintf(seat_belts.filename, "%s%s%sbelts.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	seat_belts.x		= xres * 0.7 - SYMBOL_WIDTH / 2;
	seat_belts.y		= yres * 0.4 - SYMBOL_HEIGHT / 2;
	seat_belts.color	= YELLOW;
	seat_belts.alpha	= TRANSPARENT;
	
	sprintf(arduino.filename, "%s%s%sarduino.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	arduino.x		= xres * 0.8 - SYMBOL_WIDTH / 2;
	arduino.y		= yres * 0.4 - SYMBOL_HEIGHT / 2;
	arduino.color	= RED;
	arduino.alpha	= TRANSPARENT;
	
	// --------- MIDDLE-DOWN SYMBOLS --------- //
	
	sprintf(wrench.filename, "%s%s%swrench.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	wrench.x		= xres * 0.4 - SYMBOL_WIDTH / 2;
	wrench.y		= yres * 0.6 - SYMBOL_HEIGHT / 2;
	wrench.color	= YELLOW;
	wrench.alpha	= TRANSPARENT;
	
	sprintf(fuel.filename, "%s%s%sfuel.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	fuel.x		= xres * 0.5 - SYMBOL_WIDTH / 2;
	fuel.y		= yres * 0.6 - SYMBOL_HEIGHT / 2;
	fuel.color	= YELLOW;
	fuel.alpha	= TRANSPARENT;
	
	sprintf(choke.filename, "%s%s%schoke.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	choke.x		= xres * 0.6 - SYMBOL_WIDTH / 2;
	choke.y		= yres * 0.6 - SYMBOL_HEIGHT / 2;
	choke.color	= YELLOW;
	choke.alpha	= TRANSPARENT;
	
	// ----------------------------- //
	// ------- LOWER SYMBOLS ------- //
	// ----------------------------- //
	
	sprintf(battery.filename, "%s%s%sbattery.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	battery.x		= xres * 0.17 - SYMBOL_WIDTH / 2;
	battery.y		= yres * 0.85 - SYMBOL_HEIGHT / 2;
	battery.color	= RED;
	battery.alpha	= TRANSPARENT;
	
	sprintf(oil.filename, "%s%s%soil.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	oil.x		= xres * 0.34 - SYMBOL_WIDTH / 2;
	oil.y		= yres * 0.85 - SYMBOL_HEIGHT / 2;
	oil.color	= RED;
	oil.alpha	= TRANSPARENT;
	
	sprintf(engine.filename, "%s%s%sengine.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	engine.x		= xres * 0.5 - SYMBOL_WIDTH / 2;
	engine.y		= yres * 0.85 - SYMBOL_HEIGHT / 2;
	engine.color	= YELLOW;
	engine.alpha	= TRANSPARENT;
	
	sprintf(temp.filename, "%s%s%stemp.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	temp.x		= xres * 0.66 - SYMBOL_WIDTH / 2;
	temp.y		= yres * 0.85 - SYMBOL_HEIGHT / 2;
	temp.color	= RED;
	temp.alpha	= TRANSPARENT;
	
	sprintf(alternator.filename, "%s%s%salt.bmp",sys.main_dir,sys.image_dir,sys.symbol_dir);
	alternator.x		= xres * 0.83 - SYMBOL_WIDTH / 2;
	alternator.y		= yres * 0.85 - SYMBOL_HEIGHT / 2;
	alternator.color	= RED;
	alternator.alpha	= TRANSPARENT;
	
	// ----------------------------- //
	// ---------- GAUGES ----------- //
	// ----------------------------- //
	
	sprintf(big_gauge.filename, "%s%s%sg00_big.bmp",sys.main_dir,sys.image_dir,sys.gauge_dir);
	big_gauge.x		= CENTER_SCREEN;
	big_gauge.y		= yres * 0.4 - BIG_GAUGE_HEIGHT / 2; 
	big_gauge.color	= GREEN;
	big_gauge.alpha	= TRANSPARENT;
	
	sprintf(km_l_label.filename, "%s%s%skm_l.bmp",sys.main_dir,sys.image_dir,sys.label_dir);
	km_l_label.x		= CENTER_SCREEN;
	km_l_label.y		= yres * 0.4 + BIG_GAUGE_HEIGHT / 2 - BIG_LABEL_HEIGHT;
	km_l_label.color	= DEFAULT;
	km_l_label.alpha	= TRANSPARENT;
	
	sprintf(med_gauge_01.filename, "%s%s%sg00_medium.bmp",sys.main_dir,sys.image_dir,sys.gauge_dir);
	med_gauge_01.x		= xres * 0.25 - MED_GAUGE_WIDTH / 2;
	med_gauge_01.y		= yres * 0.6 - MED_GAUGE_HEIGHT / 2;
	med_gauge_01.color	= RED;
	med_gauge_01.alpha	= TRANSPARENT;
	
	sprintf(volts_label.filename, "%s%s%svolts.bmp",sys.main_dir,sys.image_dir,sys.label_dir);
	volts_label.x		= xres * 0.25 - MED_LABEL_WIDTH / 2;
	volts_label.y		= yres * 0.6 + MED_GAUGE_HEIGHT / 2 - MED_LABEL_HEIGHT;
	volts_label.color	= DEFAULT;
	volts_label.alpha	= TRANSPARENT;
	
	sprintf(med_gauge_02.filename, "%s%s%stemp.bmp",sys.main_dir,sys.image_dir,sys.gauge_dir);
	med_gauge_02.x		= xres * 0.75 - MED_GAUGE_WIDTH / 2;
	med_gauge_02.y		= yres * 0.6 - MED_GAUGE_HEIGHT / 2;
	med_gauge_02.color	= YELLOW;
	med_gauge_02.alpha	= TRANSPARENT;
	
	sprintf(temp_label.filename, "%s%s%stemp.bmp",sys.main_dir,sys.image_dir,sys.label_dir);
	temp_label.x		= xres * 0.75 - MED_LABEL_WIDTH / 2;
	temp_label.y		= yres * 0.6 + MED_GAUGE_HEIGHT /2 - MED_LABEL_HEIGHT;
	temp_label.color	= YELLOW;
	temp_label.alpha	= TRANSPARENT;
}