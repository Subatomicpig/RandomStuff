#ifndef _SOUND_H
#define _SOUND_H

void stop_music();
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void explosion_sound();

#endif