/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _SOUND_H
#define _SOUND_H

void write_psg(int reg, char val);
void stop_music();
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
char read_psg(int reg);
void set_envelope(int shape, unsigned int sustain);

#endif