import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;


//This class will handle all of the array functions
public class ioutil {
	
	private static int ROWS = 30;
	private static int COLUMNS = 30;
	

	/*
	 * Purpose:To open a file and read the file into an array
	 * Method:Opens the file and as long as the endfile is not found takes a string from the file then itterates through the string and adds each character
	 * 		  Into our array 
	 * I/O:Array we are working with and outputs error messages if file not found or file not large enough
	 */
public static boolean readFromFile(char array[][], PrintStream print)
	{
		//Bool value to check if the file is correct size
		boolean valid = false;
		boolean validFile = false;
		
		
		//int value to check if the number of rows is correct
		int numberOfRows = 0;
		
		//The input scanner to read in our file 
		Scanner scanner = new Scanner(System.in);
		
		//create the file
		Scanner readFile = null;		
		
		//Scanner to read through the file
		String filename;
		
		//String for the next line of the file
		String s = null;
		

		//reads the next line from the input			
		filename = output.readString(scanner);
		
		try {
			readFile = new Scanner(new FileInputStream(filename));
			validFile = true;
		} catch (FileNotFoundException e) {
			//print.println("File Not Found");
			output.print(print,"File Not Found");
			validFile = false;
		}
		
		
			
			if(validFile == true){
				s = readFile.next();
			
			
			
				if(s.length() != 30)
				{
					output.print(print,"File Is Not Large Enough Exiting Program");
					valid = false;
					return valid;
				}
				else
				{
				
					for(int i = 0; i < ROWS; i++)
						{
							for(int j = 0; j < COLUMNS; j++)
							{
								//check to see if we are still in the length of the string
								if(j <= s.length() - 1)
								{
									array[i][j] = s.charAt(j);
								}
								else if(s.length() != 30)
								{
									array[i][j] = '.';
								}
							
							}
							if(readFile.hasNext() == true)
							{
								s = readFile.next();
							}
								numberOfRows++;
						}
				}
			}
			
			if(numberOfRows == ROWS)
			{
				valid = true;
				return valid;
			}
			else
			{
				valid = false;
				return valid;
			}
}
		
	
//Returns how many neighbors are around the cell entered
/*
 * Purpose:To check all the neighbors around an element in the array 
 * Method:Takes the element we want to check and add 1 to a counter for each neighbor found
 * I/O:Array we are trying to solve and the coordinates of the element
 */
public static int checkNeighbors(char currentArray[][], int x, int y)
{
	int neighbors = 0;
	
	//check right cells are alive 
	if((y + 1) < 30){
		if(currentArray[x][y + 1] == 'X'){
		neighbors++;
		}
	}
	
	//check left cells are alive
	if((y - 1) >= 0){
		if(currentArray[x][y - 1] == 'X' ){
		neighbors++;
		}
	}
	
	if((x + 1) < 30){
		if(currentArray[x + 1][y] == 'X'){
		neighbors++;
		}
	}

	if((x - 1) >= 0){
		if(currentArray[x - 1][y] == 'X'){
			neighbors++;
		}
	}
	
	//down right
	if((x + 1) < 30 && (y + 1) < 30){
		if(currentArray[x + 1][y + 1] == 'X'){
		neighbors++;
		}
	}
	
	//check down left cells are alive
	if((x + 1) < 30 && (y -1) >= 0){
		if(currentArray[x + 1][y - 1] == 'X'){
		neighbors++;
		}
	}	
	//check up right cells are alive
	if((x - 1) >= 0 && (y + 1) < 30){
		if(currentArray[x - 1][y + 1] == 'X'){
		neighbors++;
		}
	}
		
	//check up left cells are alive
	if((x - 1) >= 0 && (y - 1) >= 0){ 
		if(currentArray[x - 1][y - 1] == 'X'){
		neighbors++;
		}
	}
	
	return neighbors;

}
	

/*
 * Purpose:To itterate through the array and solve it 
 * Method: Itterates through the array and checks each element and then determines if the element should be alive or dead
 * 			Uses a temporary array to hold the solved array
 * I/O:The array we are working with 
 */
public static void solveBoard(char currentArray[][])
{
		char gameBoardNext[][] = new char[ROWS][COLUMNS];
		int numberOfNeighbors = 0;
		
			for(int k = 0; k < ROWS; k++)
			{
				for(int j = 0; j < COLUMNS; j++)
				{
					//get the number of neighbors for the current cell
					numberOfNeighbors = checkNeighbors(currentArray,k,j);
				
					//if the cell is alive and has less than 2 neighbors it dies
						if(currentArray[k][j] == 'X' && numberOfNeighbors < 2){
							//if less than 2 the cell dies
							gameBoardNext[k][j] = '.';
						}
						//if the cell is alive and has more than 3 neighbors it dies overcrowding
						else if(currentArray[k][j] == 'X' && numberOfNeighbors > 3)
						{
							//dies horrible death
							gameBoardNext[k][j] = '.';
						}
						//if the cell is dead and has exactly 3 neighbors it lives
						else if(currentArray[k][j] =='.' && numberOfNeighbors == 3)
						{
							//REBIRTH!!
							gameBoardNext[k][j] = 'X'; 
						}
						//if the cell is alive and has 2 or 3 neighbors it lives
						else if((currentArray[k][j] == 'X') && (numberOfNeighbors == 3 || numberOfNeighbors == 2) )
						{
							gameBoardNext[k][j] = 'X';
						}
						else
							//otherwise keep the cells the same
							gameBoardNext[k][j] ='.';
					}
			}
			
			//updates the board
			for(int i = 0; i < ROWS; i++)
			{
				for(int j = 0; j < COLUMNS; j++)
				{
					currentArray[i][j] = gameBoardNext[i][j];
				}
			}

			
}
	
	
	
	
//Reads Through The Array and Prints out the contents
/*
 * Purpose:To print the array to the console
 * Method:For loops to run through the array and print each element
 * I/O:Takes the array and Printstream
 */
public static void printBoard(char array[][],PrintStream print )
	{
		//This function will display the board to the user
		for(int i = 0; i < ROWS; i++)
		{
			for(int j = 0; j < COLUMNS; j++)
			{
				//prints out all the characters for that line
				output.print(print," " + array[i][j]);
			}
			print.print('\n');
		}		
		
	}
}
