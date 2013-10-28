#include "raster.h"
#include "model.h"
#include "clear_qk.h"
#include "td.h"
#include "animator.h"
#include "input.h"
#include <linea.h>
#include <osbind.h>
#include <stdio.h>



int main()
{
	
	char *base;	
	const char *originalBase;
	long int *iBase;
	unsigned long test = 0xFFFFFFFF;
	unsigned short mouseX,mouseY;
	int clicked = 0;
	
	
	linea0();
	originalBase = Physbase();
	base = Physbase();
	iBase = Physbase();
	
	animate_main(base,iBase);
	
	Setscreen(originalBase,originalBase,-1);


	return 0;
}