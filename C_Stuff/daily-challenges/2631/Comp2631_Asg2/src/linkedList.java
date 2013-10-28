//I am going to use a linked list to create a chaining hash table
public class linkedList {
	
	private bucketNode head;
	private bucketNode tail;
	private bucketNode temp; //only used to add elements and remove elements

	//constructor
	linkedList()
	{
		this.head = null;
		this.tail = null;
		this.temp = null;
	}
	
	//if the head is empty add the node otherwise find the end of the node and add it there
	public void addNode(bucketNode node)
	{
		if(head == null)
		{
			head.setNext(node);//if the head is pointing to nothing set it to the next node
			tail.setPrevious(node);//points the tail to the node we just entered 
		}
		else
		{
			tail.next = node; //set the tail to point at the new node
			tail = tail.next;
			
		}
	}
	
	
	//getters
	public bucketNode getHead()
	{
		return this.head;
	}
	
	public bucketNode getTail()
	{
		return this.tail;
	}
	

}
