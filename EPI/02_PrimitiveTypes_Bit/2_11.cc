#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

// Naive Prime
bool primeNaive(int n) {
	if( n < 2 ) 
		return false;
	
	// Better one use sqrt(n) instead of n in the for loop
	// for(int i=2; i<=sqrt; i++) {
	for(int i=2; i<n; i++) {
		if (n % i == 0) 
			return false
	}
	return true;
}


void setPrime(vector<bool> &flags, int prime);
int getNextPrime(vector<bool> &flags, int prime);

vector<bool> listPrime(const int &n) {
	vector<bool> flags(n+1, true);
	vector<int> primeList;
	int prime=2;

	while(prime<=n) {
		// set flag on in the remaining multiples of the prime
		setPrime(flags, prime);

		// Find next prime number
		prime = getNextPrime(flags, prime);

		if(prime>=flags.size())
			break;
	}
	return flags;
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

int main()
{
	printPrimeList(listPrime(100));
}
