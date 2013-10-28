/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _RASTER_H
#define _RASTER_H

#define CITY_LEFT 32
#define CITY_RIGHT 32
#define SILO_LEFT 32
#define SILO_RIGHT 32
#define MISSILE 32
#define EXPLOSION 32
#define CLEAR_SCREEN 32
#define MOUSE 6
#define TOTAL_EXPLOSIONS 6
#define BLACKBOX 32
#define DESTROYED_CITY
#define BORDER_LEFT 0
#define BORDER_RIGHT 639
#define BORDER_BOTTOM 399
#define BORDER_TOP 0


extern unsigned long int mouse[MOUSE];	
extern unsigned long int explosions[TOTAL_EXPLOSIONS][EXPLOSION];
extern unsigned long int clear_Screen[CLEAR_SCREEN];
extern unsigned long int explosion_bitmap[EXPLOSION];
extern unsigned long int missile_bitmap[MISSILE];
extern unsigned long int cityLeft_bitmap[CITY_LEFT];
extern unsigned long int cityRight_bitmap[CITY_RIGHT];
extern unsigned long int destroyed_city[DESTROYED_CITY];
extern unsigned long int siloLeft_bitmap[SILO_LEFT];
extern unsigned long int siloRight_bitmap[SILO_RIGHT];
extern unsigned long int blackBox[BLACKBOX];


void fill_screen(char *base, char pattern);
void plot_pixel(char *base, int x, int y);
void clear_bitmap(long int *base, unsigned int x, unsigned int y, long int map[]);
void plot_bitmap_uneven(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines, unsigned int offset);
void plot_bitmap(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines);
void draw_Line(char *base,unsigned int startX,unsigned int startY, unsigned int endX,unsigned int endY);



int abs();
void clear_screen();

#endif
