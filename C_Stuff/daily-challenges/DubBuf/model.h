/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _MODEL_H
#define _MODEL_H

/*H file for the model*/
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
};

#endif