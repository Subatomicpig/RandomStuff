#include "raster.h"
#include "model.h"


void render_main(long int *base,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo silo);
void render_city(long int *base,struct city city);
void render_silo(long int *base,struct missile_Silo silo);
void render_missile(long int *base, struct missile mis);
void black_box(long* base);


/*ask donovan how we are going to render all the missiles*/
void render_main(long int *base,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo silo)
{
	render_city(base,city1);
	render_city(base,city2);
	render_city(base,city3);
	render_city(base,city4);
	render_city(base,city5);
	render_city(base,city6);
	render_silo(base,silo);
	black_box(base);
}

void render_city(long int *base,struct city city)
{
	plot_bitmap(base,city.pX,city.pY,cityLeft_bitmap,32);
	
}


void render_silo(long int *base,struct missile_Silo silo)
{
	plot_bitmap(base,silo.pX,silo.pY,siloLeft_bitmap,32);
	plot_bitmap(base,silo.pX + 32,silo.pY,siloRight_bitmap,32);
	
}

void render_missile(long int *base, struct missile mis)
{
	plot_bitmap(base,mis.currentX,mis.currentY,missile_bitmap,32);
}

void black_box(long int *iBase)
{
	int count = 0;
	int x = 0;
	
	while (count < 20){
		plot_bitmap(iBase,x,368,blackBox,32);
		count++;
		x += 32;
	}
}
