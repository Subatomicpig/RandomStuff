import java.io.PrintStream;


//create a subclass of a hash table
//create a linearprobing
public class hashOpenAdressing extends hashTable {
	
	private bucket [] table = new bucket[1867];
	private int probes = 0;
	private int size;
	
	
	//constructor for the first part of the hash table
	hashOpenAdressing(int size) {
		super(size);
		bucket [] table = new bucket[size];
		initTable();
		this.size = size;
	}
	
	
	public int hashFunction(String s)
	{
		int hashValue = super.hashFunction(s,this.size);
		return hashValue;
	}
	
	//initalize the table so nothing is null
	void initTable()
	{
		for(int i = 0; i < this.getSize(); i++)
		{
			table[i] = new bucket();
		}		
	}
	
	//add the code to add the values into the hash table
	public void put(int key, String s)
	{
	
				String trim = fileIO.trimString(s,System.out);
				
		
				if(key <= this.size)
				{
					//if not in the table hash it at that location
					if(table[key].inTable() == false)
					{
						table[key].setCommand(trim);
						table[key].setPath(s);
						table[key].setIndex(key);
						table[key].setInTable(true);
						probes = probes + 1;
					}
					//hash it at the next location	
					else
					{
						//makes sure our hash keys are in bounds
						if(key < this.size - 1)
						{
							put(key + 1,s);
							probes = probes + 1;
						}
						//reach the end of our table so start from the begining 
						else if(key >= this.size)
						{
							key = -1;
							put(key + 1,s);
							probes = probes + 1;
						}
					}
				}
					
	}
	
	//finds the first instance of a cluster
	private int findStartCluster()
	{
		int i = 0;;
		
		while(table[i].inTable() == false)
		{
			i = i + 1;
		}
		
		return i;
	}
	
	
	//enter the first part of a cluster and returns the end of a cluster
	private int findEndCluster(int start)
	{	
		while(table[start].inTable() == true)
		{
			start = start + 1;
		}
		
		return start;
	}
	
	//gets the clusters in the hash table after reading in all the data
	public int getClusters()
	{
		//checks for the start and the end of the cluster
		int startCluster;
		int endCluster;
		int i = 0;
		
		startCluster = findStartCluster();
		endCluster = findEndCluster(startCluster);
		i = startCluster; //set it to the begining of the clusters
		while(i < endCluster)
		{
			i = i + 1;//increment until we get to the end of the cluster
		}
		
		i = i - startCluster; //subtract the inital start so we get exacltly how many buckets are in the cluster
		
		return i;
	}
	
	public void printData(int key)
	{
		System.out.println(table[key].getPath());
		System.out.println(table[key].getCommand());
		System.out.println(table[key].inTable());
	}

	public int getProbes()
	{
		return this.probes;
	}
	
	//returns the path of the string we entered
	String getPath(int index)
	{
		return this.table[index].getPath();
	}
	
	//returns the command from the string we entered
	String getCommand(int index)
	{
		return this.table[index].getCommand();
	}	
	
	
	
}
