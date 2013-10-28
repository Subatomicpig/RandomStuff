#include "sound.h"
#include "music.h"
#include <stdio.h>

int main()
{
	int j = 0;
	int i = 0;
	int *music;
	music = get_music();
	
	start_music();
	for (i = 0; i < 104; i++)
	{
		play_music(music[i]);
		while (j < 32000)
			j++;
		printf("%d \n",music[i]);
	}
	stop_sound();
	
	start_music();
	play_music(NOTE_C);
	sleep(5);
	
	play_music(NOTE_D);
	sleep(5);

	stop_sound();
	
	return 0;
}
		