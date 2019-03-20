# Constructing a bianry tree from traversal sequences
Given two binary tree traversal sequences, construct a binary tree if
1. Inorder and Preorder
2. Inorder and Postorder
3. Inorder and level-order

A binary tree cannot be constructed with other combinations.
ex) even if three of them (preorder, postorder, and level-order) 
    are given, the gree cannot be constructed

# Construct Tree from given Inorder and Preorder traversals
Let us consider the below traversals:

Inorder sequence: 	D B E A F C
Preorder sequence: 	A B D E C F
Postorder sequence: D E B F C A

In a Preorder sequence, leftmost element is the root of the tree. 
So we know ‘A’ is root for given sequences. 
By searching ‘A’ in Inorder sequence, 
we can find out all elements on left side of ‘A’ are 
in left subtree and elements on right are in right subtree. 
So we know below structure now.

```
				      A
	                /   \
   	               /     \
		      D B E      F C
```

We recursively follow above steps and get the following tree.

```
					  A
  			        /   \
  			       /     \
  			      B       C
	       	     / \     /
	            /   \   /
  			   D    E   F
```
Algorithm: buildTree()
1. Pick an element from Preorder. Increment a Preorder Index Variable 
   (preIndex in below code) to pick next element in next recursive call.
2. Create a new tree node tNode with the data as picked element.
3. Find the picked element’s index in Inorder. Let the index be inIndex.
4. Call buildTree for elements before inIndex and make the built tree as left subtree of tNode.
5. Call buildTree for elements after inIndex and make the built tree as right subtree of tNode.
6. return tNode.

