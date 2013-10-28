/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _MODEL_H
#define _MODEL_H

#define TRUE 1
#define FALSE 0
#define GROUND_LEVEL 366
#define TOP_CITY_LEVEL 336
#define FRIENDLY 0
#define ENEMY 1
#define MAX_EXPLOSION_SIZE 5
#define CITY_1_START 64
#define CITY_2_START 144
#define CITY_3_START 224
#define CITY_4_START 384
#define CITY_5_START 464
#define CITY_6_START 544
#define NUM_MISSILES 20
#define NUM_EXPLOSIONS 40


void create_City();
void destroy_City();
void update_Ammo();
void create_Silo();
void destroy_Silo();
void missile_Fired();
void enemy_Missile_Fired();
void friendly_Missile_Fired();
void missile_Movement();
void create_Missile();
void create_Explosion();
void reset_positions();
void reset_explosion();
void make_explosion();



struct missile
{
  int startX; /* start position for line drawing */
  int currentX,currentY; /*position of the missile*/
  int endX, endY; /* end position of the missile */
  unsigned int velocity; /*speed of the missile*/
  int team; /*team of the missile (friendly or enemy, 0 = friendly, anything else = enemy)*/
  int destroyed; /*whether the missile is still alive or not (boolean)*/
  int dx1, dx2, dy1, dy2, numerator, longest, shortest;
};

struct missile_Silo /*struct for the friendly missile silo*/
{

  int ammo;         /*ammo counter*/
  int health;       /*boolean health (0 = dead)*/
  unsigned int pX,pY; /*the position of the silo*/

};

struct city         /*struct for city objects*/
{
  int health;       /*boolean health (0 = dead)*/
  unsigned int pX,pY; /*the position of the citys*/
};

struct explosion
{
  unsigned int size; /*current size of the explosion*/
  int exists; /*whether or not the explosion has been created or not*/
  unsigned int pX,pY; /*position of the explosion*/
  int hit_city; 
};

#endif
