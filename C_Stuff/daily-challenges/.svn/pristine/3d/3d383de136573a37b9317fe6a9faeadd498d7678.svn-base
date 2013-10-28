

//This will be the default skeleton for the two types of hash tables
//Every Hash Table will be a child of this class
public abstract class hashTable {

	//the total size of the hash table
	private int size;
	
	//add a default constructor
	public hashTable(int s)
	{
		
		this.size = s;
	}
	
	//figures out the hash value of the string we are entering 
	protected int hashFunction(String s,int size)
	{
		int hashValue = 0;
		hashValue = fileIO.sumString(s, System.out);
		hashValue = hashValue % this.size;

		if(hashValue >= size)
		{
			hashValue = 1;
		}
		
		return hashValue;
	}
	
	//set the size of the bucket we are using
	public void setBucketSize(int size)
	{
		this.size = size;
	}
	
	//gets the size of the current hash table
	public int getSize()
	{
		return this.size;
	}
	
}
