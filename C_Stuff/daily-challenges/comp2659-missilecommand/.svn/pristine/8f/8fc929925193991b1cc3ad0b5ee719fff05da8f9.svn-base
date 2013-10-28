#include "effects.h"
#include "sound.h"

void missile_fired_sound()
{
	set_noise(0x7F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x54);
}

void explosion_sound()
{
	set_noise(0x1F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x38);
}

void city_destruction_sound()
{
	set_noise(0x2F);
	write_psg(7,0x0E);
	set_volume(1,0x10);
	set_volume(2,0x10);
	set_envelope(0x00,0x38);
}