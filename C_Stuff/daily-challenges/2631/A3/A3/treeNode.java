
public class treeNode {
	
	public treeNode leftChild;
	public treeNode rightChild;
	public int data;
	
	//initalize all the nodes in the tree
	public treeNode()
	{
		data = -1;
		leftChild = null;
		rightChild = null;
	}
	

	//sets the data for the nodes
	public void setData(int value)
	{
		this.data = value;
	}
	
	public void printData()
	{
		System.out.println(this.data);
	}
	
	
	public boolean hasRightChild()
	{
		boolean child = false;
		if(this.rightChild != null)
			child = true;
		return child;
	}
	//checks if there are child nodes 
	public boolean hasLeftChild()
	{
		boolean child = false;
		if(this.leftChild != null)
			child = true;
		return child;
	}
	
	public treeNode getRightChild()
	{
		return this.rightChild;
	}
	
	//gets the left child
	public treeNode getleftChild()
	{
		return this.leftChild;
	}
	
	//returns the data for the nodes
	public int getData()
	{
		return this.data;
	}
}
