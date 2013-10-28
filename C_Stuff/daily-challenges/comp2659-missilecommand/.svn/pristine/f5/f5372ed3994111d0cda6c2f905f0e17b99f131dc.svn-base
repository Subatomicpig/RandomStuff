/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "sound.h"
#include "music.h"
#include <osbind.h>


/*
	Purpose: Create the array of music
	Input  : Notes in the order to be played
	Returns: nothing
	Assume : nothing
*/
int music[] =
{	
	NOTE_C,
	NOTE_D,
	NOTE_F,
	NOTE_F,
	NOTE_E,
	NOTE_D,
	NOTE_C,
	NOTE_B,
	NOTE_A,
	NOTE_B,
	
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	
	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,
	
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	
	NOTE_A,
	NOTE_G,
	NOTE_F,
	NOTE_E,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	NOTE_E,
	NOTE_F,
	NOTE_E,
	NOTE_D,
	NOTE_C,
	NOTE_B,
	NOTE_A,
	NOTE_B,
	
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	NOTE_C,
	NOTE_B,
	
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	NOTE_C,
	NOTE_A,
	
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,
	NOTE_C,
	NOTE_F,

	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	NOTE_C,
	NOTE_E,
	
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D,
	NOTE_C,
	NOTE_D
};

/*
	Purpose: returns a pointer to the start of the music array
	Input  : nothing
	Returns: the pointer to the start of the array
	Assume : nothing
*/
int *get_music()
{
	return music;
}

/*
	Purpose: start the music playing
	Input  : channels to enable as well as volume
	Returns: nothing
	Assume : nothing
*/
void start_music()
{
	enable_channel(0,1,0);
	set_volume(0,8);
}

/*
	Purpose: plays the music using the current note 
	Input  : note to play
	Returns: nothing
	Assume : nothing
*/
void play_music(int note)
{
	set_tone(0,note);
}
