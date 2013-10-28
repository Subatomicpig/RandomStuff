#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

struct Particle{
       
       float x,y;
       float mass;
       
};


void readInput(struct Particle &part,struct Particle &part2)
{
  printf("Enter DATA!!!!\n");
  scanf("%f %f %f",&part.x,&part.y,&part.mass);
  scanf("%f %f %f",&part2.x,&part2.y,&part2.mass);
}

float calcDist(struct Particle part1,struct Particle part2)
{
       float distance,deltaX,deltaY = 0;
       
       deltaX = part1.x - part2.x;
       deltaY = part1.y - part2.y;
       distance = sqrtf(deltaX * deltaX + deltaY * deltaY);
       
       return distance;
}

void printStruct(struct Particle part1,struct Particle part2)
{
     printf("%lf %lf %lf\n",part1.x,part1.y,part1.mass);
     printf("%lf %lf %lf\n",part2.x,part2.y,part2.mass);
}

void calcForce(struct Particle part1, struct Particle part2,float distance)
{
     float force = 0;
     
     force = part1.mass * part2.mass / (distance * distance);
     printf("The force is %lf\n",force);
}

int main()
{
    Particle p1,p2;
    
    readInput(p1,p2);
    printStruct(p1,p2);
    printf("%lf\n",calcDist(p1,p2));
    
    system("pause");
    
 return 0;   
};
