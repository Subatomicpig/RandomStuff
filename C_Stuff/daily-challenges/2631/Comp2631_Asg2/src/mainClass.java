

//This is the main class of asg2 
public class mainClass {
	

	//create a new fileIo class to handle our fileIo
	static fileIO file = new fileIO();
	static String inputString = null;
	static hashOpenAdressing openHash = new hashOpenAdressing(1867);
	static int hashKey = 0;
	
	
	
	public static void main( String [] args)
	{
		//open a file
		fileIO.openFile(System.out);
		String input;
		String trim;
		int hashKey;
		
		//Steps to follow for each line in the file get the string hash its value add it to the table
		//while there is a next line in the file 
		while(fileIO.hasNext())
		{
			//reads the string value from our file
			input = fileIO.readString(System.out);
			System.out.println(input);
			trim = fileIO.trimString(input, System.out);
			hashKey = openHash.hashFunction(input);
			System.out.println(hashKey);
			openHash.put(hashKey, input);
		}
		
		
		int clusters = openHash.getClusters();
		System.out.println("The Clusters are " + clusters);
		
		
	}
	
}
