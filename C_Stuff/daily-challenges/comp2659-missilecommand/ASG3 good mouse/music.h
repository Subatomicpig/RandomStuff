/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _MUSIC_H
#define _MUSIC_H

#define NOTE_F 0x281
#define NOTE_C 0x357
#define NOTE_D 0x2FA
#define NOTE_E 0x2A7
#define NOTE_G 0x23B
#define NOTE_A 0x1FC
#define NOTE_B 0x1C5
#define SONG_LENGTH 104
int *get_music();
void start_music();
void play_music(int note);

#endif