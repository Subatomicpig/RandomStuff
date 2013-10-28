/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/

/*
	Bug Testing for out of screen checks
	End of game function check
*/

#include "model.h"
#include "raster.h"
#include "renderer.h"
#include "td.h"
#include "animator.h"
#include "clear_qk.h"
#include <stdlib.h>
#include <osbind.h>
#include "sound.h"
#include "input.h"

char buffer[32256];

/*
	Purpose: animate and run the game with the clock
	Input  : a char length pointer to the frame buffer and a long length pointer to the frame buffer
	Returns: nothing, but constantly runs the game and its functions
	Assume : nothing
*/
void animate_main(char *base,long *iBase)
{

	int done = 0;
	long *back,*temp;

	int musicCounter = 0;
	int enMisCount = 0;
	int plMisCount = 0;
	int x,y = 0;
	int deltaX,deltaY;
	long clock;
	long newClock;
	int mouseClicked = 0;
	unsigned short mouseX,mouseY;
	int i= 0,j = 0,k = 0,l = 0;
	int randX,randY,randX2;
	int fire = 0;
	int s = 0;
	
	struct missile friendlyMis[NUM_MISSILES];
	struct missile enemyMis[NUM_MISSILES];
	struct explosion explosions[NUM_EXPLOSIONS];
	struct missile_Silo silo;
	struct city city1;
	struct city city2;
	struct city city3;
	struct city city4;
	struct city city5;
	struct city city6;
	struct sound_effect *music = get_music();
	initialize_model(&city1,&city2,&city3,&city4,&city5,&city6,&silo,friendlyMis,enemyMis,explosions);
	
	back = (long *)(buffer + (256 -((long)&buffer)%256));	
	
	
	while(done == 0)
	{
		/*random values for enemy missiles*/
		randX = rand() % BORDER_RIGHT + 16;
		randX2 = rand() % BORDER_RIGHT + 16;
		randY = rand() % GROUND_LEVEL - 200;
		
		/* needs to fire a player missile at the mouse click coordinates */
		if (mouseClicked == 1)
		{ 					/* process on input */
			if (k > NUM_MISSILES-1)
			{
				k = 0;
			}
			if (friendlyMis[k].destroyed == TRUE)
			{
				friendlyMis[k].destroyed = FALSE;
				friendlyMis[k].currentY = GROUND_LEVEL-20;
				friendly_Missile_Fired(mouseX,mouseY, &friendlyMis[k],MISSILE_SILO_FIRING_POINT);
				missile_fired_sound();
				k++;
			}
		}
		
		clock = clockGet();
		
		if (clock != newClock)
		{  					/* process on clock change */
			fire++;
			if(fire == MISSILE_FIRED_TIME)
			{
				enemyMis[j].destroyed = FALSE;
				enemy_Missile_Fired(randX, GROUND_LEVEL, &enemyMis[j],randX2);
				j++;
				if(fire == MISSILE_FIRED_TIME)
				{
					fire = 0;
				}
				if (j == NUM_MISSILES-1)
				{
					j = 0;
				}
			}
			
			
			mouseClicked = get_mouse_pos(&mouseX,&mouseY);
			
			clear_screen(back);
			render_main(back, city1, city2, city3, city4, city5, city6, silo, enemyMis,friendlyMis, explosions,mouseX,mouseY);
			/* T */
			temp = iBase;
			iBase = back;
			back = temp;

			/* wait for sync and then set the screen to the current buffer */
			Setscreen(iBase,iBase,-1);
			
			/* process missiles
			   might need to change to be able to handle more */
			for (i = 0; i < NUM_MISSILES; i++)
			{
				if (enemyMis[i].destroyed == FALSE && explosions[i].exists == FALSE)
				{
					processEnemyMissiles(&enemyMis[i],&explosions[i],clock,ENEMY_SPEED);
				}
				if (friendlyMis[i].destroyed == FALSE && explosions[i+NUM_MISSILES].exists == FALSE)
				{
					processEnemyMissiles(&friendlyMis[i],&explosions[i+NUM_MISSILES],clock,FRIENDLY_SPEED);
				}
			}
			/* process explosions
			   might need to change to be able to handle more */
			for (i = 0; i < NUM_EXPLOSIONS; i++)
			{
				if (explosions[i].exists == TRUE)
				{
					processExplosions(&explosions[i]);
				}
			}
			/* process missile -> explosion collisions */
			for (i = NUM_MISSILES; i < NUM_EXPLOSIONS; i++  && fire == EXPLOSION_PROCESS_TIME)
			{
				if (explosions[i].exists == TRUE)
				{
					processCollisions(friendlyMis,enemyMis,explosions[i]);
				}
			}
			/* process explosion -> city explosions */
			for (i = 0; i < NUM_MISSILES; i++)
			{
				if (explosions[i].hit_city != FALSE)
				{
					city_collision(explosions[i].hit_city,&city1,&city2,&city3,&city4,&city5,&city6);
				}
			}
			if (musicCounter < SONG_LENGTH){
				if (fire % 5 == 0)
				{
					play_note(music[musicCounter],1);
					musicCounter++;
				}
			}
			else
			{
				musicCounter = 0;
			}
		}
		newClock = clockGet();
		
		done = game_over(city1,city2,city3,city4,city5,city6);
		
	}
	stop_music();
}


