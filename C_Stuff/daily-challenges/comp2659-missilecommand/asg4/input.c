/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "input.h"
#include <osbind.h>
#include <linea.h>
#define IS_DOWN ((int)CUR_MS_STAT & 0x1)


volatile UBYTE *const IKBD_control = 0xFFFFFC00;
volatile const UBYTE *const IKBD_status = 0xFFFFFC00;
volatile const SCANCODE * const IKBD_Data = 0xFFFFFC02;



/*
	Purpose: recieve make and break codes and update the model accordingly
	Input  : int values for mouseClicked deltaX deltaY and the currrent state of the mouse 0 move input recieved 1 first byte 2 second byte
	Returns: updated Mouse state after a byte has been read the change in x and y as wll as if the mouse has been clicked
	Assume : nothing
*/
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



/*
	Purpose: move the mouse smoothly using the linea functions
	Input  : short x,y for the change in mouse cursor position
	Returns: short x,y
	Assume : nothing
*/
int get_mouse_pos(unsigned short *x, unsigned short *y)
{
	(*x) = GCURX;
	(*y) = GCURY;
	return IS_DOWN;
}



/*
	Purpose: reads the current scancode if the RDR is full
	Input  : nothing
	Returns: the current scancode in the data register
	Assume : nothing
*/
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