/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/
#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#define ENEMY_SPEED 4
#define FRIENDLY_SPEED 10
#define MISSILE_SILO_FIRING_POINT 320
#define MISSILE_FIRED_TIME 50
#define EXPLOSION_PROCESS_TIME 25
#define CRASHING_LEVEL 340
#define EXPLOSION_MAGNITUDE 4

void animate_main();
long clockGet();
void processEnemyMissiles();
void calculateLine();
void getPositions();
void initialize_model();
void processExplosions();
void swap_buffer();
void processCollisions();
void city_collision();
int game_over(struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6);



#endif