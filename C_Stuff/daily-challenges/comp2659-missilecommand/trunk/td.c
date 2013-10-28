#include "raster.h"
#include "model.h"
#include "raster.c"
#include "model.c"
#include "renderer.c"
#include "clear_qk.h"


#include <osbind.h>
#include <stdio.h>


#define BYTES_PER_SCREEN 32000
void testRender(char *base, long *iBase,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo middle_Silo);
void testRaster(char*, long int*);
void testModel();

int main()
{

	/*frame buffer*/
	char *base;	
	long int *iBase;
	unsigned long test = 0xFFFFFFFF;


	/*Code for the current state of the game the inital state*/
	int p1_Score = 0;

	/*The silo position*/
	struct missile_Silo middle_Silo = {10,1,300,350};

	/*city position*/
	struct city city1 = {1,120,350};
	struct city city2 = {1,200,350};
	struct city city3 = {1,280,350};
	struct city city4 = {1,360,350};
	struct city city5 = {1,440,350};
	struct city city6 = {1,520,350};
	
	struct missile enemyMis[20];

	enemyMis[0].currentX = 100;
	
	base = Physbase();
	iBase = Physbase();
	
	testRaster(base,iBase);
	Cnecin();
	test = test ;

	testRender(base,iBase,city1,city2,city3,city4,city5,city6,middle_Silo);
	Cnecin();
	test = test;
	

	return 0;
}



void testRender(char *base, long *iBase,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo middle_Silo)
{
	/*update the city and silo positions to be in the correct spot*/
	city1.pX = 64;
	city2.pX = 144;
	city3.pX = 224;
	city4.pX = 384;
	city5.pX = 464;
	city6.pX = 544;
	
	city1.pY = 336;
	city2.pY = 336;
	city3.pY = 336;
	city4.pY = 336;
	city5.pY = 336;
	city6.pY = 336;
	
	middle_Silo.pX = 288;
	middle_Silo.pY = 336;
	
	clear_screen(base);
	/*draw one frame*/
	render_main(iBase,city1,city2,city3,city4,city5,city6,middle_Silo);
	draw_Line(base,0,0,100,100);
	plot_bitmap(iBase,100,100,missile_bitmap,32);
	

}

/* model.c test driver */
void testModel(){
    struct city test_City = {1,120,350};
    struct missile_Silo test_Silo = {10,1,300,350};
    struct missile test_Missile = {100,100,10,10,0,0};

    /* Working */
    printf("City Health Before Test is: %d\n",test_City.health);
    test_City = destroy_City(test_City);
    printf("City Health is: %d\n",test_City.health);

    printf("Silo Ammo Before Test is: %d\n",test_Silo.ammo);
    test_Silo = update_Ammo(test_Silo);
    printf("Silo Ammo is: %d\n",test_Silo.ammo);

    printf("Silo Before Destroyed is: %d\n",test_Silo.health);
    test_Silo = destroy_Silo(test_Silo);
    printf("Silo After Destroyed is: %d\n",test_Silo.health);

    printf("Testing missile movement position before X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);
    test_Missile = missile_Movement(11,11,test_Missile);
    printf("Testing missile movement position after X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);

    printf("Testing missile destroyed Before:%d\n",test_Missile.destroyed);
    test_Missile = missile_Destroyed(test_Missile);
    printf("Testing missile destroyed After:%d\n",test_Missile.destroyed);

    printf("Testing enemy missile fired :%d\n",test_Missile.team);
    test_Missile = enemy_Missile_Fired();
    printf("Testing enemy missile fired :%d\n",test_Missile.team);

    printf("Testing friendly missile fired :%d\n",test_Missile.team);
    test_Missile = friendly_Missile_Fired(100,100);
    printf("Testing friendly missile fired :%d\n",test_Missile.team);

    printf("Testing silo choice:%d\n",choose_silo(1));
    printf("Testing silo choice:%d\n",choose_silo(200));
    printf("Testing silo choice:%d\n",choose_silo(500));
}

/* raster.c test driver */
void testRaster(char *base, long *iBase){
	int count = 0;
	int x = 0;

	clear_screen(base);
	

	
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
}
