import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


//This class will handle the reading of the file
//The input and output of files
public class fileIO {
	
	private static Scanner scannerIn = null;
	
	//opens the file for reading the lines into the hash table
	//Reminder ask jason if we want the user to choose what file is to be opened
	public static void openFile(PrintStream out)
	{
		try {
			scannerIn = new Scanner( new FileInputStream("asgn2.dat"));	
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			out.println("File Not Found");
		}
		
	}
	
	static public boolean hasNext()
	{
		return scannerIn.hasNext();
	}
	
	
	static public String readString(PrintStream out)
	{
		//null string until we add the code to read through the file
		String s = null;

		if(scannerIn.hasNext())
		{
			s = scannerIn.nextLine();
		}
		return s;
	}
	
	public static String trimString(String s,PrintStream out)
	{
		String trimmedString;
		int trimStart;
		
		if(s != null)
		{
			trimStart = s.lastIndexOf('/');
			trimmedString = s.substring(trimStart + 1, s.length());
			
			return trimmedString;
		}

		return s;
	}
	
	//sums the string for use in the hash function
	static int sumString(String s, PrintStream out)
	{
		int sumString = 0;
		
		for(int i = 0; i < s.length(); i ++)
		{
			sumString = (int) s.charAt(i) * (i + 103);
		}
		
		return sumString;
	}

}
