#ifndef  _BITMAP_H
#define _BITMAP_H

#define CITY_LEFT 32
#define CITY_RIGHT 32
#define SILO_LEFT 32
#define SILO_RIGHT 32
#define MISSILE 32
#define EXPLOSION 32
#define CLEAR_SCREEN 32


long int clear_Screen[CLEAR_SCREEN] =
{
	0x00000000
};

long int explosion_bitmap[EXPLOSION] =
{
	0x00000000	
};

long int missile_bitmap[MISSILE] = 
{
	0x60000000,
	0xF0000000,
	0xF0000000,
	0x60000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000

};

long int cityLeft_bitmap[CITY_LEFT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x000F8000,
	0x03EFC000,
	0x07EFC000,
	0x07EFC000,
	0x07FFE000,
	0x07FFE000,
	0x03FFE000,
	0x03FFE000,
	0x03FFE03A,
	0x03FFE03F,
	0xE1FFE3FF,
	0xE1FFE3FF,
	0xE1FFE3FF,
	0xE7FFE3FF,
	0xF7FFE3FF,
	0xF7FFFFFF,
	0xF7FFFFFF,
	0xF7FFFFFF,
	0xF7FFFFFF,
	0xF7FFFFFF
};

long int cityRight_bitmap[CITY_RIGHT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0001F000,
	0x0003F7C0,
	0x0003F7E0,
	0x0003F7E0,
	0x0007FFE0,
	0x0007FFE0,
	0x0007FFC0,
	0x0007FFC0,
	0x1C07FFC7,
	0xFC07FFC7,
	0xFFC7FFC7,
	0xFFC7FFC7,
	0xFFC7FFE7,
	0xFFC7FFEF,
	0xFFFFFFEF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF,
	0xFFFFFFFF
};

long int siloLeft_bitmap[SILO_LEFT] = 
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000400,
	0x00000E00,
	0x00001F00,
	0x00003F80,
	0x00007FC0,
	0x0000FFFF,
	0x0001FFFF,
	0x0003FFFF,
	0x0007FFFF,
	0x000FFFFF,
	0x001FFFFF,
	0x003FFFFF,
	0x007FFFFF,
	0x00FFFFFF,
	0x01FFFFFF,
	0x03FFFFFF,
	0x07FFFFFF,
	0x0FFFFFFF,
	0x1FFFFFFF,
	0x3FFFFFFF,
	0x7FFFFFFF,
	0xFFFFFFFF
};

long int siloRight_bitmap[SILO_RIGHT] =
{
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000,
	0x00200000,
	0x00700000,
	0x00F80000,
	0x01FC0000,
	0x03FE0000,
	0xFFFF0000,
	0xFFFF8000,
	0xFFFFC000,
	0xFFFFE000,
	0xFFFFF000,
	0xFFFFF800,
	0xFFFFFC00,
	0xFFFFFE00,
	0xFFFFFF00,
	0xFFFFFF80,
	0xFFFFFFC0,
	0xFFFFFFE0,
	0xFFFFFFF0,
	0xFFFFFFFA,
	0xFFFFFFFC,
	0xFFFFFFFE,
	0xFFFFFFFF
};

#endif
