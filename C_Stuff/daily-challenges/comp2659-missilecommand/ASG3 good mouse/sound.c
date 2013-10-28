/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include <osbind.h>
#include "stdio.h"
#include "sound.h"

#define FINE_TONE_A 0
#define ROUGH_TONE_A 1
#define FINE_TONE_B 2
#define ROUGH_TONE_B 3
#define FINE_TONE_C 4
#define ROUGH_TONE_C 5
#define NOISE_REGISTER 6
#define VOLUME_A 8
#define VOLUME_B 9
#define VOLUME_C 10
#define ENABLE_MIXER_REGISTER 7
#define MAX_12_BIT 0xFFF
#define ENVELOPE_SHAPE_REGISTER 13
#define ENVELOPE_ROUGH_REGISTER 12
#define ENVELOPE_FINE_REGISTER 11

volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;

/*
	Purpose: write a value to a register on the sound chip
	Input  : number of the register (0-15) and the value to write (maximum 12 bit)
	Returns: nothing
	Assume : nothing
*/
void write_psg(int reg, char val)
{
	long old_ssp = Super(0);
	if (reg < 16 && val < MAX_12_BIT)
	{
		*PSG_reg_select = reg;
		*PSG_reg_write = val;
	}
	Super(old_ssp);
}

/*
	Purpose: reads the value of the register you choose
	Input  : register to read from
	Returns: value at the register that was read
	Assume : nothing
*/
char read_psg(int reg)
{
	char psg;
	long old_ssp = Super(0);
	if (reg < 16)
	{
		*PSG_reg_select = reg;
		psg = *PSG_reg_write;
	}
	Super(old_ssp);
	return psg;
}

/*
	Purpose: add tuning to a channel onboard the sound chip to play
	Input  : the channel (0,1,2) and the 12-bit tuning for that channel
	Returns: nothing
	Assume : nothing
*/
void set_tone(int channel, int tuning)
{
	char fine_tone  = tuning; 
	char rough_tone = tuning >> 8;
	if (tuning < MAX_12_BIT)
	{
		if (channel == 0)
		{
			write_psg(FINE_TONE_A,fine_tone);
			write_psg(ROUGH_TONE_A,rough_tone);
		}
		else if (channel == 1)
		{
			write_psg(FINE_TONE_B,fine_tone);
			write_psg(ROUGH_TONE_B,rough_tone);
		}
		else if (channel == 2)
		{
			write_psg(FINE_TONE_C,fine_tone);
			write_psg(ROUGH_TONE_C,rough_tone);
		}
	}
}

/*
	Purpose: turn the volume of a specific channel to a value inputted
	Input  : the channel to change the volume of (0,1,2) and the volume to set that channel to
	Returns: nothing
	Assume : nothing
*/
void set_volume(int channel, int volume)
{
	if (volume < 32)
	{
		if (channel == 0)
		{
			write_psg(VOLUME_A,volume);
		}
		else if (channel == 1)
		{
			write_psg(VOLUME_B,volume);
		}
		else if (channel == 2)
		{
			write_psg(VOLUME_C,volume);
		}
	}
}

/*
	Purpose: set the mixer register to enable the channel you chose
	Input  : the channel to enable and whether you want just noise or just tone from that channel
	Returns: nothing
	Assume : nothing
*/
void enable_channel(int channel, int tone_on, int noise_on)
{
	long old_ssp = Super(0);
	*PSG_reg_select = ENABLE_MIXER_REGISTER;
	if (channel == 0)
	{
		if (tone_on == 1)
		{
			*PSG_reg_write = 0x3E;
		}
		if (noise_on == 1)
		{
			*PSG_reg_write = 0x38;
		}
	}
	else if (channel == 1)
	{
		if (tone_on == 1)
		{
			*PSG_reg_write = 0x32;
		}
		if (noise_on == 1)
		{
			*PSG_reg_write = 0x2F;
		}
	}
	else if (channel == 2)
	{
		if (tone_on == 1)
		{
			*PSG_reg_write = 0x34;
		}
		if (noise_on == 1)
		{
			*PSG_reg_write = 0x1F;
		}
	}
	Super(old_ssp);
	
}

/*
	Purpose: stop the music and all sounds currently playing
	Input  : nothing
	Returns: nothing
	Assume : nothing
*/
void stop_sound()
{
	write_psg(VOLUME_A,0x00);
	write_psg(VOLUME_B,0x00);
	write_psg(VOLUME_C,0x00);
	write_psg(NOISE_REGISTER,0x00);
	write_psg(ENABLE_MIXER_REGISTER,0x3F);
}

/*
	Purpose: sets the noise register to a specific tuning
	Input  : the tuning to put into the noise channel
	Returns: nothing
	Assume : nothing
*/
void set_noise(int tuning)
{
	write_psg(NOISE_REGISTER,tuning);
}

/*
	Purpose: sets the envelope length and the shape to make noise
	Input  : the shape of the envelope and the length
	Returns: nothing
	Assume : nothing
*/
void set_envelope(int shape, unsigned int sustain)
{
	char rough_envelope = sustain;
	write_psg(ENVELOPE_SHAPE_REGISTER,shape);
	write_psg(ENVELOPE_ROUGH_REGISTER,rough_envelope);
}
	