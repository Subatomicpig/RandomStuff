/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "model.h"


void create_City(struct city *cityX,unsigned int coordX,unsigned int coordY)
{
	(*cityX).health = 1;
	(*cityX).pX = coordX;
	(*cityX).pY = coordY;
}

/*
	Purpose: update city health when hit by missile
	Input  : a city that is to be destroyed
	Returns: destroyed city
	Assume : nothing
*/
void destroy_City(struct city *cityX)
{
	(*cityX).health = 0;
}

/*
	Purpose: silo to update ammo count of
	Input  : a silo to update
	Returns: silo with updated ammo
	Assume : nothing
*/
void update_Ammo(struct missile_Silo *siloX)
{
	if ((*siloX).ammo > 0)
	{
		(*siloX).ammo--;
	}
}

void create_Silo(struct missile_Silo *siloX)
{
	(*siloX).health = 1;
	(*siloX).ammo = 1000;
	(*siloX).pX = 288;
	(*siloX).pY = TOP_CITY_LEVEL;
}

/*
	Purpose: update silo health when hit by missile
	Input  : a silo that has been damaged
	Returns: a silo that has been damaged
	Assume : nothing
*/
void destroy_Silo(struct missile_Silo *siloX)
{
	(*siloX).health = 0;
}

/*
	Purpose: update missile location when it is being moved
	Input  : an x and y coordinate and a missile to update
	Returns: a missile with those coordinates
	Assume : nothing
*/
void missile_Movement(unsigned int nextX, unsigned int nextY, struct missile *mis)
{
	(*mis).currentX = nextX;
	(*mis).currentY = nextY;
}

/*
	Purpose: create an enemy missile heading towards a coordinate
	Input  : a y and x coordinate for the missile to head towards, and the missile itself
	Returns: a missile with updated finalx and finaly coordinates
	Assume : nothing
*/
void enemy_Missile_Fired(unsigned int finalX, unsigned int finalY, struct missile *mis,unsigned int sX)
{
	(*mis).currentX = sX;
	(*mis).startX = sX;
	(*mis).endX = finalX;
	(*mis).endY = finalY;
	(*mis).destroyed = FALSE;
}

/*
	Purpose: create a friendly missile heading towards a coordinate
	Input  : a y and x coordinate for the missile to head towards, and the missile itself
	Returns: a missile with updated finalx and finaly coordinates
	Assume : nothing
*/
void friendly_Missile_Fired(unsigned int finalX, unsigned int finalY, struct missile *mis,unsigned int sX)
{
	(*mis).currentX = sX;
	(*mis).startX = sX;
	if (finalX < 16)
	{
		(*mis).endX = finalX + 16;
	}
	else if (finalX > 624)
	{
		(*mis).endX = finalX - 16;
	}
	else
	{
		(*mis).endX = finalX;
	}
	if (finalY < 16)
	{
		(*mis).endY = finalY + 16;
	}
	else
	{
		(*mis).endY = finalY;
	}
	(*mis).destroyed = 0;
}

void reset_positions(struct missile *mis)
{
	(*mis).dx1 = 0;
	(*mis).dx2 = 0;
	(*mis).dy1 = 0;
	(*mis).dy2 = 0;
	(*mis).destroyed = TRUE;
	(*mis).numerator = 0;
	(*mis).longest = 0;
	(*mis).shortest = -1;
	(*mis).startX = 0;
	(*mis).currentX = 0;
	(*mis).currentY = 0;
}

void create_Missile(struct missile *mis, int team)
{
	(*mis).startX = 0; 
	(*mis).currentX = 0;
	(*mis).currentY = 0;
	(*mis).endX = 0;
	(*mis).endY = 0; 
	(*mis).velocity = 0; 
	(*mis).team = team; 
	(*mis).destroyed = TRUE; 
	(*mis).dx1 = 0;
	(*mis).dx2 = 0; 
	(*mis).dy1 = 0;
	(*mis).dy2 = 0; 
	(*mis).numerator = 0; 
	(*mis).longest = 0; 
	(*mis).shortest = -1;
}

void create_Explosion(struct explosion *exp)
{
	(*exp).size = 0;
	(*exp).exists = FALSE;
	(*exp).pX = 0;
	(*exp).pY = 0;
	(*exp).hit_city = 0;
}

void make_explosion(struct explosion *exp, unsigned int coordX, unsigned int coordY)
{
	(*exp).exists = TRUE;
	(*exp).pX = coordX;
	(*exp).pY = coordY;
}
