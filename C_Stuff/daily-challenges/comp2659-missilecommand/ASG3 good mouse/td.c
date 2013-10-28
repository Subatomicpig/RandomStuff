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
	int clicked = 0;
	
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

void testRender(char *base, long *iBase,struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6,struct missile_Silo middle_Silo,struct missile mis,struct explosion exp)
{
	/*update the city and silo positions to be in the correct spot
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
	/*draw one frame

}
*/


