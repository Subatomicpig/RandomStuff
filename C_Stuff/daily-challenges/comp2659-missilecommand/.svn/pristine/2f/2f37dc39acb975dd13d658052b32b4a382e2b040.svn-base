/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
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
#include "effects.h"
#include "music.h"
#include "input.h"
#include "set_vi~1.h"
#include "vbl_isr.h"

char buffer[32256];
int mouseClicked = FALSE;
struct world gameWorld;
unsigned short mouseX;
unsigned short mouseY;
long *back;
long *longBase;
int render = 0;
int *a_music;
/*
	Purpose: animate and run the game with the clock
	Input  : a char length pointer to the frame buffer and a long length pointer to the frame buffer
	Returns: nothing, but constantly runs the game and its functions
	Assume : nothing
*/
void animate_main(char *base,long *iBase)
{
	Vector original_vector;
	long *temp;

	int musicCounter = 0;
	int enMisCount = 0;
	int plMisCount = 0;
	int x,y = 0;
	long clock;
	long newClock;
	int i= 0,j = 0,l = 0;
	int randX,randY,randX2;
	int fire = 0;
	int s = 0;
	int done = 0;
	a_music = get_music();
	stop_sound();
	start_music();
	initialize_model();
	
	back = (long *)(buffer + (256 -((long)&buffer)%256));	
	longBase = iBase;
	
	original_vector = install_vector(28,VBL_ISR);
	
	while(done == 0)
	{	
		/* needs to fire a player missile at the mouse click coordinates */
		if (mouseClicked == TRUE)
		{ 					/* process on input */
			process_async_events();
		}	
		/* process on clock change */
		mouseClicked = get_mouse_pos(&mouseX,&mouseY);
		process_sync_events();
		done = game_over();
	}
	install_vector(28,original_vector);
	stop_sound();
}


void do_VBL_ISR()
{
	render = render + 1;
}

/*
	Purpose: Check if all the citys have been destroyed if so the game exits
	Input  : all the citys in the game
	Returns: integer 0 if false 1 if game over
	Assume : nothing
*/
int game_over()
{
	int gameOver = 0;
	
	if(gameWorld.cities[0].health == 0 && gameWorld.cities[1].health == 0 && gameWorld.cities[2].health == 0 && gameWorld.cities[3].health == 0 && gameWorld.cities[4].health == 0 && gameWorld.cities[5].health == 0)
		gameOver = 1;
		
	return gameOver;
}

