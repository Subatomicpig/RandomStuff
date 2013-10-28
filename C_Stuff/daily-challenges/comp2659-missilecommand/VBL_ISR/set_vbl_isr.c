#include <stdio.h>
#include <osbind.h>
#include "set_vb~1.h"
#include "animator.h"


Vector original_vector;


void VBL_ISR(int *render)
{

	/*set global flag to render */
	*render = 1;

}


Vector init_VBL_ISR(Vector original_Vector)
{
	Vector orVector = installvector(28,VL_ISR());
}

/*installs the orignal vbl isr*/
void install_Original_VBL_ISR(Vector original_vector)
{
	install_vector(28,original_vector);
}

/*installs a vector into a vector number*/
Vector install_vector(int num, Vector vector)
{
	Vector orig;
	Vector *vectp = (Vector *) ((long)num << 2);
	long old_ssp = Super(0);

	orig = *vectp;
	*vectp = vector;
	Super(old_ssp);
	return orig;
}