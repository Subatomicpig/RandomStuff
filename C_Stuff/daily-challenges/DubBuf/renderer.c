/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "raster.h"
#include "model.h"
#include <stdlib.h>
#include <time.h>
#include "clear_qk.h"

/*
	Purpose: takes structs from the model and renders them to the screen
*/
void render_main(long int *base,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo silo,struct missile mis[],struct missile mis2[],struct explosion exp[],int mouseX,int mouseY);
void render_city(long int *base,struct city city);
void render_silo(long int *base,struct missile_Silo silo);
void render_missile(long int *base, struct missile mis[]);
void black_box(long* base);
void render_explosion(long int *base,struct explosion exp[]);
void render_Mouse(long int *base,int mouseX,int mouseY);






/*
	Purpose: Render everything in the game that could appear on the screen
	Input  : structs on screen, missiles, and explosions to update
	Returns: updates the frame buffer to represent new game state
	Assume : the game has one missile, one explosion, and all cities and the silo are already initialized
*/
void render_main(long int *base,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo silo, struct missile mis[],struct missile mis2[], struct explosion exp[],int mouseX,int mouseY)
{
	
	render_city(base,city1);
	render_city(base,city2);
	render_city(base,city3);
	render_city(base,city4);
	render_city(base,city5);
	render_city(base,city6);
	render_silo(base,silo);
	black_box(base);
	render_missile(base,mis);
	render_missile(base,mis2);
	render_explosion(base,exp);
	render_Mouse(base,mouseX,mouseY);
}





void render_Mouse(long int *base,int mouseX,int mouseY)
{
	plot_bitmap(base,mouseX,mouseY,mouse,6);
}
/*
	Purpose: checks if the explosion is being displayed then renders it
	Input  : the frame buffer base, and an explosion structure
	Output : updated explosion state in the frame buffer and on the screen
	Assume : nothing
*/
void render_explosion(long int *base,struct explosion exp[])
{
	int i = 0;
	for (i = 0; i < 40; i++){
		if (exp[i].exists == 1){
			plot_bitmap(base,exp[i].pX - 16,exp[i].pY - 16,explosions[exp[i].size],32);
		}
	}
}

/*
	Purpose: checks if the city is being displayed and renders it
	Input  : the frame buffer base, and a city structure
	Output : a new city at the cities initialized location, and on the screen
	Assume : city is initialized (pX and pY are both set to correct values)
*/
void render_city(long int *base,struct city city)
{
	plot_bitmap(base,city.pX,city.pY,cityLeft_bitmap,32);
	
}

/*
	Purpose: checks if the missile is being displayed and renders it
	Input  : the frame buffer base, and a missile structure
	Output : updated missile in the frame buffer and on the screen, as well as a line going to the missile
			 from the starting point
	Assume:  nothing
*/
void render_missile(long int *iBase, struct missile mis[])
{
	char *base= (char*) iBase;
	int i;
	for (i = 0; i < 20; i++)
		if (mis[i].destroyed == 0){
			/*draw_Line(base,mis[i].startX,0,mis[i].currentX,mis[i].currentY);*/
			plot_bitmap(iBase,mis[i].currentX,mis[i].currentY,missile_bitmap,4);
		}

}

/*
	Purpose: checks if the silos are being rendered and renders them
	Input  : the frame buffer base, and a silo structure
	Output : updated frame buffer, and a silo on the screen
	Assume : silo has been initialized to correct values
*/
void render_silo(long int *base,struct missile_Silo silo)
{
	plot_bitmap(base,silo.pX,silo.pY,siloLeft_bitmap,32);
	plot_bitmap(base,silo.pX + 32,silo.pY,siloRight_bitmap,32);
	
}

/*
	Purpose: draws a black line at the bottom of the screen to act as the ground
	Input  : the frame buffer base
	Output : updated frame buffer, as well as a black box along the bottom of the screen
			 below the cities and silos
	Assume : Silos and cities are on the correct y coordinate
*/
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