/*
	Purpose: swap the pointers for double buffering
	Input  : two pointers for buffers
	Returns: nothing
	Assume : nothing
*/
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
void processEnemyMissiles(struct missile *mis, struct explosion *exp, int speed){
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

/*
	Purpose: processes the animation and sound effects for the explosions
	Input  : pointer to array of explosions
	Returns: nothing
	Assume : nothing
*/
void processExplosions(struct explosion *exp){
	(*exp).size++;
	if((*exp).pY > CRASHING_LEVEL)
	{
		if ((*exp).pX > 64 && (*exp).pX < 96)
		{
			(*exp).hit_city = 1;
			city_destruction_sound();
		}
		else if ((*exp).pX > 144 && (*exp).pX < 176)
		{
			(*exp).hit_city = 2;
			city_destruction_sound();
		}
		else if ((*exp).pX > 224 && (*exp).pX < 256)
		{
			(*exp).hit_city = 3;
			city_destruction_sound();
		}
		else if ((*exp).pX > 384 && (*exp).pX < 416)
		{
			(*exp).hit_city = 4;
			city_destruction_sound();
		}
		else if ((*exp).pX > 464 && (*exp).pX < 496)
		{
			(*exp).hit_city = 5;
			city_destruction_sound();
		}
		else if ((*exp).pX > 544 && (*exp).pX < 576)
		{
			(*exp).hit_city = 6;
			city_destruction_sound();
		}
	}
	if((*exp).size == MAX_EXPLOSION_SIZE)
	{
		(*exp).size = 0;
		(*exp).exists = FALSE;
	}
	
}

/*
	Purpose: check collision with explosions
	Input  : friendly missile array enemyMis array and explosions
	Returns: nothing
	Assume : nothing
*/
void processCollisions(struct explosion exp)
{
	int i,j;
	for (i = 0; i < NUM_MISSILES; i++)
	{
		if (gameWorld.enemyMissiles[i].destroyed == FALSE)
		{
			if (gameWorld.enemyMissiles[i].currentX < (exp.pX + exp.size * EXPLOSION_MAGNITUDE) 
				&& gameWorld.enemyMissiles[i].currentX > (exp.pX - exp.size * EXPLOSION_MAGNITUDE) 
				&& gameWorld.enemyMissiles[i].currentY < (exp.pY + exp.size * EXPLOSION_MAGNITUDE) 
				&& gameWorld.enemyMissiles[i].currentY > (exp.pY - exp.size * EXPLOSION_MAGNITUDE))
			{
				reset_positions(&gameWorld.enemyMissiles[i]);
			}
		}
	}
}


/*
	Purpose: calculate the missile trajectory and update it accordingly
	Input  : missile
	Returns: nothing
	Assume : nothing
*/
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

/*
	Purpose: gets the current position and updates the missile position
	Input  : speed of the missile and the missile moving
	Returns: nothing
	Assume : nothing
*/
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


/*
	Purpose: initalizes all the starting positions of everything in the model
	Input  : all the structures in the game
	Returns: nothing
	Assume : nothing
*/
void initialize_model()
{
	int i;
	create_City(&gameWorld.cities[0],CITY_1_START,TOP_CITY_LEVEL);
	create_City(&gameWorld.cities[1],CITY_2_START,TOP_CITY_LEVEL); 
	create_City(&gameWorld.cities[2],CITY_3_START,TOP_CITY_LEVEL); 
	create_City(&gameWorld.cities[3],CITY_4_START,TOP_CITY_LEVEL); 
	create_City(&gameWorld.cities[4],CITY_5_START,TOP_CITY_LEVEL); 
	create_City(&gameWorld.cities[5],CITY_6_START,TOP_CITY_LEVEL); 
	create_Silo(&gameWorld.mainSilo);
	for (i = 0; i < NUM_MISSILES; i++)
	{
		create_Missile(&gameWorld.enemyMissiles[i],FRIENDLY);
	}
	for (i = 0; i < NUM_MISSILES; i++)
	{
		create_Missile(&gameWorld.friendlyMissiles[i],ENEMY);
	}
	for (i = 0; i < NUM_EXPLOSIONS; i++)
	{
		create_Explosion(&gameWorld.explosions[i]);
	}
}


/*
	Purpose: updates the citys if a missile has collided with them
	Input  : city structures in the game
	Returns: nothing
	Assume : nothing
*/
void city_collision(int cityHit)
{
	if (cityHit == 1)
	{
		destroy_City(&gameWorld.cities[0]);
	}
	else if (cityHit == 2)
	{
		destroy_City(&gameWorld.cities[1]);
	}
	else if (cityHit == 3)
	{
		destroy_City(&gameWorld.cities[2]);
	}
	else if (cityHit == 4)
	{
		destroy_City(&gameWorld.cities[3]);
	}
	else if (cityHit == 5)
	{
		destroy_City(&gameWorld.cities[4]);
	}
	else if (cityHit == 6)
	{
		destroy_City(&gameWorld.cities[5]);
	}
}

void process_async_events()
{
	static int k = 0;
	if (k > NUM_MISSILES-1)
	{
		k = 0;
	}
	if (gameWorld.friendlyMissiles[k].destroyed == TRUE)
	{
		gameWorld.friendlyMissiles[k].destroyed = FALSE;
		gameWorld.friendlyMissiles[k].currentY = GROUND_LEVEL-20;
		friendly_Missile_Fired(mouseX,mouseY, &gameWorld.friendlyMissiles[k],MISSILE_SILO_FIRING_POINT);
		missile_fired_sound(); 
		k++;
	}
}
	
void process_sync_events()
{
	int randX,randY,randX2;
	static int fire=0;
	static int j=0;
	static int i = 0;
	long *temp;
	static int musicCounter = 0;
	
	/*random values for enemy missiles*/
	randX = rand() % BORDER_RIGHT + 16;
	randX2 = rand() % BORDER_RIGHT + 16;
	randY = rand() % GROUND_LEVEL - 200;
	
	
	fire++;
	if(fire == MISSILE_FIRED_TIME)
	{
		gameWorld.enemyMissiles[j].destroyed = FALSE;
		enemy_Missile_Fired(randX, GROUND_LEVEL, &gameWorld.enemyMissiles[j],randX2);
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
	
			
	if (render == 1)
	{
		render_main(back,gameWorld,mouseX,mouseY);
		/* T */
		temp = longBase;
		longBase = back;
		back = temp;

		/* wait for sync and then set the screen to the current buffer */
		set_video_base_wrap((char *)longBase);
		render = 0;
	}
	/* process missiles
	   might need to change to be able to handle more */
	for (i = 0; i < NUM_MISSILES; i++)
	{
		if (gameWorld.enemyMissiles[i].destroyed == FALSE && gameWorld.explosions[i].exists == FALSE)
		{
			processEnemyMissiles(&gameWorld.enemyMissiles[i],&gameWorld.explosions[i],ENEMY_SPEED);
		}
		if (gameWorld.friendlyMissiles[i].destroyed == FALSE && gameWorld.explosions[i+NUM_MISSILES].exists == FALSE)
		{
			processEnemyMissiles(&gameWorld.friendlyMissiles[i],&gameWorld.explosions[i+NUM_MISSILES],FRIENDLY_SPEED);
		}
	}
	/* process explosions
	   might need to change to be able to handle more */
	for (i = 0; i < NUM_EXPLOSIONS; i++)
	{
		if (gameWorld.explosions[i].exists == TRUE)
		{
			processExplosions(&gameWorld.explosions[i]);
		}
	}
	/* process missile -> explosion collisions */
	for (i = NUM_MISSILES; i < NUM_EXPLOSIONS; i++)
	{
		if (gameWorld.explosions[i].exists == TRUE)
		{
			processCollisions(gameWorld.explosions[i]);
		}
	}
	/* process explosion -> city explosions */
	for (i = 0; i < NUM_MISSILES; i++)
	{
		if (gameWorld.explosions[i].hit_city != FALSE)
		{
			city_collision(gameWorld.explosions[i].hit_city);
		}
	}
	if (musicCounter < SONG_LENGTH){
		if (fire % 4 == 0)
		{
			play_music(a_music[musicCounter]);
			musicCounter++;
		}
	}
	else
	{
		musicCounter = 0;
	}
}
	
	
	
