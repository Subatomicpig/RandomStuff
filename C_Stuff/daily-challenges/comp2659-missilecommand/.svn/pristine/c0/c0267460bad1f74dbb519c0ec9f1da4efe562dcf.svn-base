#include "sound.h"
#include "music.h"
#include <osbind.h>



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

int *get_music()
{
	return music;
}

void start_music()
{
	enable_channel(0,1,0);
	set_volume(0,8);
}

void play_music(int note)
{
	set_tone(0,note);
}
