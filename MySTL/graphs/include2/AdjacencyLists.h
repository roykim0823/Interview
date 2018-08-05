/*
 * AdjacencyLists.h
 *
 *  Created on: 2012-01-13
 *      Author: morin
 */

#ifndef ADJACENCYLISTS_H_
#define ADJACENCYLISTS_H_

#include <vector>
//#include "ArrayStack.h"

namespace mySTL {

class AdjacencyLists {
protected:
	std::vector<std::vector<int> > adj;
	int n;
	bool contains(int i, int j) {
		for(int k=0; k<adj[i].size(); k++) {
			if(adj[i][k] == j) 
				return true;
		}
		return false;
	}

public:
	AdjacencyLists(int n0):n(n0), adj(n) {}

	virtual ~AdjacencyLists() {}

	void addEdge(int i, int j) {
		adj[i].push_back(j);
	}

	bool hasEdge(int i, int j) {
		return contains(i, j);
	}

	template<typename T>
	void inEdges(int i, std::vector<T> &edges) {
		for (int j = 0; j < n; j++)
			if (contains(j, i))	edges.push_back(j);
	}

	int nVertices() {
		return n;
	}

	template<typename T>
	void outEdges(int i, std::vector<T> &edges) {
		for (int k = 0; k < adj[i].size(); k++)
			edges.push_back(adj[i][k]);
	}

	void removeEdge(int i, int j) {
		for (int k = 0; k < adj[i].size(); k++) {
			if (adj[i][k] == j) {
				adj[i].erase(adj[i].begin()+k);
				return;
			}
		}
	}

};

} /* namespace ods */
#endif /* ADJACENCYLISTS_H_ */
