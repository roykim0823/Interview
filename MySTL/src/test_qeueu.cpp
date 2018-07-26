/*
 * main.cpp
 *
 *  Created on: 2011-11-23
 *      Author: morin
 */
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "Queue.h"
using namespace mySTL;

template <typename T>
void print(T& x) 
{
	for(int i=0; i<x.size(); i++)
		cout << x[i] << " ";
	cout << endl;
}

int main(int argc, char **argv)
{
	int n = 20, i;


	srand(0);

	cout << endl << "Queue<int>:" << endl;

	Queue<int> as;
	cout << "Test Queue::push() " << endl;;
	for(i=0; i<n; i++) {
		as.push(i);
		print(as);
	}
	for(i=0; i<n; i++)
		assert(as[i]==n-1-i);
	cout << "-> PASS" << endl;
	
	cout << "Test Queue::pop_back() " << endl;;
	for(i=0; i<n; i++)     {
		as.pop();
		assert(as.size()==n-1-i);
		print(as);
	}
	cout << "-> PASS" << endl;
}

