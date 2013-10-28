public class binaryTree implements	integerTree {
	
	private treeNode root;
	private int size;
	
	//constructor
	public binaryTree()
	{
		this.root = null;
		size = 0;
	}
	
//inserts a node in the correct spot
public boolean insertNode(int key)
{
	 
		 treeNode newNode = new treeNode();
		 newNode.data= key;
		 if(root==null)
		 {
			        	root = newNode;
			        	return true;
		 }
		 else
		  {
		      treeNode current = root;
		      treeNode parent;
		      while(true)
			  {
			       parent = current;
			       if(key < current.data)
			       {
			          current = current.leftChild;
			          if(current == null)
			          {
			               parent.leftChild = newNode;
			               return true;
			          }
			        }
			        else
			            {
			               current = current.rightChild;
			               if(current == null)
			               {
			                  parent.rightChild = newNode;
			                  return true;
			               }
			           }
			        }
			    }
}


	
	//checks if a node is found pass in the root to find the node
	public boolean findNode(int key,treeNode node)
	{
		boolean found = false;
		
		//if the root is null keep do nothing
		if(this.root == null)
		{
			found = false;
		}
		else
		{	//if the node is not null
			if(node != null)
			{
				//if the data is less keep moving left
				if(key < node.getData())
				{
					found = findNode(key,node.leftChild);
				}
				else if(key > node.getData())
				{
					found = findNode(key,node.rightChild);
				}
				else if(key == node.getData())
				{
					found = true;
				}	
			}
		}
		
		return found;
	}
	
	
	//set the tree to its initial state
	public void clearTree()
	{
		if(root == null)
		{
			System.out.println("Nothing to delete");
		}
		root = null;
		size = 0;
	}
	
	/*
	 * Delete Node and find Successor was taken from
	 * http://chinmaylokesh.wordpress.com/2011/10/22/binary-search-tree-bst-implementation-to-insert-a-node-delete-a-node-search-a-node-and-display-the-tree/
	 * 
	 * 
	 * 
	 */
	
	public boolean delete(int val,treeNode node)
    {
	      treeNode current = root;
	      treeNode parent = root;
	      boolean isLeftChild = true;
	       while(current.getData() != val)
	        {
	            parent = current;
	            if(val < current.getData())
	            {  
	                isLeftChild = true;
	                current = current.leftChild;
	            }
	            else
	            {
	                isLeftChild = false;
	                current = current.rightChild;
	            }
	            if(current == null)
	                return false;
	 
	        }
			if(current.leftChild==null && current.rightChild==null)
			     {
			          if(current == root)
			              root = null;
			          else if(isLeftChild)
			              parent.leftChild = null;
			          else
			              parent.rightChild = null;
			     }
			else if(current.rightChild==null)
			 {
			            if(current == root)
			                root = current.leftChild;
			            else if(isLeftChild)
			                parent.leftChild = current.leftChild;
			            else
			                parent.rightChild = current.leftChild;
			        }
			        else if(current.leftChild==null)
			        {
			            if(current == root)
			                root = current.rightChild;
			            else if(isLeftChild)
			                parent.leftChild = current.rightChild;
			            else
			                parent.rightChild = current.rightChild;
			        }
			        else
			        {
			            treeNode successor = findSuccessor(current);
			            if(current == root)
			                root = successor;
			            else if(isLeftChild)
			                parent.leftChild = successor;
			            else
			                parent.rightChild = successor;
			            successor.leftChild = current.leftChild;
			        }
					size--;
			        return true;
			    }
		    
	/*
	 * Delete Node and find Successor was taken from
	 * http://chinmaylokesh.wordpress.com/2011/10/22/binary-search-tree-bst-implementation-to-insert-a-node-delete-a-node-search-a-node-and-display-the-tree/
	 * 
	 * 
	 * 
	 */	
	private treeNode findSuccessor(treeNode delNode)
    {
        treeNode successorParent = delNode;
        treeNode successor = delNode;
        treeNode current = delNode.rightChild;
        while(current != null)
        {
            successorParent = successor;   
            successor = current;
            current = current.leftChild;
        }
        if(successor != delNode.rightChild)
        {
            successorParent.leftChild = successor.rightChild;
            successor.rightChild = delNode.rightChild;
        }
        return successor;
   }
	
	
	//prints the tree out in preOrder
	public void treePreorder(treeNode node)
	{
		if(node != null)
		{
			System.out.println(node.getData() + " ");
			treePreorder(node.leftChild);
			treePreorder(node.rightChild);
		}
	}
	
	//prints the tree out in inOrder
	public void treeInOrder(treeNode node)
	{
		if(node != null)
		{
			treeInOrder(node.leftChild);
			node.printData();
			treeInOrder(node.rightChild);
		}
	}
	
	public int treeSize()
	{
		return this.size;
	}
	
	@Override
	public boolean find(int key) {
		return this.findNode(key,this.root);
	}

	@Override
	public boolean insert(int key) {
		return this.insertNode(key);
	}


	@Override
	public boolean delete(int key) {
		return this.delete(key, this.root);
	}


	@Override
	public String inOrder() {
		this.treeInOrder(this.root);
		return null;
	}


	@Override
	public String preOrder() {
		this.treePreorder(this.root);
		return null;
	}


	@Override
	public int size() {
		return this.treeSize();
	}


	@Override
	public void clear() {
		this.clearTree();	
	}

}
