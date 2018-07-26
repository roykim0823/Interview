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

#include "Deque.h"
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

	cout << endl << "Deque<int>:" << endl;

	Deque<int> as;
	cout << "Test Dequq::push_back() ";
	for(i=0; i<n; i++)
		as.push_back(i);
	for(i=0; i<n; i++)
		assert(as[i]==i);
	cout << "-> PASS" << endl;
	
	cout << "Test Deque::pop_back() ";
	for(i=0; i<n; i++)     {
		as.pop_back();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
	print(as);
	as.clear();

	cout << "Test Dequq::push_front() ";
	for(i=0; i<n; i++)
		as.push_front(i);
	for(i=0; i<n; i++)
		assert(as[i]==n-1-i);
	cout << "-> PASS" << endl;
	
	cout << "Test Deque::pop_front() ";
	for(i=0; i<n; i++)     {
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
	print(as);
	as.clear();
	
	cout << "Test Dequq::push_back() ";
	for(i=0; i<n; i++)
		as.push_back(i);
	for(i=0; i<n; i++)
		assert(as[i]==i);
	cout << "-> PASS" << endl;
	
	cout << "Test Deque::pop_front() ";
	for(i=0; i<n; i++)     {
		as.pop_front();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
	print(as);
	as.clear();
	
	cout << "Test Dequq::push_front() ";
	for(i=0; i<n; i++)
		as.push_front(i);
	for(i=0; i<n; i++)
		assert(as[i]==n-1-i);
	cout << "-> PASS" << endl;
	
	cout << "Test Deque::pop_back() ";
	for(i=0; i<n; i++)     {
		as.pop_back();
		assert(as.size()==n-1-i);
	}
	cout << "-> PASS" << endl;
	print(as);

	cout << "Test Dequq::push_*() " << endl;
	for(i=0; i<n; i++)  {
		if(i%2==0) 
			as.push_front(i);
		else
			as.push_back(i);
		print(as);
	}
	cout << "-> PASS" << endl;
	
	cout << "Test Dequq::pop_*() " << endl;
	for(i=0; i<n; i++)  {
		if(i%2==0) 
			as.pop_front();
		else
			as.pop_back();
		print(as);
	}
	cout << "-> PASS" << endl;
}

