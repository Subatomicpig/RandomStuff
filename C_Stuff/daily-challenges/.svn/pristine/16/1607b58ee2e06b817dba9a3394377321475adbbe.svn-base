//Bucket class for the hash table
//create an array of buckets that contain the following
public class bucket {
	
	//the string that we are holding at this address in the hash table 
	private String path;
	private String command;
	//where the bucket is in the hash table
	private int hashIndex;
	//checks to see if the bucket has been delete from the hash table
	private boolean deleted;
	//checks to see if it is implemented in the hash table
	private boolean inTable;
	
	//constructor for the bucket class
	bucket()
	{
		hashIndex = -1;
		deleted = false;
		inTable = false;
	}
	

	//gets the command from the string
	String getCommand()
	{
		return this.command;
	}
	
	//gets the path of the data
	String getPath()
	{
		return this.path;
	}
	
	
	//sets if this value has been entered 
	void setInTable(boolean bool)
	{
		this.inTable = bool;
	}
	
	
	//returns if this bucket is in use in the table
	boolean inTable()
	{
		return this.inTable;
	}
	
	//returns the index 
	int getIndex()
	{
		return this.hashIndex;
	}
	
	//checks if the bucket has been deleted
	boolean getDeleted()
	{
		return this.deleted;
	}
	
	//sets the path of the bucket "ex /bin/users/ls"
	void setPath(String s)
	{
		this.path = s;
	}
	
	//sets the command of the string that is passed into it and trims it so its the command "ex ls"
	void setCommand(String s)
	{
		this.command = s;
	}
	
	//sets the index of the table we are hashing
	void setIndex(int index)
	{
		this.hashIndex = index;
	}
	
	//sets if the object has been deleted
	void setDeleted(boolean deleted)
	{
		this.deleted = deleted;
	}
	
	
}
