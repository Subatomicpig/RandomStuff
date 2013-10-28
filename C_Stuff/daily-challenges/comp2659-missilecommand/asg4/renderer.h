/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _RENDERER_H
#define _RENDERER_H

#define CITY_HEIGHT 32
#define SILO_HEIGHT 32
#define MISSILE_HEIGHT 4
#define MOUSE_HEIGHT 6
#define GROUND_HEIGHT 32
#define EXPLOSION_HEIGHT 32
#define BITMAP_WIDTH 32
#define HALF_BITMAP_WIDTH 16
#define BITMAPS_ACROSS 19

void render_Mouse(long int *base,int mouseX, int mouseY);
void render_ground(long int *iBase);
void render_silo();
void render_main();
void render_explosion();
void render_city();
void render_missile();


#endif