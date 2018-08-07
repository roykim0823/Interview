#include <iostream>
//#include <random>
#include <stdlib.h>
#include <set>

using namespace std;

int main()
{
	/*
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;
	for(int i=0; i<10; i++)
		cout << u(e) << endl;
	*/
	int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Store all the index of the array into a set
	set<int> remaining;
	for(int i=0; i<10; i++)
		remaining.insert(i);
	
	unsigned cnt=0;
	// Use random value to print the array elements randomly
	while(!remaining.empty()) {
		cnt++;
		int index=rand()%10;
		if(remaining.find(index)!=remaining.end()) {
			cout << A[index] << endl;
			remaining.erase(index);
		}
	}
	cout << "iterations: " << cnt << endl;
}
