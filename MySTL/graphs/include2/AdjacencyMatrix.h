/*
 * AdjacencyMatrix.h
 *
 *  Created on: 2012-01-13
 *      Author: morin
 */

#ifndef ADJACENCYMATRIX_H_
#define ADJACENCYMATRIX_H_

#include <vector>
namespace mySTL {

class AdjacencyMatrix {
protected:
	int n;
	//bool **a;
	std::vector<vector<bool>> matrix;

public:
	AdjacencyMatrix(int num): n(num) {
		/*
		a = new bool*[n];
		for(int i=0; i<n; i++) 
			a[i]= new bool[n];
		for(int i=0; i<n; i++) 
			for(int j=0; j<n; j++)
				a[i][j]=false;
		*/
		matrix.resize(n);
		for(int i=0; i<n; i++) 
			//matrix[i] = std::vector<bool>(n, false);
			matrix[i].resize(n, false);
	}

	virtual ~AdjacencyMatrix() {}
	/*
		for(int i=0; i<n; i++) 
			delete [] a[i];
		delete [] a;
	}*/

	void addEdge(int i, int j) {
		matrix[i][j] = true;
	}

	void removeEdge(int i, int j) {
		matrix[i][j] = false;
	}

	bool hasEdge(int i, int j) {
		return matrix[i][j];
	}

	template<typename T>
	void outEdges(int i, std::vector<T> &edges) {
		for (int j = 0; j < n; j++)
			if (matrix[i][j]) edges.push_back(j);
	}

	template<typename T>
	void inEdges(int i, std::vector<T> &edges) {
		for (int j = 0; j < n; j++)
			if (matrix[j][i]) edges.push_back(j);
	}

	int nVertices() {
		return n;
	}
};

} /* namespace ods */
#endif /* ADJACENCYMATRIX_H_ */
