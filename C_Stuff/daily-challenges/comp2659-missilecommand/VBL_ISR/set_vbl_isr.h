/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef SET_VBL_ISR_H
#define SET_VBL_ISR_H

typedef void (*Vector)();
void VBL_ISR(int render);
Vector install_vector(int num, Vector vector);
void VBL_ISR_Original();
Vector init_VBL_ISR(Vector original_Vector);

#endif