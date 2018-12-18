#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

void setPrime(vector<bool> &flags, int prime);
int getNextPrime(vector<bool> &flags, int prime);

map<int, int> listPrime(int n) {
	vector<bool> flags(n+1, true);
	map<int, int>factors;
	int prime=2;

	while(n>1) {
		// set flag on in the remaining multiples of the prime
		setPrime(flags, prime);
		factors.insert(make_pair(prime, 0));
		while(n%prime==0) {
			n=n/prime;
			factors[prime]++;
		}
		if(factors[prime]==0)	
			factors.erase(prime);

		// Find next prime number
		prime = getNextPrime(flags, prime);


		if(prime>=flags.size())
			break;
	}
	//return flags;
	return factors;
}

void setPrime(vector<bool> &flags, int prime) {
	for(int i=prime*prime; i<flags.size(); i+=prime) 
		flags[i]=false;
}

int getNextPrime(vector<bool> &flags, int prime)
{
	int next = prime+1;
	while(next < flags.size() && !flags[next]) {
		next++;
	}
	return next;
}

void printPrimeList(vector<bool> flags) {
	for(int i=2; i<flags.size(); i++) {
		if(flags[i]==true)
			cout << i << " "; 
	}
	cout << endl;
}

void printFactors(map<int, int> factors) {
	map<int, int>::iterator iter;
	for(iter=factors.begin(); iter!=factors.end(); ++iter)
		cout << iter->first << " ^ " << iter->second << endl;
}


int main()
{
	//printPrimeList(listPrime(100));
	printFactors(listPrime(610));
}

