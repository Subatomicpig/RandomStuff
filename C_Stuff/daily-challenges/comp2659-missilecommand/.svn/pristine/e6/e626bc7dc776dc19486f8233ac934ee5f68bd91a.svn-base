#include <osbind.h>
#include "sound.h"
#include "stdio.h"

volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;
void play_sound_effect(struct sound_effect effect);
void play_note(struct sound_effect note, int notes);

#define NOTE_F_STRUCT {{0,1},{0x81,0x02},2}
#define NOTE_C_STRUCT {{0,1},{0x57,0x03},2}
#define NOTE_D_STRUCT {{0,1},{0xFA,0x02},2}
#define NOTE_E_STRUCT {{0,1},{0xA7,0x02},2}
#define NOTE_G_STRUCT {{0,1},{0x3B,0x02},2}
#define NOTE_A_STRUCT {{0,1},{0xFC,0x01},2}
#define NOTE_B_STRUCT {{0,1},{0xC5,0x01},2}

struct sound_effect music[] =
{	
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_F_STRUCT,
	NOTE_F_STRUCT,
	NOTE_E_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_A_STRUCT,
	NOTE_B_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	
	NOTE_A_STRUCT,
	NOTE_G_STRUCT,
	NOTE_F_STRUCT,
	NOTE_E_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_E_STRUCT,
	NOTE_F_STRUCT,
	NOTE_E_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_A_STRUCT,
	NOTE_B_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	NOTE_C_STRUCT,
	NOTE_B_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	NOTE_C_STRUCT,
	NOTE_A_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,
	NOTE_C_STRUCT,
	NOTE_F_STRUCT,

	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	NOTE_C_STRUCT,
	NOTE_E_STRUCT,
	
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT,
	NOTE_C_STRUCT,
	NOTE_D_STRUCT
};
	
struct sound_effect *get_music()
{
	return music;
}

void missile_fired_sound()
{
	struct sound_effect gunshot = 
	{
	{6,7,8,9,10,12,13},
	{0x10,0x07,0x10,0x10,0x10,0x53,0x00},
	7
	};
	play_sound_effect(gunshot);
}

void explosion_sound()
{
	struct sound_effect explosion_sound =
	{
	{6,7,8,9,10,12,13},
	{0x1F,0x07,0x10,0x10,0x10,0x38,0x00},
	7
	};
	play_sound_effect(explosion_sound);
}

void city_destruction_sound()
{
	struct sound_effect city_destroyed_sound =
	{
	{6,7,8,9,10,12,13},
	{0xAA,0x07,0x10,0x10,0x10,0x38,0x00},
	7
	};
	play_sound_effect(city_destroyed_sound);
}

void play_sound_effect(struct sound_effect effect)
{
	int i = 0;
	long old_ssp = Super(0);

	while (i < effect.length)
	{
		*PSG_reg_select = effect.register_select[i];
		*PSG_reg_write = effect.tune[i];
		i++;
	}
	Super(old_ssp);
}

void play_note(struct sound_effect note, int number_notes)
{
	int i = 0;
	int notes;
	
	long old_ssp = Super(0);
	if (note.length != -1)
	{
		*PSG_reg_select = ENABLE_REGISTER;	
		if (number_notes == 1)	
		{
			*PSG_reg_write  = ENABLE_A;		/* enable only channel a */
			*PSG_reg_select = 8;		/* set channel A volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			notes = 1;
		}
		else if (number_notes == 2)
		{
			*PSG_reg_select = ENABLE_REGISTER;	 	/* enable channel a + b */
			*PSG_reg_write  = ENABLE_A_B;
			*PSG_reg_select = A_VOLUME;		/* set channel A volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			*PSG_reg_select = B_VOLUME;		/* set channel B volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			notes = 2;
		}
		else if (number_notes == 3)
		{
			*PSG_reg_select = ENABLE_REGISTER;		/* enable all 3 channels */
			*PSG_reg_write  = ENABLE_A_B_C;
			*PSG_reg_select = A_VOLUME;		/* set channel A volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			*PSG_reg_select = B_VOLUME;		/* set channel B volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			*PSG_reg_select = C_VOLUME;		/* set channel C volume = 8 */
			*PSG_reg_write  = CHANNEL_VOLUME;
			notes = 3;
		}
	}
	while (i < note.length)
	{
		*PSG_reg_select = note.register_select[i];
		*PSG_reg_write = note.tune[i];
		i++;
	}
	Super(old_ssp);
}

void stop_music()
{
	long old_ssp = Super(0);
	*PSG_reg_select = A_VOLUME;		/* set channel A volume = 8 */
	*PSG_reg_write  = 0;
	*PSG_reg_select = B_VOLUME;		/* set channel B volume = 8 */
	*PSG_reg_write  = 0;
	*PSG_reg_select = C_VOLUME;		/* set channel C volume = 8 */
	*PSG_reg_write  = 0;
	
	Super(old_ssp);
}

