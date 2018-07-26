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

#include "Vector.h"
using namespace mySTL;

int main(int argc, char **argv)
{
	int n = 20, i;


	srand(0);

	cout << endl << "Vector<int>:" << endl;

	cout << "Test Vector::push_back() ";
	Vector<int> as;
	for(i=0; i<n; i++)
		as.push_back(i);
	for(i=0; i<n; i++)
		assert(as[i]==i);
	cout << "-> PASS" << endl;
	
	cout << "Test Vector::reverse() ";
	as.reverse();
	for(i=0; i<n; i++)
		assert(as[i]==n-1-i);
	cout << "-> PASS" << endl;
	
	cout << "Test Vector::pop_back() ";
	for(i=0; i<n; i++)     {
		as.pop_back();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
}

