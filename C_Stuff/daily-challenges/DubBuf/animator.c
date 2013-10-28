/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/

/* 	Process explosions seperately from missiles with a counter for the clock speed
	Process collisions (check explosion coords, exp size * 5 to get the area
		of the collision
	Bug Testing for out of screen checks
	End of game function check
*/

#include "model.h"
#include "raster.h"
#include "td.h"



long clockGet();
void processEnemyMissiles(struct missile *mis, struct explosion *exp, long clock,int speed);
void calculateLine(struct missile *mis);
void getPositions(struct missile *mis,int speed);
void initialize_model(struct city*,struct city*,struct city*,struct city*,struct city*,struct city*,struct missile_Silo*,struct missile enemyMis[],struct missile friendlyMis[],struct explosion explosions[]);
void processExplosions(struct explosion *exp);
void swap_buffer(long *front, long *back);


char buffer[32256];

/*
	Purpose: animate and run the game with the clock
	Input  : a char length pointer to the frame buffer and a long length pointer to the frame buffer
	Returns: nothing, but constantly runs the game and its functions
	Assume : nothing
*/
void animate_main(char *base,long *iBase){
	
	
	long *back,*temp;
	const int enemySpeed = 3;
	const int friendlySpeed = 10; 

	int enMisCount = 0;
	int plMisCount = 0;
	int x,y = 0;
	long clock;
	long newClock;
	int mouseClicked = 0;
	unsigned short mouseX,mouseY;
	int i= 0,j = 0,k = 0,l = 0;
	int randX,randY,randX2;
	int fire = 0;
	int s = 0;
	
	struct missile friendlyMis[20];
	struct missile enemyMis[20];
	struct explosion explosions[40];
	struct missile_Silo silo;
	struct city city1;
	struct city city2;
	struct city city3;
	struct city city4;
	struct city city5;
	struct city city6;

	initialize_model(&city1,&city2,&city3,&city4,&city5,&city6,&silo,friendlyMis,enemyMis,explosions);
	
	while(!Cconis()){
		
		
		
		back = buffer + (256 -((long)&buffer)%256);	
		
		/*random values for enemy missiles*/
		randX = rand() % 639 + 16;
		randX2 = rand() % 639 + 16;
		randY = rand() % 366 - 200;
		
		/* needs to fire a player missile at the mouse click coordinates */
		if (mouseClicked == 1){ /* process on input */
			if (k > 18){
				k = 0;
			}
			if (friendlyMis[k].destroyed == 1){
				friendlyMis[k].destroyed = 0;
				friendlyMis[k].currentY = 366;
				friendly_Missile_Fired(mouseX,mouseY, &friendlyMis[k],320);
				k++;
			}
		}
		
		clock = clockGet();
		
		
		if (clock != newClock){ /* process on clock change */
			
			fire++;
		

			if(fire == 50)
			{
				enemyMis[j].destroyed = 0;
				enemy_Missile_Fired(randX, 366, &enemyMis[j],randX2);
				j++;
				if(fire == 50)
					fire = 0;
				if (j == 19)
					j = 0;
			}
			
		
			
			
			mouseClicked = get_mouse_pos(&mouseX,&mouseY);
			
			temp = back;
			back = iBase;
			iBase = temp;
			clear_screen(back);
			render_main(back, city1, city2, city3, city4, city5, city6, silo, enemyMis,friendlyMis, explosions,mouseX,mouseY);
		
			
			temp = back;
			back = iBase;
			iBase = temp;
			Setscreen(iBase,iBase,-1);
			
			
		
		
		
			/* process the enemy missiles being fired */
			/* needs to be able to handle more missiles */


			for (i = 0; i < 20; i++){
				if (enemyMis[i].destroyed == 0 && explosions[i].exists == 0){
					processEnemyMissiles(&enemyMis[i],&explosions[i],clock,enemySpeed);
				}
				
				if (friendlyMis[i].destroyed == 0 && explosions[i+20].exists == 0){
					processEnemyMissiles(&friendlyMis[i],&explosions[i+20],clock,friendlySpeed);
				}
			}
			for (i = 0; i < 40; i++){
				if (explosions[i].exists == 1){
					processExplosions(&explosions[i]);
				}
			}
			

		}
		newClock = clockGet();
	}
	
	

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
	if ((*mis).shortest == -1){
		calculateLine(mis);
	}
	if ((*mis).currentX < (*mis).endX || (*mis).currentX > (*mis).endX){ 
		getPositions(mis,speed);
	}
	if ((*mis).currentX == (*mis).endX || (*mis).currentY == (*mis).endY && (*mis).endX != 0)
	{	
		(*mis).destroyed = 1;
		make_explosion(exp,(*mis).endX,(*mis).endY);
		reset_positions(&(*mis));					
	}
}

void processExplosions(struct explosion *exp){
		(*exp).size++;
		if((*exp).size == 5)
		{
			(*exp).size = 0;
			(*exp).exists = 0;
		}	
}

void calculateLine(struct missile *mis)
{
	int w = (*mis).endX - (*mis).currentX;
    int h = (*mis).endY - (*mis).currentY;
	if (w < 0){
		(*mis).dx1 = -1;
		(*mis).dx2 = -1;
	}		
	else if (w > 0){
		(*mis).dx1 = 1 ;
		(*mis).dx2 = 1;
	}
    if (h<0){ 
		(*mis).dy1 = -1;
	}		
	else if (h>0){
		(*mis).dy1 = 1;
	}
    (*mis).longest = abs(w);
    (*mis).shortest = abs(h);
    
	if (!((*mis).longest >= (*mis).shortest)) {
        (*mis).longest = abs(h) ;
        (*mis).shortest = abs(w) ;
        if (h < 0){
			(*mis).dy2 = -1;
		}	
		else if (h > 0){
			(*mis).dy2 = 1;
		}
        (*mis).dx2 = 0;            
    }
	(*mis).numerator = (*mis).longest >> 1;
}

void getPositions(struct missile *mis,int speed){
		int i;
		for (i = 0;i < speed && (*mis).currentX != (*mis).endX;i++){
			(*mis).numerator += (*mis).shortest;
			if (!((*mis).numerator<(*mis).longest)) {
				(*mis).numerator -= (*mis).longest;
				(*mis).currentX += (*mis).dx1;
				(*mis).currentY += (*mis).dy1;
			} else {
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
	create_City(city1,64,336);
	create_City(city2,144,336); 
	create_City(city3,224,336); 
	create_City(city4,384,336); 
	create_City(city5,464,336); 
	create_City(city6,544,336); 
	create_Silo(silo);
	for (i = 0; i < 20; i++){
		create_Missile(&enemyMis[i],1);
	}
	for (i = 0; i < 20; i++){
		create_Missile(&friendlyMis[i],0);
	}
	for (i = 0; i < 40; i++){
		create_Explosion(&explosions[i]);
	}
}
	
	