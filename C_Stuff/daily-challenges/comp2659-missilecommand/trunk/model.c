/*
	Comp2659 Asg#2 Phase 1

	Donovan Paget
	Ryan Wright

*/

#include "model.h"

void test_Driver();
struct city destroy_City(struct city);
struct missile_Silo update_Ammo(struct missile_Silo);
struct missile_Silo destroy_Silo(struct missile_Silo);
struct missile missile_Fired(unsigned int, unsigned int, struct missile);
struct missile missile_Destroyed(struct missile);
struct missile enemy_Missile_Fired();
struct missile friendly_Missile_Fired(unsigned int, unsigned int);
struct missile missile_Movement(unsigned int nextX, unsigned int nextY, struct missile Shot);
void create_Explosion(unsigned int coordX,unsigned int coordY);
int choose_silo(unsigned int);






/* Start of event handler functions */
/* Checks what key is pressed and returns it */
void keyPress()
{

}


/* Check for mouse movement */
void mouseMovement()
{
 
}
 
 /* Checks for a key click */
void mouseClick()
{
 
}
 
 

/* Destroys city when it is hit */
struct city destroy_City(struct city cityX)
{
	cityX.health = 0;
	create_Explosion(cityX.pX, cityX.pY);
	return cityX;
}

/* Decreases ammo count when missile is fired from a silo */
struct missile_Silo update_Ammo(struct missile_Silo siloX)
{
	if (siloX.ammo > 0){
		siloX.ammo--;
	}
	return siloX;
}

/* Destroys a silo if the silo is hit by a missile */
struct missile_Silo destroy_Silo(struct missile_Silo siloX)
{
	siloX.health = 0;
	create_Explosion(siloX.pX, siloX.pY);
	return siloX;
}


void create_Explosion(unsigned int coordX,unsigned int coordY)
{
	struct explosion newExplosion = {0,1,0,0};
	
	newExplosion.pX = coordX;
	newExplosion.pY = coordY;
	
	while(newExplosion.size < 10)
	{
		newExplosion.size++;
	}
	newExplosion.exists = 0;
}

/* Updates a missiles position, will need to be called from another function which manages 
   the diagonal movements and whether it is a friendly or enemy missile */
struct missile missile_Movement(unsigned int nextX, unsigned int nextY, struct missile Shot)
{
	Shot.currentX = nextX;
	Shot.currentY = nextY;
	return Shot;
}

/* Updates a missile when it reaches the target */
struct missile missile_Destroyed(struct missile Shot)
{
	Shot.destroyed = 1; 
	create_Explosion(Shot.currentX, Shot.currentY);
	return Shot;
}




/* Creates an enemy missile */
struct missile enemy_Missile_Fired()
{
	/* Need some way to randomize where they come out from at the top of the screen
	and their final coordinate */
	struct missile enemyMissile = {0,0,0,0,1,0};
	return enemyMissile;
}

/* Creates a friendly missile, heading towards finalX,finalY */
struct missile friendly_Missile_Fired(unsigned int finalX, unsigned int finalY)
{
	/*Have to figure out which silo, depending on ammo, health, etc. */
	/*Position would depends upon silo chosen*/
	struct missile friendlyMissile = {0,0,0,0,0,0};
	return friendlyMissile;
}

/* Chooses the correct silo for a missile to be fired from depending on where the missile
is heading, 1 = left silo, 2 = middile silo, 3 = right silo */
int choose_silo(unsigned int finalX)
{
	/* Have to find a way to check ammo counts and then spawn the missile from the appropriate
	silo */ 
	int choice = 0;
	if (finalX < 180){
		choice = 1;
	}
	else if (finalX > 180 && finalX < 480){
		choice = 2;
	}
	else{
		choice = 3;
	}
	return choice;
}


	



