/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */

#ifndef INTSET_BST_H_
#define INTSET_BST_H_
#include "intSet.h"

// p.138-139 IntSetBST
struct Bnode {
	int val;
	Bnode *left, *right;
	// same as insert v in front of p
	Bnode(int v) { val = v; left=right=nullptr; } 	// p is the next node
};

struct BST {
	size_t n, vn; 	// vn is for v's index in BST traverse
	int *v;
	Bnode *root, *sentinel;
	
	Bnode *rinsert(Bnode *p, int t) {
		if( p == nullptr ) {
			p = new Bnode(t);
			n++;
		} else if(t < p->val) {
			p->left = rinsert(p->left, t);
		} else if(t > p->val) {
			p->right = rinsert(p->right, t);
		} // do nothing if p->val == t
		return p;
	}
	void traverse(Bnode *p)
	{
		if(p == nullptr) 
			return;
		traverse(p->left);
		v[vn++] = p->val;
		traverse(p->right);
	}
	void deleteNode(Bnode *p) {
		// delete all nodes by post-order traverse
		if(p != nullptr) {
			deleteNode(p->left);
			deleteNode(p->right);
			//cout << "delete " << p->val << endl;
			delete p;
			p = nullptr;
		}
	}
	~BST() { deleteNode(root); }
};

class IntSetBST : public IntSet<BST> {
public:
	IntSetBST(int maxSize, int maxVal) {
		S.root = nullptr;
		S.n=0;
	}
	int size() { return S.n; }
	void insert(int t) { S.root = S.rinsert(S.root, t); }
	void report(int *v) { S.v = v; S.vn=0; S.traverse(S.root); }
};

#endif	// INTSET_LIST_H_
