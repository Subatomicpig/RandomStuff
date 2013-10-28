/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "raster.h"
#include "clear_qk.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BYTES_PER_SCREEN 32000

/*
	Purpose: Define all the bitmaps in our game
*/
unsigned long int clear_Screen[CLEAR_SCREEN] =
{
	0x00000000
};

unsigned long int explosion_bitmap[EXPLOSION] =
{
	0x00000000	
};

unsigned long int missile_bitmap[MISSILE] = 
{
	0x60000000,
	0xF0000000,
	0xF0000000,
	0x60000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000

};

unsigned long int cityLeft_bitmap[CITY_LEFT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x03EFC000,
	0x07EFC000,
	0x07EFC000,
	0x07FFE000,
	0x07FFE000,
	0x03FFE000,
	0x03FFE000,
	0x03FFE03A,
	0x03FFE03F,
	0xE1FFE3FF,
	0xE1FFE3FF,
	0xE1FFE3FF,
	0xE7FFE3FF,
	0xFFFFE3FF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF
};

unsigned long int cityRight_bitmap[CITY_RIGHT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0003F7C0,
	0x0003F7E0,
	0x0003F7E0,
	0x0007FFE0,
	0x0007FFE0,
	0x0007FFC0,
	0x0007FFC0,
	0x1C07FFC7,
	0xFC07FFC7,
	0xFFC7FFC7,
	0xFFC7FFC7,
	0xFFC7FFE7,
	0xFFC7FFEF,
	0xFFFFFFEF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF
};

unsigned long int destroyed_city[DESTROYED_CITY] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000020,
	0x00000030,
	0x03F80070,
	0x0FFFE070,
	0x1FFFF1F0,
	0x1FFFFFF0,
	0x1FFFFFF0,
	0x3FFFFFF8,
	0x7FFFFFFE,
	0xFFFFFFFF
};
	

unsigned long int siloLeft_bitmap[SILO_LEFT] = 
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000400,
	0x00000E00,
	0x00001F00,
	0x00003F80,
	0x00007FC0,
	0x0000FFFF,
	0x0001FFFF,
	0x0003FFFF,
	0x0007FFFF,
	0x000FFFFF,
	0x001FFFFF,
	0x003FFFFF,
	0x007FFFFF,
	0x00FFFFFF,
	0x01FFFFFF,
	0x03FFFFFF,
	0x07FFFFFF,
	0x0FFFFFFF,
	0x1FFFFFFF,
	0x3FFFFFFF,
	0x7FFFFFFF,
	0xFFFFFFFF
};

unsigned long int siloRight_bitmap[SILO_RIGHT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00200000,
	0x00700000,
	0x00F80000,
	0x01FC0000,
	0x03FE0000,
	0xFFFF0000,
	0xFFFF8000,
	0xFFFFC000,
	0xFFFFE000,
	0xFFFFF000,
	0xFFFFF800,
	0xFFFFFC00,
	0xFFFFFE00,
	0xFFFFFF00,
	0xFFFFFF80,
	0xFFFFFFC0,
	0xFFFFFFE0,
	0xFFFFFFF0,
	0xFFFFFFF8,
	0xFFFFFFFC,
	0xFFFFFFFE,
	0xFFFFFFFF
};

unsigned long int blackBox[BLACKBOX] =
{
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF
};

