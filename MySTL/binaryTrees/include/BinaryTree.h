/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
//#include <cstdlib>
//#include "ArrayDeque.h"
#include <iostream>
#include <vector>
#include <new>
#include <memory>

namespace ods {

// Binary Tree Node
template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;	// for iterative version of traverse or size
				// without the parent field, list or stack is used to
				// keep track of the path from the current node to the root
	BTNode() {
		left = right = parent = nullptr;
	}
};


template<class Node>
class BinaryTree {
protected:
	Node *root;    // root node
	virtual int size(Node *u);
	virtual int height(Node *u);
	virtual void traverse(Node *u);
public:
	BinaryTree(): root(nullptr) {}
	virtual ~BinaryTree();
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
};


template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = root, *prev = nullptr, *next;
	while (u != nullptr) {
		if (prev == u->parent) {
			if (u->left != nullptr) next = u->left;
			else if (u->right != nullptr) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nullptr) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		if (next == u->parent)
			delete u;
		u = next;
	}
	root = nullptr;
}

// Depth of a node
template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != root) {
		u = u->parent;
		d++;
	}
	return d;
}

// The size of the tree
template<class Node>
int BinaryTree<Node>::size() {
	return size(root);
}

// a size of a node, the number of nodes (Recursive)
template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nullptr) return 0;
	return 1 + size(u->left) + size(u->right);
}

// Size the tree (Iterative) -> Prevent stack overflow
// Left, Right, Parent
template<class Node>
int BinaryTree<Node>::size2() {
		Node *u = root, *prev = nullptr, *next;
		int n = 0;
		while (u != nullptr) {
			if (prev == u->parent) {	// if we arrive at a node u from u.parent,
				n++;	// count a node when it arrives from the parent node
				if (u->left != nullptr) next = u->left;			// first, tries to visit u.left
				else if (u->right != nullptr) next = u->right;	// second, tries to visit u.right
				else next = u->parent;                      // finally, move back to u.parent
			} else if (prev == u->left) { // if we arrive at a node u from u.left,
				if (u->right != nullptr) next = u->right;		// first, tries to visit u.right
				else next = u->parent;                      // finally, move back to u.parent
			} else {                   // if we arrives at a node from u.right
				next = u->parent;                     		// move back to u.parent
			}
			prev = u;
			u = next;
		}
		return n;
	}


// The height of the tree
template<class Node>
int BinaryTree<Node>::height() {
	return height(root);
}

// a height of a node (Recursive)
template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nullptr) return -1;
	return 1 + max(height(u->left), height(u->right));
}

// Traverse the tree
template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(root);
}

// Traverse from a node (Recursive)
template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
		if (u == nullptr) return;
		// cout << u->x << " "; 	// print values in preorder
		traverse(u->left);
		// cout << u->x << " "; 	// print values in inorder
		traverse(u->right);
		// cout << u->x << " "; 	// print values in postorder
}

// Traverse the tree (Iterative) -> Prevent stack overflow
// Left, Right, Parent: Post-Order
template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = root, *prev = nullptr, *next;
	while (u != nullptr) {
		if (prev == u->parent) {
			if (u->left != nullptr) next = u->left;
			else if (u->right != nullptr) next = u->right;
			else next = u->parent;
		} else if (prev == u->left) {
			if (u->right != nullptr) next = u->right;
			else next = u->parent;
		} else {
			next = u->parent;
		}
		prev = u;
		u = next;
	}
}

// Breadth-first Traversal
template<class Node>
void BinaryTree<Node>::bfTraverse() {
	std::vector<Node*> q;
	if (root != nullptr) q.push_back(root);	// q.size() is just a parameter 
	while (q.size() > 0) {
		Node *u = q[q.size()-1];
		if (u->left != nullptr) q.push_back(u->left);
		if (u->right != nullptr) q.push_back(u->right);
	}
}


} /* namespace ods */
#endif /* BINARYTREE_H_ */
