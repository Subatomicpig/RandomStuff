/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "sound.h"
#include "music.h"
#include "effects.h"
#include <stdio.h>

/*
	Purpose: Test all the music functions
	Input  : Notes we want to play as well has how long of a wait between them
	Returns: plays the music  and sound effects
	Assume : nothing
*/
int main()
{
	int j = 0;
	int i = 0;
	int *music;
	music = get_music();
	
	start_music();
	write_psg(0,0x3F);
	sleep(5);
	
	for (i = 0; i < 104; i++)
	{
		play_music(music[i]);
		while (j < 32000)
			j++;
		printf("%d \n",music[i]);
	}
	
	play_music(NOTE_C);
	sleep(1);
	play_music(NOTE_D);
	sleep(1);	
	play_music(NOTE_E);
	sleep(1);
	play_music(NOTE_F);
	sleep(1);	
	play_music(NOTE_G);
	sleep(1);
	play_music(NOTE_A);
	sleep(1);
	play_music(NOTE_B);
	sleep(1);
	play_music(NOTE_A);
	sleep(1);
	play_music(NOTE_G);
	sleep(1);
	play_music(NOTE_F);
	sleep(1);
	play_music(NOTE_E);
	sleep(1);	
	play_music(NOTE_D);
	sleep(1);
	play_music(NOTE_C);
	sleep(1);	
	
	city_destruction_sound();
	sleep(2);
	
	explosion_sound();
	sleep(2);
	
	explosion_sound();
	sleep(2);
	
	missile_fired_sound();
	sleep(2);
	
	stop_sound();
	
	return 0;
}
		