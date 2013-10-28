/*Ryan Wright
 * Comp2631-001
 * Assingment #4
 * Jason heard
 */

import java.util.Random;
import java.util.Timer;

public class mainProg {
	
	static binaryTree tree = new binaryTree();
	
	public static void main(  String []	args)
	{
		Random generator = new Random();
	
		
		int size = 100;
		int SEED = 150;
		int numTimes = 150000;
		double operation = 10;
		
		double probRemove = 0.33;
		double probInsert = 0.44;
		
		generator.setSeed(SEED);

		//creates a tree of size 
		for(int i = 0; i < size; i++)
		{
			tree.insert(i);
		}
		
		testBed(probRemove,probInsert,operation,size,SEED,numTimes,generator);
		
	}
	
	
	
	public static void testBed(double probRemove,double probInsert,double operation,int size,int seed,int NUMTIMES,Random generator)
	{
		double startTimer = 0;
		double endTimer = 0;
		double timeItTook = 0;
		double averageInsertTime = 0;
		int insertCounter = 0;
		double averageDeleteTime = 0;
		int deleteCounter = 0;
		double averageFindTime = 0;
		int findCounter = 0;
		
		//go through a certain number of times
		for(int i = 0; i < NUMTIMES; i++)
		{
			int x = generator.nextInt(size *2);
			operation = generator.nextDouble();
			if(operation < probInsert)
			{
				//start the timer
				startTimer = System.currentTimeMillis();
				tree.insert(x);
				endTimer = System.currentTimeMillis();
				timeItTook = endTimer - startTimer;
				averageInsertTime = averageInsertTime + timeItTook;
				insertCounter++;
			}
			else if(operation < (probInsert + probRemove))
			{
				startTimer = System.currentTimeMillis();
				tree.delete(x);
				endTimer = System.currentTimeMillis();
				timeItTook = endTimer - startTimer;
				averageDeleteTime = averageDeleteTime + timeItTook;
				deleteCounter++;
			}
			else
			{
				startTimer = System.currentTimeMillis();
				tree.find(x);
				endTimer = System.currentTimeMillis();
				timeItTook = endTimer - startTimer;
				averageFindTime = averageFindTime + timeItTook;
				findCounter++;
			}	
		}
		
		averageInsertTime = ((averageInsertTime / insertCounter) * 1000000);
		averageDeleteTime = ((averageDeleteTime / deleteCounter) * 1000000);
		averageFindTime = ((averageFindTime / findCounter) * 1000000);
		
		System.out.println("The average time for insert: " + averageInsertTime);
		System.out.println("The average time for delete: " + averageDeleteTime);
		System.out.println("The average time for find: " + averageFindTime);
	
			
	}

}
