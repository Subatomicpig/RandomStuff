import java.awt.Color;
import java.util.Random;

import edu.umd.cs.piccolo.activities.PActivity;
import edu.umd.cs.piccolo.nodes.PText;

public class SortingAnimation extends AnimationScreen {
	private static final long serialVersionUID = 1L;
		
	//creates all the boxes and nodes we need
	private static TextBoxNode [] boxes = new TextBoxNode[10];
	private static TextBoxNode pivotNode;
	private static TextBoxNode lowNode;
	private static TextBoxNode highNode;
	
	
	//offsets to align all the boxes correctly
	private static int pX[] = {0,30,60,90,120,150,180,210,240,270};
	
	//array to sort
	private static int array[] = new int[10];
	
	
	private static Random generator = new Random();
	
	private static int low = 10;
	private static int high = 100;
	private static int size = 0;
	
	
	@Override
	public void addInitialNodes () 
	{
		
		
		String s;
		int offset = 0;//offset position for where the boxes go
		
		// add background box
		// addColouredBox (0, 0, 400, 400, Color.LIGHT_GRAY);

		// add header text
		PText header = addText (0, 0, "Quick Sort Algorithm");
		header.setTextPaint (Color.DARK_GRAY);
		
		PText beforeSort = addText(0,35, "Before the Sort the array looks like");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText Pivot = addText(0,90, "During The Sorting");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText afterSort = addText(0,180, "After The Sort");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText pivotName = addText(0,145, "Pivot");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText lowName = addText(60,145, "Low");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText highName = addText(120,145, "High");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		//loop to add all the nodes
		for(int i = 0;  i < size; i++)
		{
			s = Integer.toString(array[i]);
			boxes[i] = addTextBox(offset,50,30,30,s);
			boxes[i].setTextPaint(Color.black);
			offset += 30;
		}
		
		pivotNode = addTextBox(0,115,30,30,"Pivot");
		lowNode = addTextBox(60,115,30,30,"Low");
		highNode = addTextBox(120,115,30,30,"High");
		
		
	}
	
	
	//initalizes all the values of the array to random integer values between 10 - 100
	public static void initalizeArray(int array[])
	{
		for(int i = 0; i < size; i++)
		{
			array[i] = generator.nextInt(high - low) + low;
		}
	}
	
	
	
	public static void main (String[] args)
	{
		
		SortingAnimation screen = new SortingAnimation ();
		
		
		size = array.length;		
		initalizeArray(array);
		
		System.out.print("The values in the array before the sort ");
		for(int i = 0; i < size; i++)
		{
			System.out.print(array[i]);
			System.out.print(" ");
		}	
		
		// wait for initialization before animating
		screen.waitForInitialization ();
		
		
		quickSort(array,0,size-1);
		
		
		System.out.println();
		System.out.print("The values in the array after the sort ");
	
		for(int i = 0; i < size; i++)
		{
			System.out.print(array[i]);
			System.out.print(" ");
		}
		
		System.out.println();
		
		moveToNewPosition();

	}

	
	
	
	private static void waitForActivity (PActivity activity) {
		while (!activity.isStepping ()) {
			try {
				Thread.sleep (100);
			} catch (InterruptedException e) {
				// Whatever, I do what I want.
			}
		}

		while (activity.isStepping ()) {
			try {
				Thread.sleep (100);
			} catch (InterruptedException e) {
				// Whatever, I do what I want.
			}
		}
	}
	
	//Moves all the boxes to the correct position after the array has been sorted properly
	public static void moveToNewPosition()
	{
		
		int valueToMove = 0;
		String s1;
		
		//for each value in the array 
		for(int i = 0; i < size; i++)
		{
			s1 = Integer.toString(array[i]);
			valueToMove = findPos(s1);
			waitForActivity(boxes[valueToMove].animateToPositionScaleRotation (pX[i], 195, 1, 0, 1000)); 	
		}
		
	}
	
	//finds the position in the array of displayed boxes so we move the correct box
	public static int findPos(String s)
	{
		int rValue = 0;
		
		for(int i = 0; i < size; i++)
		{
			if(s.equals(boxes[i].getText()))
			{
				rValue = i;
			}
		}
		
		return rValue;
	}
	
	//swaps the two values in the array 
	public static void swap(int array[], int index1, int index2)
	{
		int temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;	
	}
	
	
	//sorts the array 
	public static void quickSort(int array[],int low, int high)
	{

		int i = low;
		int j = high;
	    
		//get the pivot
		int pivot = array[low];
	    	   
	    while (i <= j) 
	    {
	      while (array[i] < pivot) 
	      {
	        i++;
	        //timer for animation
	        try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				
			}
	        lowNode.setText(boxes[i].getText());
	      }
	 
	      while (array[j] > pivot) 
	      {
	        j--;
	        //timer for animation
	        try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
				
			}
	        highNode.setText(boxes[j].getText());
	       }

	      if (i <= j) 
	      {
	        swap(array,i, j);
	        //timer to wait
	        try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				
			}
	        pivotNode.setText(Integer.toString(pivot));
	        i++;
	        //timer to wait
	        try {
				Thread.sleep(200);
			} catch (InterruptedException e) {

			}
	        lowNode.setText(boxes[i].getText());
	        j--;
	        //timer to wait
	        try {
				Thread.sleep(300);
			} catch (InterruptedException e) {
				
			}
	        //error check to make sure we are still in bounds
	        if(j != -1)
	        {
	        	highNode.setText(boxes[i].getText());
	        }
	      }
	    }
	    // Recursion
	    if (low < j)
	      quickSort(array,low, j);
	    if (i < high)
	      quickSort(array,i, high);
	}
}