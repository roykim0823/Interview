/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */

#ifndef INTSET_LIST_H_
#define INTSET_LIST_H_
#include "intSet.h"

// p.136-137 IntSetList
struct node {
	int val;
	node *next;
	// same as insert v in front of p
	node(int v, node *p) { val = v; next = p; } 	// p is the next node
};

struct list {
//protected:
	size_t n;
	node *head, *sentinel;
//public:
	node *rinsert(node *p, int t) {
		if(p->val < t) {
			p->next = rinsert(p->next, t);
		} else if (p->val > t) {
			p = new node(t, p);
			n++;
		}
		return p;
	}
};

class IntSetList : public IntSet<list> {
public:
	IntSetList(int maxSize, int maxVal) {
		S.sentinel = S.head = new node(maxVal, nullptr);
		S.n=0;
	}
	int size() { return S.n; }
	void insert(int t) { S.head = S.rinsert(S.head, t); }
	void report(int *v) {
		int j=0;
		for(node *p = S.head; p != S.sentinel; p = p->next)
			v[j++] = p->val;
	}
	~IntSetList()  {
		node *tmp;
		for(node *p = S.head; p != S.sentinel; ) {
			tmp = p;
			p = p->next;
			delete tmp;
		}
		delete S.sentinel;
	}
};

#endif	// INTSET_LIST_H_
