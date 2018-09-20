/* Copyright (C) 1999 Lucent Technologies */
/* From 'Programming Pearls' by Jon Bentley */
/* sets.cpp -- exercise set implementations on random numbers */
#ifndef INT_SET_BIN_H_
#define INT_SET_BIN_H_
#include "intSetList.h"	// to get struct node and list, use IntSetList

// p.141: combination of list and bit vectors
class IntSetBin {
private:
	int n, bins, maxval;
	IntSetList **bin;
public:
	IntSetBin(int maxelements, int pmaxval)
	{
		bins = maxelements;
		maxval = pmaxval;
		bin = new IntSetList*[bins];
		for(int i=0; i<bins; i++) {
			bin[i] = new IntSetList(0, maxval);
		}
        n=0;
	}
	int size() { return n; }
	void insert(int t)
	{
		int i = t / (1 + maxval/bins); // CHECK !
		//bin[i] = rinsert(bin[i], t);
		bin[i]->insert(t);
		n++;
	}
	void report(int *v)
	{
		for (int i = 0; i < bins; i++) {
			bin[i]->report(v);
			v = v+bin[i]->size();
		}
	}
};

class IntSetBins2 {
	private:
	int
	n, bins, maxval;
	struct node {
		int val;
		node *next;
	};
	node **bin, *sentinel, *freenode;
	node *rinsert(node *p, int t)
	{
		if (p->val < t) {
			p->next = rinsert(p->next, t);
		} else if (p->val > t) {
			freenode->val = t;
			freenode->next = p;
			p = freenode++;
			n++;
		}
		return p;
	}
	public:
	IntSetBins2(int maxelements, int pmaxval)
	{
		bins = maxelements;
		maxval = pmaxval;
		freenode = new node[maxelements];
		bin = new node*[bins];
		sentinel = new node;
		sentinel->val = maxval;
		for (int i = 0; i < bins; i++)
			bin[i] = sentinel;
		n = 0;
	}
	int size() { return n; }
	void insert1(int t)
	{
		int i = t / (1 + maxval/bins);
		bin[i] = rinsert(bin[i], t);
	}
	void insert(int t)
	{
		node **p;
		int i = t / (1 + maxval/bins);
		for (p = &bin[i]; (*p)->val < t; p = &((*p)->next))
			;
		if ((*p)->val == t)
			return;
		freenode->val = t;
		freenode->next = *p;
		*p = freenode++;
		n++;
	}
	void report(int *v)
	{
		int j = 0;
		for (int i = 0; i < bins; i++)
			for (node *p = bin[i]; p != sentinel; p = p->next)
				v[j++] = p->val;
	}
};

#endif	// INT_SET_BIT_H_ 