int game_over(struct city city1,struct city city2,struct city city3,struct city city4,struct city city5,struct city city6)
{
	int gameOver = 0;
	
	if(city1.health == 0 && city2.health == 0 && city3.health == 0 && city4.health == 0 && city5.health == 0 && city6.health == 0)
		gameOver = 1;
		
	return gameOver;
}

/*swaps what buffer we are writing to */
void swap_buffer(long *front, long *back)
{
	long *temp;
	temp = front;
	front = back;
	back = temp;
}

/*
	Purpose: animate the enemy missiles and the lines following them
	Input  : a missile struct, an explosion struct, and the clock
	Returns: nothing, but updates the missiles current position, and updates the explosion if necessary
	Assume : nothing
*/
void processEnemyMissiles(struct missile *mis, struct explosion *exp, long clock,int speed){
	if ((*mis).shortest == -1)
	{
		calculateLine(mis);
	}
	if ((*mis).currentX < (*mis).endX || (*mis).currentX > (*mis).endX)
	{ 
		getPositions(mis,speed);
	}
	if ((*mis).currentX == (*mis).endX || (*mis).currentY == (*mis).endY && (*mis).endX != 0)
	{	
		(*mis).destroyed = TRUE;
		make_explosion(exp,(*mis).endX,(*mis).endY);
		explosion_sound();
		reset_positions(&(*mis));					
	}
}

void processExplosions(struct explosion *exp){
	(*exp).size++;
	if((*exp).pY > CRASHING_LEVEL)
	{
		if ((*exp).pX > 64 && (*exp).pX < 96)
		{
			(*exp).hit_city = 1;
		}
		else if ((*exp).pX > 144 && (*exp).pX < 176)
		{
			(*exp).hit_city = 2;
		}
		else if ((*exp).pX > 224 && (*exp).pX < 256)
		{
			(*exp).hit_city = 3;
		}
		else if ((*exp).pX > 384 && (*exp).pX < 416)
		{
			(*exp).hit_city = 4;
		}
		else if ((*exp).pX > 464 && (*exp).pX < 496)
		{
			(*exp).hit_city = 5;
		}
		else if ((*exp).pX > 544 && (*exp).pX < 576)
		{
			(*exp).hit_city = 6;
		}
	}
	if((*exp).size == MAX_EXPLOSION_SIZE)
	{
		(*exp).size = 0;
		(*exp).exists = FALSE;
	}
	
}

void processCollisions(struct missile friendlyMis[], struct missile enemyMis[], struct explosion exp)
{
	int i,j;
	for (i = 0; i < NUM_MISSILES; i++)
	{
		if (enemyMis[i].currentX < (exp.pX + exp.size * EXPLOSION_MAGNITUDE) 
			&& enemyMis[i].currentX > (exp.pX - exp.size * EXPLOSION_MAGNITUDE) 
			&& enemyMis[i].currentY < (exp.pY + exp.size * EXPLOSION_MAGNITUDE) 
			&& enemyMis[i].currentY > (exp.pY - exp.size * EXPLOSION_MAGNITUDE))
		{
			reset_positions(&enemyMis[i]);
		}
	}
}


