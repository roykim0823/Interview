#ifndef _UF
#define _UF

#include <iostream>
#include <vector>

class QuickFindUF
{
	std::vector<int> id;	// access to component id 
	int count;				// number of components

public:
	QuickFindUF(int N)
	{
		// Initialize component id array
		count = N;
		id.resize(N);
		for(int i=0; i<N; i++)
			id[i]=i;
	}

	int get_count() { return count; }
	bool connected(int p, int q) 
	{ 
		return find(p) == find(q);
	}

	int find(int p) { return id[p]; }

	void connect(int p, int q)
	{
		// Put p and q into the same component
     	int pID = find(p);
		int qID = find(q);

		// Nothing to do if p and q are already in the same component
		if(pID == qID) return;

		// Rename p's component to q's name
		std::vector<int>::iterator pos;
		for(pos=id.begin(); pos!=id.end(); ++pos)
			if(*pos==pID) *pos=qID;
		count--;
	}

};


class QuickUnionUF
{
	std::vector<int> id;	// access to component id 
	int count;				// number of components

public:
	QuickUnionUF(int N)
	{
		// Initialize component id array
		count = N;
		id.resize(N);
		for(int i=0; i<N; i++)
			id[i]=i;
	}

	int get_count() { return count; }
	
	bool connected(int p, int q) 
	{ 
		return find(p) == find(q);
	}

	int find(int p)	// Find the root
	{ 
		// Find component name
		while (p !=id[p]) p=id[p];
		return id[p]; 
	}

	void connect(int p, int q)
	{
		// Put p and q into the same component
     	int pRoot = find(p);
		int qRoot = find(q);

		if(pRoot == qRoot) return;

		// Rename p's component to q's name
		id[pRoot] = qRoot;
		count--;
	}

};


class WeightedQuickUnionUF
{
	std::vector<int> id;	// access to component id 
	std::vector<int> sz;	// size of component for roots  
	int count;				// number of components

public:
	WeightedQuickUnionUF(int N)
	{
		// Initialize component id array
		count = N;
		id.resize(N);
		for(int i=0; i<N; i++)
			id[i]=i;
		sz.resize(N);
		for(int i=0; i<N; i++)
			sz[i]=1;

	}

	int get_count() { return count; }
	
	bool connected(int p, int q) 
	{ 
		return find(p) == find(q);
	}

	int find(int p)	// Find the root
	{ 
		// Find component name
		while (p !=id[p]) 
		{
			id[p] = id[id[p]]; // Path Compression
			p=id[p];
		}
		return id[p]; 
	}

	void connect(int p, int q)
	{
		// Put p and q into the same component
     	int i = find(p);
		int j = find(q);

		if(i == j) return;

		// Rename p's component to q's name
		if(sz[i] < sz[j]) { 
			id[i] = j; sz[j]+=sz[i];
		} else {
			id[j] = i; sz[i]+=sz[j];
		}
		count--;
	}

};

#endif
