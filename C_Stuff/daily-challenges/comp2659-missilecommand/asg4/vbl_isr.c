#include <stdio.h>
#include <osbind.h>
#include "set_vb~1.h"
#include "animator.h"


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