
public class quickSort {
	
	public quickSort()
	{
		
	}

	
	public void sort(int array[], int low, int high)
	{
		
		    int i = low, j = high;
		    // Get the pivot element from the middle of the list
		    int pivot = array[low];

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
		        i++;
		        j--;
		      }
		    }
		    // Recursion
		    if (low < j)
		      sort(array,low, j);
		    if (i < high)
		      sort(array,i, high);
	}
		

	public void swap(int array[], int index1, int index2)
	{
			int temp = array[index1];
			array[index1] = array[index2];
			array[index2] = temp;
	}
}