unsigned long int explosions[TOTAL_EXPLOSIONS][EXPLOSION] =
{	{
	0x00000000, /* Phase 1 */
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0003C000,
	0x000FF000,
	0x000FF000,
	0x001FF800,
	0x001FF800,
	0x001FF800,
	0x001FF800,
	0x000FF000,
	0x000FF000,
	0x0003C000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	},{
	0x00000000, /* Phase 2 */
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0007E000,
	0x000FF000,
	0x003FFC00,
	0x003FFC00,
	0x007FFE00,
	0x00FFFF00,
	0x00FFFF00,
	0x00FFFF00,
	0x00FFFF00,
	0x00FFFF00,
	0x00FFFF00,
	0x007FFE00,
	0x003FFC00,
	0x003FFC00,
	0x000FF000,
	0x0007E000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,		
	},{
	0x00000000, /* Phase 3 */
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0007E000,
	0x001FF800,
	0x007FFE00,
	0x00FFFF00,
	0x00FFFF00,
	0x01FFFF80,
	0x01FFFF80,
	0x03FFFFC0,
	0x03FFFFC0,
	0x03FFFFC0,
	0x03FFFFC0,
	0x03FFFFC0,
	0x03FFFFC0,
	0x01FFFF80,
	0x01FFFF80,
	0x00FFFF00,
	0x00FFFF00,
	0x007FFE00,
	0x001FF800,
	0x0007E000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	},{
	0x00000000, /* Phase 4 */
	0x00000000,
	0x00000000,
	0x00000000,
	0x0007E000,
	0x001FF800,
	0x007FFE00,
	0x00FFFF00,
	0x01FFFF80,
	0x03FFFFC0,
	0x03FFFFC0,
	0x07FFFFE0,
	0x07FFFFE0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x07FFFFE0,
	0x07FFFFE0,
	0x03FFFFC0,
	0x03FFFFC0,
	0x01FFFF80,
	0x00FFFF00,
	0x007FFE00,
	0x001FF800,
	0x0007E000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	},{
	0x00000000, /* Phase 5 */
	0x00000000,
	0x0007E000,
	0x003FFC00,
	0x00FFFF00,
	0x01FFFF80,
	0x03FFFFC0,
	0x07FFFFE0,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x1FFFFFF8,
	0x1FFFFFF8,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x1FFFFFF8,
	0x1FFFFFF8,
	0x0FFFFFF0,
	0x0FFFFFF0,
	0x07FFFFE0,
	0x03FFFFC0,
	0x01FFFF80,
	0x00FFFF00,
	0x003FFC00,
	0x0007E000,
	0x00000000,
	0x00000000,
	},{
	0x000FF000, /* Phase 6 */
	0x007FFE00,
	0x01FFFF80,
	0x03FFFFC0,
	0x07FFFFE0,
	0x0FFFFFF0,
	0x1FFFFFF8,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x7FFFFFFE,
	0x7FFFFFFE,
	0x7FFFFFFE,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0x7FFFFFFE,
	0x7FFFFFFE,
	0x7FFFFFFE,
	0x3FFFFFFC,
	0x3FFFFFFC,
	0x1FFFFFF8,
	0x0FFFFFF0,
	0x07FFFFE0,
	0x03FFFFC0,
	0x01FFFF80,
	0x007FFE00,
	0x000FF000
	}
};

unsigned long int mouse[MOUSE] =
{
	0x30000000,
	0x30000000,
	0xCC000000,
	0xCC000000,
	0x30000000,
	0x30000000
};


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
	{
		*(loc++) = pattern;
	}
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
	
	for(i = 0; i < SCREEN_HEIGHT; i++)
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
void plot_bitmap_uneven(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines, unsigned int offset)
{
	unsigned long left_half_bitmap[32] = {0};
	unsigned long right_half_bitmap[32] = {0};
	int count = 0;
	
	while(count < numLines)
	{
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
void plot_bitmap(long int *base, unsigned int x, unsigned int y, unsigned long int map[], int numLines)
{
	int line = 0;
	unsigned int unevenOffset = x % 32;
	long int *region = (base + 20 * y) + (x >> 5);
	if(y > 367)
	{
		y = 367;
	}
	if (unevenOffset != 0)
	{
		plot_bitmap_uneven(base, x, y, map, numLines, unevenOffset);
	}
	else 
	{
		for (line = 0; line < numLines; line++)
		{
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
 
	if (w < 0)
	{
		dx1 = -1;
	}		
	else if (w > 0)
	{
		dx1 = 1 ;
	}
    if (h<0)
	{ 
		dy1 = -1;
	}		
	else if (h>0)
	{
		dy1 = 1;
	}
    if (w<0)
	{
		dx2 = -1;
	}		
	else if (w>0)
	{ 
		dx2 = 1;
	}
	
    longest = abs(w);
    shortest = abs(h);
    
	if (!(longest > shortest)) 
	{
        longest = abs(h);
        shortest = abs(w);
        if (h < 0)
		{
			dy2 = -1;
		}	
		else if (h > 0)
		{
			dy2 = 1;
		}
        dx2 = 0;            
    }
	
	numerator = longest >> 1;
    
	for (i=0; i <= longest; i++) 
	{
        plot_pixel(base,startX,startY);
        numerator += shortest;
        if (!(numerator<longest)) 
		{
            numerator -= longest;
            startX += dx1;
            startY += dy1;
        }
		else 
		{
            startX += dx2;
            startY += dy2;
        }
    }
}
