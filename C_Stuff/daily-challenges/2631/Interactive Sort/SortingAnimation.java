import java.awt.Color;
import java.util.Random;

import edu.umd.cs.piccolo.activities.PActivity;
import edu.umd.cs.piccolo.nodes.PText;

public class SortingAnimation extends AnimationScreen {
	private static final long serialVersionUID = 1L;
		
	
	//create 10 boxes
	private static TextBoxNode [] boxes = new TextBoxNode[10];
	private static TextBoxNode pivotNode;
	private static TextBoxNode lowNode;
	private static TextBoxNode highNode;
	
	
	private static int pX[] = {0,30,60,90,120,150,180,210,240,270};
	
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
		
		PText Pivot = addText(0,100, "During The Sorting");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText afterSort = addText(0,150, "After The Sort");
		beforeSort.setTextPaint(Color.DARK_GRAY);
		
		PText pivotName = addText(0,80, "Pivot");
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
		
		
	}
	
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
	
	
	public static void moveToNewPosition()
	{
		int offset = 0;
		int valueToMove = 0;
		String s1;
		String s2;
		
		//for each value in the array 
		for(int i = 0; i < size; i++)
		{
			s1 = Integer.toString(array[i]);
			valueToMove = findPos(s1);
			waitForActivity(boxes[valueToMove].animateToColor(Color.GREEN, 2000));
			waitForActivity(boxes[valueToMove].animateToPositionScaleRotation (pX[i], 165, 1, 0, 2000));
			waitForActivity(boxes[valueToMove].animateToColor(Color.WHITE, 2000));
		}
		
	}
	
	//finds the position in the array of displayed boxes
	public static int findPos(String s)
	{
		int rValue = 0;
		
		for(int i = 0; i < size; i++)
		{
			//if we found the spot
			if(s.equals(boxes[i].getText()))
			{
				rValue = i;
			}
		}
		
		return rValue;
	}
	
	public static void swap(int array[], int index1, int index2)
	{
		int temp = array[index1];
		array[index1] = array[index2];
		array[index2] = temp;
		
	}
	
	public static void quickSort(int array[],int low, int high)
	{
		
		
		int i = low, j = high;
	    // Get the pivot element from the middle of the list
	    int pivot = array[low];
	    //animate to show the pivot
	   

	    // Divide into two lists
	    while (i <= j) {
	      // If the current value from the left list is smaller then the pivot
	      // element then get the next element from the left list
	      while (array[i] < pivot) {
	        i++;
	      }
	      // If the current value from the right list is larger then the pivot
	      // element then get the next element from the right list
	      while (array[j] > pivot) {
	        j--;
	      }

	      // If we have found a values in the left list which is larger then
	      // the pivot element and if we have found a value in the right list
	      // which is smaller then the pivot element then we exchange the
	      // values.
	      // As we are done we can increase i and j
	      if (i <= j) {
	        swap(array,i, j);
	        pivotNode.setText(Integer.toString(pivot));
	        i++;
	        j--;
	      }
	    }
	    // Recursion
	    if (low < j)
	      quickSort(array,low, j);
	    if (i < high)
	      quickSort(array,i, high);
	}
}