/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "raster.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BYTES_PER_SCREEN 32000

void plot_pixel(char *base, int x, int y);
void plot_bitmap_uneven(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines, unsigned int offset);
void draw_Line(char *base,unsigned int startX,unsigned int startY, unsigned int endX,unsigned int endY);
void plot_bitmap(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines);
void clear_bitmap(long int *base, unsigned int x, unsigned int y, long int map[]);
void fill_screen(char *base, char pattern);
int abs();
void clear_screen();


/*
	Purpose: clear the screen
	Input  : nothing
	Returns: nothing, but calls an assembly function to wipe the screen clear
	Assume : nothing
*/
void test_Clear()
{
	clear_screen();
}

/*
	Purpose: fill the screen
	Input  : a pointer to the frame buffer, and the pattern of black
	Returns: nothing, but turns screen black
	Assume : nothing
*/
void fill_screen(char *base, char pattern)
{
	register int i = 0;
	register char *loc = base;

	while (i++ < BYTES_PER_SCREEN)
		*(loc++) = pattern;
}

/*
	Purpose: plot a single pixel at an x and y coordinate
	Input  : pointer to frame buffer and the coordinates
	Returns: nothing, but flips the pixel at the coordinates
	Assume : nothing
*/
void plot_pixel(char *base, int x, int y)
{
	if(x >=0 && x < SCREEN_WIDTH && y >=0 && y < SCREEN_HEIGHT)
	{
		*(base + y * 80 + (x >>3)) |= 1 << 7 - (x & 7);
	}
}

/*
	Purpose: clear a bitmap on the screen
	Input  : a pointer to the frame buffer, an x and y coordinate, and a bitmap to clear
	Returns: nothing, but clears bitmap from screen
	Assume : nothing
*/
void clear_bitmap(long int *base, unsigned int x, unsigned int y, long int map[])
{
	int i,j = 0;
	long int *region = (base + 20 * y) + (x >> 5);
	
	for(i = 0; i < 400; i++)
	{
		for(j = 0; j < 20; j++)
		{
			*region &= *map;
			region += 20;
		}
	}
	
}

/*
	Purpose: plot a bitmap over a word boundary
	Input  : a pointer to the frame buffer, an x and y coordinate, a bitmap to map, the height of the bitmap, and the offset from 32
	Returns: nothing, but calls plot_bitmap againt to plot the two halves
	Assume : nothing
*/
void plot_bitmap_uneven(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines, unsigned int offset){
	unsigned long left_half_bitmap[32] = {0};
	unsigned long right_half_bitmap[32] = {0};
	int count = 0;
	
	while(count < numLines){
		left_half_bitmap[count] = (map[count] >> offset);
		right_half_bitmap[count] = (map[count] << (32 - offset));
		count++;
	}
	plot_bitmap(base, x-offset, y, left_half_bitmap, numLines);
	plot_bitmap(base, x+(32-offset), y, right_half_bitmap, numLines);
	
}

/*
	Purpose: plot a bitmap
	Input  : a pointer to the frame buffer, an x and y coordinate, a bitmap to map, the height of the bitmap
	Returns: nothing, but plots the bitmap into the frame buffer at the coordinates
	Assume : nothing
*/
void plot_bitmap(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines){
	int line = 0;
	unsigned int unevenOffset = x % 32;
	long int *region = (base + 20 * y) + (x >> 5);
	if(y > 367){
		y = 367;
	}
	if (unevenOffset != 0){
		plot_bitmap_uneven(base, x, y, map, numLines, unevenOffset);
	}
	
	else {
		for (line = 0; line < numLines; line++){
			*region |= *map;
			map++;
			region += 20;
		}
	}
}

/*
	Purpose: plot a line from a point to an end point
	Input  : a pointer to the frame buffer, a starting x and y position, and an ending x and y position
	Returns: nothing, but changes frame buffer to have the line in there
	Assume : nothing
	
	Uses bresenham's line algorithm to figure out which quadrant.
*/
void draw_Line(char *base,unsigned int startX,unsigned int startY, unsigned int endX,unsigned int endY)
{
	int longest,shortest,numerator,i;
	int w = endX - startX;
    int h = endY - startY;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
 
	if (w < 0){
		dx1 = -1;
	}		
	else if (w > 0){
		dx1 = 1 ;
	}
    if (h<0){ 
		dy1 = -1;
	}		
	else if (h>0){
		dy1 = 1;
	}
    if (w<0){
		dx2 = -1;
	}		
	else if (w>0){ 
		dx2 = 1;
	}
	
    longest = abs(w);
    shortest = abs(h);
    
	if (!(longest > shortest)) {
        longest = abs(h) ;
        shortest = abs(w) ;
        if (h < 0){
			dy2 = -1;
		}	
		else if (h > 0){
			dy2 = 1;
		}
        dx2 = 0;            
    }
	
	numerator = longest >> 1;
    
	for (i=0; i <= longest; i++) {
        plot_pixel(base,startX,startY);
        numerator += shortest;
        if (!(numerator<longest)) {
            numerator -= longest;
            startX += dx1;
            startY += dy1;
        } else {
            startX += dx2;
            startY += dy2;
        }
    }

}
