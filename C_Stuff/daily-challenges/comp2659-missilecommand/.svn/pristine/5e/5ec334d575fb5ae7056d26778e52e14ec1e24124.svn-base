#include <osbind.h>
#include "stdio.h"
#include "sound.h"

#define FINE_TONE_A 0
#define ROUGH_TONE_A 1
#define FINE_TONE_B 2
#define ROUGH_TONE_B 3
#define FINE_TONE_C 4
#define ROUGH_TONE_C 5
#define VOLUME_A 8
#define VOLUME_B 9
#define VOLUME_C 10
#define ENABLE_MIXER_REGISTER 7

volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;

void write_psg(int reg, char val);
char read_psg(int reg);
void missile_fired_sound();
void city_destruction_sound();


void write_psg(int reg, char val)
{
	long old_ssp = Super(0);
	if (reg < 16 && val < 0xFFF)
	{
		*PSG_reg_select = reg;
		*PSG_reg_write = val;
	}
	Super(old_ssp);
}

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

void set_tone(int channel, int tuning)
{
	char fine_tone  = tuning; 
	char rough_tone = tuning >> 8;
	long old_ssp = Super(0);
	if (tuning < 0xFFF)
	{
		if (channel == 0)
		{
			*PSG_reg_select = FINE_TONE_A;
			*PSG_reg_write = fine_tone;
			*PSG_reg_select = ROUGH_TONE_A;
			*PSG_reg_write = rough_tone;
		}
		else if (channel == 1)
		{
			*PSG_reg_select = FINE_TONE_B;
			*PSG_reg_write = fine_tone;
			*PSG_reg_select = ROUGH_TONE_B;
			*PSG_reg_write = rough_tone;
		}
		else if (channel == 2)
		{
			*PSG_reg_select = FINE_TONE_C;
			*PSG_reg_write = fine_tone;
			*PSG_reg_select = ROUGH_TONE_C;
			*PSG_reg_write = rough_tone;
		}
	}
	Super(old_ssp);
}
	
void set_volume(int channel, int volume)
{
	long old_ssp = Super(0);
	if (channel == 0)
	{
		*PSG_reg_select = VOLUME_A;
		*PSG_reg_write = (char)volume;
	}
	else if (channel == 1)
	{
		*PSG_reg_select = VOLUME_B;
		*PSG_reg_write = (char)volume;
	}
	else if (channel == 2)
	{
		*PSG_reg_select = VOLUME_C;
		*PSG_reg_write = (char)volume;
	}
	Super(old_ssp);
}

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

void stop_sound()
{
	long old_ssp = Super(0);
	*PSG_reg_select = VOLUME_A;		
	*PSG_reg_write  = 0;
	*PSG_reg_select = VOLUME_B;		
	*PSG_reg_write  = 0;
	*PSG_reg_select = VOLUME_C;	
	*PSG_reg_write  = 0;
	*PSG_reg_select = ENABLE_MIXER_REGISTER;
	*PSG_reg_write  = 0x3F;
	Super(old_ssp);
}

void missile_fired_sound()
{
	
}

void explosion_sound()
{
	write_psg(6,0x1F);
	write_psg(7,0x0E);
	write_psg(9,0x10);
	write_psg(10,0x10);
	write_psg(12,0x10);
	write_psg(13,0x00);
}

void city_destruction_sound()
{


}
	