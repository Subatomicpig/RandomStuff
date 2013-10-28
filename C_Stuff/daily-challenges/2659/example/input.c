#include "input.h"
#include <osbind.h>


volatile UBYTE *const IKBD_control = 0xFFFFFC00;
volatile const UBYTE *const IKBD_status = 0xFFFFFC00;
volatile const SCANCODE * const IKBD_Data = 0xFFFFFC02;



SCANCODE mouseMoved = 0xF8;
SCANCODE mouseClick = 0xFA;
	

int read_click()
{
	SCANCODE code;
	int click = 0;
	long oldSSP;
	
	oldSSP = Super(0);
	
	
	
	code = read_scancode();
	
	if(code == mouseClick)
		click = 1;
	
	Super(oldSSP);

	return click;
}
	
	
void read_input(int x, int y)
{
	long oldSSP;
	
	SCANCODE currentCode;
	
	oldSSP = Super(0);
	
	currentCode = read_scancode();
	
	/*read if the mouse was moved*/
	if(currentCode == mouseMoved)
	{
		while(!(*IKBD_status & 0x01))
			;
		x = *IKBD_Data;
		
		while(!(*IKBD_status & 0x01))
			;
			
		y = *IKBD_Data;
	
	}
	
	Super(oldSSP);

}




SCANCODE read_scancode()
{

	while(!(*IKBD_status & 0x01))
		;	
		
	return *IKBD_Data;	
	
}