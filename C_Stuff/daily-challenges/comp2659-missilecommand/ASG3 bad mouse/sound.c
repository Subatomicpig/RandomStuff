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
	write_psg(VOLUME_A,0x00);
	write_psg(VOLUME_B,0x00);
	write_psg(VOLUME_C,0x00);
	write_psg(ENABLE_MIXER_REGISTER,0x3F);
}

void set_noise(int tuning)
{
	write_psg(NOISE_REGISTER,tuning);
}

void set_envelope(int shape, unsigned int sustain)
{
	char rough_envelope = sustain;
	write_psg(ENVELOPE_SHAPE_REGISTER,shape);
	write_psg(ENVELOPE_FINE_REGISTER,rough_envelope);

}
	