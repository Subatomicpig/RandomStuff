/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef VBL_ISR_H
#define VBL_ISR_H

void VBL_ISR();
typedef void (*Vector)();
Vector install_vector(int num, Vector vector);

#endif