#include "input.h"
#include <osbind.h>
#include <linea.h>
#define IS_DOWN ((int)CUR_MS_STAT & 0x1)


volatile UBYTE *const IKBD_control = 0xFFFFFC00;
volatile const UBYTE *const IKBD_status = 0xFFFFFC00;
volatile const SCANCODE * const IKBD_Data = 0xFFFFFC02;
	
void read_input(int *mouseState, int *deltaX, int *deltaY,int *mouseClicked)
{	
	SCANCODE mouseClick = 0xF8;

	

	long oldSSP;
	SCANCODE currentCode;
	oldSSP = Super(0);

	if((*mouseState) == 2 && (*IKBD_status & 0x01))
		{
			(*deltaY) = *IKBD_Data;
			(*mouseState) = 0;
		}
		else if((*mouseState) == 1 && (*IKBD_status & 0x01))
		{
			(*deltaX) = *IKBD_Data;
			(*mouseState) = 2;
		}
		else if((*mouseState) == 0 && (*IKBD_status & 0x01))
		{
			(*mouseState) = 1;
		}
		
	if((*IKBD_status & 0x01))
	{
		currentCode = read_scancode();
		if(currentCode == mouseClick)
		{
			(*mouseClicked) = 1;
		}
	}
	
	Super(oldSSP);
}


int get_mouse_pos(unsigned short *x, unsigned short *y)
{
	(*x) = GCURX;
	(*y) = GCURY;
	return IS_DOWN;
}

SCANCODE read_scancode()
{	
	long oldSSP;
	SCANCODE data;
	
	oldSSP = Super(0);
	
	while(!(*IKBD_status & 0x01))
		;	
		
	data = *IKBD_Data;	
	Super(oldSSP);
	return data;
	
}