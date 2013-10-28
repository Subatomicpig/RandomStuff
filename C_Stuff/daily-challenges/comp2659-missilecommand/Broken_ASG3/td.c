/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "raster.h"
#include "model.h"
#include "clear_qk.h"
#include "td.h"
#include "animator.h"
#include <linea.h>
#include <osbind.h>
#include <stdio.h>

#define IS_DOWN ((int)CUR_MS_STAT & 0x1)
#define BYTES_PER_SCREEN 32000

/*
	Purpose: Test driver test all the functions
*/
void testRender(char *base, long *iBase,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo middle_Silo,struct missile mis,struct explosion exp);
void testRaster(char*, long int*);
void testModel();

/*
	Purpose: Call all test driver functions to ensure game is functional
	Input  : none
	Returns: none, but outputs all relevant data and updates the screen depending on which driver is called
	Assume : none
*/
int main()
{

	/*frame buffer*/
	char *base;	
	const char *originalBase;
	long int *iBase;
	unsigned long test = 0xFFFFFFFF;
	unsigned short mouseX,mouseY;
	int clicked = 0;
	
	
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
	
	struct missile enemyMis = {100,100,10,0,0};
	struct explosion exp = {0,0,0,0};

	linea0();
	originalBase = Physbase();
	base = Physbase();
	iBase = Physbase();
	
	animate_main(base,iBase);

	
	Setscreen(originalBase,originalBase,-1);
			

	return 0;
}



/*
	Purpose: Test all the rendering functions
	Input  : frame buffer pointer and the structs to render
	Returns: test data and screen for render functions
	Assume : nothing
*/
void testRender(char *base, long *iBase,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo middle_Silo,struct missile mis,struct explosion exp)
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

	

}


/*
	Purpose: Test all the model functions
	Input  : nothing
	Returns: test data about model functions
	Assume : nothing
*/
void testModel(){
    struct city test_City = {1,120,350};
    struct missile_Silo test_Silo = {10,1,300,350};
    struct missile test_Missile = {100,100,10,0,0};

    /* Working */
    printf("City Health Before Test is: %d\n",test_City.health);
    destroy_City(&test_City);
    printf("City Health is: %d\n",test_City.health);

    printf("Silo Ammo Before Test is: %d\n",test_Silo.ammo);
    update_Ammo(&test_Silo);
    printf("Silo Ammo is: %d\n",test_Silo.ammo);

    printf("Silo Before Destroyed is: %d\n",test_Silo.health);
    destroy_Silo(&test_Silo);
    printf("Silo After Destroyed is: %d\n",test_Silo.health);

    printf("Testing missile movement position before X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);
    missile_Movement(11,11,&test_Missile);
    printf("Testing missile movement position after X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);

	/*
    printf("Testing enemy missile fired :%d\n",test_Missile.team);
    test_Missile = enemy_Missile_Fired();
    printf("Testing enemy missile fired :%d\n",test_Missile.team);

    printf("Testing friendly missile fired :%d\n",test_Missile.team);
    test_Missile = friendly_Missile_Fired(100,100);
    printf("Testing friendly missile fired :%d\n",test_Missile.team);
	*/
}

/*
	Purpose: Test all the raster functions
	Input  : two frame buffer bases, one 8 bit and one 32 bit
	Returns: test data for raster and the updated test screen
	Assume : nothing
*/
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

	/*plot_bitmap(iBase,100,200,explosions[0],32);
	plot_bitmap(iBase,180,200,explosions[1],32);
	plot_bitmap(iBase,260,200,explosions[2],32);
	plot_bitmap(iBase,340,200,explosions[3],32);
	plot_bitmap(iBase,420,200,explosions[4],32);
	plot_bitmap(iBase,500,200,explosions[5],32);

	plot_bitmap(iBase,100,100,missile_bitmap,32);
	draw_Line(base,0,0,100,100);*/
	
	while (count < 20){
		plot_bitmap(iBase,x,368,blackBox,32);
		count++;
		x += 32;
	}
}
