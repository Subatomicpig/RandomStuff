/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#include "model.h"
#include <stdio.h>

/*
	Purpose: Test all the model functions
	Input  : nothing
	Returns: test data about model functions
	Assume : nothing
*/
int main()
{
	struct city test_City = {1,120,350};
	struct missile_Silo test_Silo = {10,1,300,350};
	struct missile test_Missile = {100,100,10,0,0};

	/* Working */
	printf("City Health Before Test is: %d\n",test_City.health);
	destroy_City(&test_City);
	printf("City Health is: %d\n",test_City.health);
	
	printf("Silo Ammo Before Test is: %d\n",test_Silo.ammo);
	update_Ammo(&test_Silo);
	printf("Silo Ammo is: %d\n",test_Silo.ammo);

	printf("Silo Before Destroyed is: %d\n",test_Silo.health);
	destroy_Silo(&test_Silo);
	printf("Silo After Destroyed is: %d\n",test_Silo.health);
	
	printf("Testing missile movement position before X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);
	missile_Movement(11,11,&test_Missile);
	printf("Testing missile movement position after X:%d Y:%d\n",test_Missile.currentX,test_Missile.currentY);
	
	return 0;
}