void calculateLine(struct missile *mis)
{
	int w = (*mis).endX - (*mis).currentX;
    int h = (*mis).endY - (*mis).currentY;
	if (w < 0)
	{
		(*mis).dx1 = -1;
		(*mis).dx2 = -1;
	}		
	else if (w > 0)
	{
		(*mis).dx1 = 1 ;
		(*mis).dx2 = 1;
	}
    if (h<0)
	{ 
		(*mis).dy1 = -1;
	}		
	else if (h>0)
	{
		(*mis).dy1 = 1;
	}
    (*mis).longest = abs(w);
    (*mis).shortest = abs(h);
    
	if (!((*mis).longest >= (*mis).shortest)) 
	{
        (*mis).longest = abs(h) ;
        (*mis).shortest = abs(w) ;
        if (h < 0)
		{
			(*mis).dy2 = -1;
		}	
		else if (h > 0)
		{
			(*mis).dy2 = 1;
		}
        (*mis).dx2 = 0;            
    }
	(*mis).numerator = (*mis).longest >> 1;
}

void getPositions(struct missile *mis,int speed)
{
		int i;
		for (i = 0;i < speed && (*mis).currentX != (*mis).endX;i++)
		{
			(*mis).numerator += (*mis).shortest;
			if (!((*mis).numerator<(*mis).longest)) 
			{
				(*mis).numerator -= (*mis).longest;
				(*mis).currentX += (*mis).dx1;
				(*mis).currentY += (*mis).dy1;
			} 
			else 
			{
				(*mis).currentX += (*mis).dx2;
				(*mis).currentY += (*mis).dy2;
			}
		}
}

/*
	Purpose: get the current time on the clock
	Input  : nothing
	Returns: current clock time
	Assume : nothing
*/
long clockGet()
{
	long *timer = 0x462;
	long c_time;
	long old_ssp;

	old_ssp = Super(0);
	c_time = *timer;
	Super(old_ssp);

	return c_time;
}

void initialize_model(struct city *city1,struct city *city2,struct city *city3,struct city *city4,struct city *city5,struct city *city6,struct missile_Silo *silo,struct missile enemyMis[],struct missile friendlyMis[],struct explosion explosions[])
{
	int i;
	create_City(city1,CITY_1_START,TOP_CITY_LEVEL);
	create_City(city2,CITY_2_START,TOP_CITY_LEVEL); 
	create_City(city3,CITY_3_START,TOP_CITY_LEVEL); 
	create_City(city4,CITY_4_START,TOP_CITY_LEVEL); 
	create_City(city5,CITY_5_START,TOP_CITY_LEVEL); 
	create_City(city6,CITY_6_START,TOP_CITY_LEVEL); 
	create_Silo(silo);
	for (i = 0; i < NUM_MISSILES; i++)
	{
		create_Missile(&enemyMis[i],FRIENDLY);
	}
	for (i = 0; i < NUM_MISSILES; i++)
	{
		create_Missile(&friendlyMis[i],ENEMY);
	}
	for (i = 0; i < NUM_EXPLOSIONS; i++)
	{
		create_Explosion(&explosions[i]);
	}
}

void city_collision(int cityHit,struct city* city1,struct city* city2,struct city* city3,struct city* city4,struct city* city5,struct city* city6)
{
	if (cityHit == 1)
	{
		destroy_City(city1);
	}
	else if (cityHit == 2)
	{
		destroy_City(city2);
	}
	else if (cityHit == 3)
	{
		destroy_City(city3);
	}
	else if (cityHit == 4)
	{
		destroy_City(city4);
	}
	else if (cityHit == 5)
	{
		destroy_City(city5);
	}
	else if (cityHit == 6)
	{
		destroy_City(city6);
	}
}
	
	
	
	
