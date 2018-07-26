#include "Graph.h"
#include <iostream>

int main()
{
	Graph tinyG(6);	// #Vertices = 13
	int edge[13][3]={{0, 5, 1}, {4, 3, 1}, {0, 1, 1}, {9, 12, 1}, {6, 4, 0}, 
	 	{5, 4, 1}, {0, 2, 1}, {11, 12, 1}, {9, 10, 1}, {0, 6, 1}, {7, 8, 1},
		{9, 11, 1}, {5, 3, 1}};
	
    for (int i=0; i<13; i++)
	{
		Edge e(edge[i][0], edge[i][1], edge[i][2]);
		tinyG.add(e);
	}

	std::cout << "NumVertices: " << tinyG.getNumVertices() << "\n";
	std::cout << "NumEdges: " << tinyG.getNumEdges() << "\n";
	tinyG.getTable();

	return 0;
}

						

