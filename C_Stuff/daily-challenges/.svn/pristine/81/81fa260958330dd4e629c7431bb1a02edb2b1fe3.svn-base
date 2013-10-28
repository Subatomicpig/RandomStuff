import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class asg1 {

	//The Size of the array 
	static int ROWS = 30;
	static int COLUMNS = 30;

	//string for the file we want to open
	static String inputFileName;
	
	//scanner to read in the input
	static int numberOfTimes = 0;
	
	//creates the array to hold the board of the game
	static char gameBoardCurrent[][] = new char[ROWS][COLUMNS];
	static boolean validFile;
	
	//scanner to read input
	static Scanner scanner = new Scanner( System.in );

	static char steps;
	static String temp;
	
	/*
	 * Purpose: This is the main function
	 */
	public static void main(String [] args)
	{
		
		System.out.println("Welcome to the Game of Life!" + '\n');
		System.out.print("Enter Seed File name:");
		
		validFile = ioutil.readFromFile(gameBoardCurrent,System.out);
		if(validFile == true)
		{
			System.out.println("The World ( at time " + numberOfTimes +" ):");
			System.out.println();
			ioutil.printBoard(gameBoardCurrent,System.out);
			System.out.print("\n");
			System.out.print("Enter number of time steps to simulate (negative to quit):");
			numberOfTimes = (int) scanner.nextInt();
			System.out.println("Show Intervening steps (y or n):");
			temp = scanner.next();
			steps = Character.toLowerCase(temp.charAt(0));
			
			if(numberOfTimes == -1)
			{
				System.out.println("You quit without doing anything");
				return;
			}
			
			for(int i = 1; i <= numberOfTimes; i++)
			{
				if(steps == 'y')
				{
					System.out.println("The world ( at time " + i +" ):");
					ioutil.printBoard(gameBoardCurrent,System.out);
				}
				ioutil.solveBoard(gameBoardCurrent);
			}
			
			System.out.println("The world ( at time " + numberOfTimes +" ):");
			ioutil.printBoard(gameBoardCurrent,System.out);
		}
		else if(validFile == false){
			return;
		}
	
	}

}
