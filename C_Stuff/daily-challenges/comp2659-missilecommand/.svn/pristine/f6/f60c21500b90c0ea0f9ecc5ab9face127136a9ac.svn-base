/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "effects.h"
#include "sound.h"



/*
	Purpose: creates the missile fired sound
	Input  : nothing but calls other helper functions to create the effect
	Returns: nothing
	Assume : nothing
*/
void missile_fired_sound()
{
	set_noise(0x7F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x54);
}


/*
	Purpose: creates the explosion sound
	Input  : nothing but calls other helper functions to create the effect
	Returns: nothing
	Assume : nothing
*/
void explosion_sound()
{
	set_noise(0x1F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x38);
}


/*
	Purpose: creates the city destruction sound
	Input  : nothing but calls other helper functions to create the effect
	Returns: nothing
	Assume : nothing
*/
void city_destruction_sound()
{
	set_noise(0x2F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x38);
}