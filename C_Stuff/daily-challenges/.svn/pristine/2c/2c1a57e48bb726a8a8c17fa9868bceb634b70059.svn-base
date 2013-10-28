/**
 * <code>IntegerTree</code> is an interface which represents a binary search
 * tree that contains integers. In practice, the interface has methods
 * consistent with a <em>set</em> data type. That is, it holds a set of integers
 * without order. For each integer, it is either in the set or not in the set.
 * 
 * @author Jason Heard
 * @version 1.5
 */
public interface integerTree {
	/**
	 * Determines whether the specified key exists in the tree. This method then
	 * returns {@code true} if the key is found in the tree; {@code false}
	 * otherwise.
	 * 
	 * This method should <b>not</b> change the tree.
	 * 
	 * @param key The key to find in the tree.
	 * @return {@code true} if the key is found in the tree; {@code false}
	 *         otherwise.
	 */
	boolean find (int key);

	/**
	 * Inserts the specified key in the tree. This method then returns {@code
	 * true} if the key was added to the tree (did not previously exist in the
	 * tree); {@code false} otherwise.
	 * 
	 * @param key The key to insert in the tree.
	 * @return {@code true} if the key was added to the tree (did not previously
	 *         exist in the tree); {@code false} otherwise.
	 */
	boolean insert (int key);

	/**
	 * Deletes the specified key from the tree. This method then returns {@code
	 * true} if the key was deleted from tree (did previously exist in the
	 * tree); {@code false} otherwise. In the case of the deletion of a node
     * with two children, the inorder predecessor will be used.
	 * 
	 * @param key The key to delete from the tree.
	 * @return {@code true} if the key was deleted from tree (did previously
	 *         exist in the tree); {@code false} otherwise.
	 */
	boolean delete (int key);

    /**
     * Retrieves a string representation of the tree baseed on an in-order
     * traversal of the tree. The returned string will have each value from the
     * tree on a separate line. I.e. as each node is visited in the in-order
     * traversal, the integer value stored in the node is appended to the string
     * along with a newline character ({@code '\n'}); this includes the last
     * node.
     *
     * @return The string representation of the tree based on an in-order
     * traversal of the tree.
     */
    String inOrder ();

    /**
     * Retrieves a string representation of the tree baseed on a pre-order
     * traversal of the tree. The returned string will have each value from the
     * tree on a separate line. I.e. as each node is visited in the pre-order
     * traversal, the integer value stored in the node is appended to the string
     * along with a newline character ({@code '\n'}); this includes the last
     * node.
     *
     * @return The string representation of the tree based on a pre-order
     * traversal of the tree.
     */
    String preOrder ();

	/**
	 * Retrieves the current size of the tree (the number of keys in the tree).
	 * 
	 * @return The current size of the tree (the number of keys in the tree).
	 */
	int size ();

	/**
	 * Resets the tree to its initial state (with no keys).
	 */
	void clear ();
}
