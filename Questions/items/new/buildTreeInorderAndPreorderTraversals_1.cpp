#include "bTree.h"
#include <unordered_map>

template <typename T>
int search(T arr[], int strt, int end, char value) {
	int i; 
	for (i = strt; i <= end; i++) { 
		if (arr[i] == value) 
			return i; 
	} 
} 

/* Recursive function to construct binary of size len from 
   Inorder traversal in[] and Preorder traversal pre[]. 
   Initially: inBeg=0, inEnd=len-1
   T= O(n^2), worst case occurs when tree is left skewed
   worst case preOrder = {A, B, C, D}, inOrder {D, C, B, A}
*/
template <typename T>
//std::unique_ptr<btNode<T>> buildTree(T in[], T pre[], int preIndex, int inStrt, int inEnd) 
std::unique_ptr<btNode<T>> buildTree(T in[], T pre[], int inStrt, int inEnd) 
{ 
	static int preIndex=0;

	if (inStrt > inEnd) 
		return nullptr; 

	auto tNode = new_bt_Node<T>(pre[preIndex++]); 

	/* If this node has no children then return */
	if (inStrt == inEnd) 
		return tNode; 

	/* Else find the index of this node in Inorder traversal */
	auto inIndex = search<T>(in, inStrt, inEnd, tNode->data); 

	/* Using index in Inorder traversal, 
	   construct left and right subtress */
	tNode->l = buildTree(in, pre, inStrt, inIndex - 1); 
	tNode->r = buildTree(in, pre, inIndex + 1, inEnd); 
	return tNode; 
}

// Efficient Approach with hashing
// hash stores indexes of inorder traversal
// search can be done O(1) time
template <typename T> 
std::unordered_map<T, int> buildHash(T in[], T pre[], int len) {
	std::unordered_map<T, int> hash;

	for(int i=0; i<len; i++) 
		hash[in[i]] = i;
	
	return hash;
}

template <typename T>
//std::unique_ptr<btNode<T>> buildTree(T in[], T pre[], int preIndex, int inStrt, int inEnd) 
std::unique_ptr<btNode<T>> buildTree2(T in[], T pre[], int inStrt, int inEnd, 
	std::unordered_map<T, int> & hash) 
{ 
	static int preIndex=0;

	if (inStrt > inEnd) 
		return nullptr; 

	int curr = pre[preIndex++];
	auto tNode = new_bt_Node<T>(curr); 

	/* If this node has no children then return */
	if (inStrt == inEnd) 
		return tNode; 
	
	// Else find the index of this node in Inorder traversal using hash
	int inIndex = hash[curr];

	/* Using index in Inorder traversal, 
	   construct left and right subtress */
	tNode->l = buildTree2(in, pre, inStrt, inIndex - 1, hash); 
	tNode->r = buildTree2(in, pre, inIndex + 1, inEnd, hash); 
	return tNode; 
}


/* Driver program to test above functions */
int main() 
{ 
	char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
	char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
	int len = sizeof(in) / sizeof(in[0]); 
	auto root = buildTree<char>(in, pre, 0, len - 1); 

	/* Let us test the built tree by printing Insorder traversal */
	std::cout << "Inorder traversal of the constructed tree is" << std::endl; 
	printInorder<char>(root); 
	std::cout << std::endl;

	auto hash = buildHash<char>(in, pre, len);
	auto root2 = buildTree2<char>(in, pre, 0, len -1, hash);
	std::cout << "Inorder traversal of the constructed tree with hash is" << std::endl; 
	printInorder<char>(root2);
	std::cout << std::endl;
} 

