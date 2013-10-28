#include "sound.h"
#include "music.h"

int main()
{
	int j = 0;
	int i = 0;
	int music[104];
	
	music = get_music();
	
	start_music();
	
	for (i = 0; i < 104; i++){
		play_music(music[i]);
		while (j < 32000)
			j++
	}
	stop_music();
	
	
	return 0;
}
		