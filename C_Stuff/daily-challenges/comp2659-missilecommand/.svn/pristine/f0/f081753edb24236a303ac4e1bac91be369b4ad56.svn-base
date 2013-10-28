#ifndef _SOUND_H
#define _SOUND_H

#define SONG_LENGTH 105
#define ENABLE_A 0x3E
#define ENABLE_A_B 0x3C
#define ENABLE_A_B_C 0x38
#define CHANNEL_VOLUME 0x07
#define ENABLE_REGISTER 7
#define A_VOLUME 8
#define B_VOLUME 9
#define C_VOLUME 10

void missile_fired_sound();
void explosion_sound();
void city_destruction_sound();
void play_note();
struct sound_effect *get_music();
void stop_music();

struct sound_effect
{
  char register_select[50];       /*register to play out of*/
  char tune[50]; /*the tune to play*/
  int length;
};




#endif