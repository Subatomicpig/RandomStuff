/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include <osbind.h>
#include "raster.h"
/*
	Purpose: Test all the raster functions
	Input  : two frame buffer bases, one 8 bit and one 32 bit
	Returns: test data for raster and the updated test screen
	Assume : nothing
*/
int main()
{
	int count = 0;
	int x = 0;
	long *iBase = Physbase();
	char *base = Physbase();
	
	
	plot_bitmap(iBase,288,336,siloLeft_bitmap,32);
	plot_bitmap(iBase,320,336,siloRight_bitmap,32);

	plot_bitmap(iBase,64,336,cityLeft_bitmap,32);
	plot_bitmap(iBase,144,336,cityLeft_bitmap,32);
	plot_bitmap(iBase,224,336,cityLeft_bitmap,32);
	plot_bitmap(iBase,384,336,cityLeft_bitmap,32);
	plot_bitmap(iBase,464,336,cityLeft_bitmap,32);
	plot_bitmap(iBase,544,336,cityLeft_bitmap,32);

	plot_bitmap(iBase,100,200,explosions[0],32);
	plot_bitmap(iBase,180,200,explosions[1],32);
	plot_bitmap(iBase,260,200,explosions[2],32);
	plot_bitmap(iBase,340,200,explosions[3],32);
	plot_bitmap(iBase,420,200,explosions[4],32);
	plot_bitmap(iBase,500,200,explosions[5],32);

	plot_bitmap(iBase,100,100,missile_bitmap,32);
	draw_Line(base,0,0,100,100);
	
	while (count < 20){
		plot_bitmap(iBase,x,368,blackBox,32);
		count++;
		x += 32;
	}
	return 0;
}