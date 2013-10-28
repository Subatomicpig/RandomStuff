#include <iostream>
#include <curses.h>

using namespace std;

const int MAX_SIZE = 30;

//data structure of the snake 2d array for the body of max size a 2d array for the current head positon of max size
struct snake{

  char bodyPos[MAX_SIZE][MAX_SIZE];
  char currentPos[1][1];


}player;



void printBoard(char board[][MAX_SIZE])
{
  for(int i = 0; i < MAX_SIZE; i++)
    {
      for(int j = 0; j < MAX_SIZE; j++)
	{
	  cout<<board[i][j];
	  if(j == MAX_SIZE - 1)
	    cout<<endl;
	}
    }

}



void createBoard(char board[][MAX_SIZE])
{
  
  //creates a simple board 
  for(int i = 0; i < MAX_SIZE; i++)
    {
      for(int j = 0; j < MAX_SIZE; j++)
	{
	  if(i == 0 || i == MAX_SIZE - 1){
	    board[i][j] = '-';
	  }
	  else if((i > 0 && i < MAX_SIZE) && (j == 0 || j == MAX_SIZE -1)){
	    board[i][j] = '|';
	  }
	  else	  
	    board[i][j] = ' ';
	}
    }
  
}



//this is supposed to be a random challenge thing but I don't know what I am going to make out of this
int main()
{
 
  //simple 2d board array
  char board[MAX_SIZE][MAX_SIZE];
  

 

  createBoard(board);
  printBoard(board);
  clrscr();
  printBoard(board);

  cout<<"Everything is Working properly"<<endl;


  return 0;

};
