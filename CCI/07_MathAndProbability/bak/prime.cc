// Check the number is prime
#include <iostream>
#include <complex> 	// for sqrt using namespace std; bool prime_v1(int n) {

using namespace std;

bool prime_v1(int n) {	
	if (n<2) return false;

	for(int i=2; i<n; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}

bool prime_v2(int n) {
	if (n<2) return false;

	int sqrt_value = (int) sqrt(n);
	for(int i=2; i<= sqrt_value; i++) { // include sqrt value
		if(n % i == 0)
			return false;
	}
	return true;
}

void init(bool *flags, int flags_size) {
	flags[0]=false;
	flags[1]=false;
	for(int i=2; i<flags_size; i++)
		flags[i]=true;
}

void crossOff(bool*, int, int);
int getNextPrime(bool*, int, int);
bool* sieveOfEratosthenes(int max) {
	// Better one is only store odd numbers, the size of 1/2*max+1
	bool *flags = new bool[max+1];
	int count=0;

	init(flags, max+1);	// set all flags to true except 0 and 1
	int prime = 2;

	while(prime<=max) {
		// Cross off remaining multiples of prime
		crossOff(flags, max+1, prime);

		// Find next value which it true
		prime = getNextPrime(flags, max+1, prime);

		if(prime >=max+1) 
			break;
	}
	return flags;
}

void crossOff(bool *flags, int flags_size, int prime) {
	// cross off remaining multiples of prime.
	// We start with (prime*prime) since if we have k*prime, where k<prime
	// , then this value would have alread been crossed off in a prior iteration.
	for(int i=prime * prime; i<flags_size; i+=prime) {
		flags[i]=false;
	}
}

int getNextPrime(bool *flags, int flags_size, int prime)  { 
	int next = prime+1; 
	while(next < flags_size && flags[next]==false) {
		next++;
	}
	return next;
}

int main() 
{ 
	for(int i=1; i<100; i++) { 
		if(prime_v1(i))
			cout << i << " "; 
	}
	cout << endl;

	for(int i=1; i<100; i++) {
		if(prime_v2(i))
			cout << i << " "; 
	}
	cout << endl;

	bool *prime = sieveOfEratosthenes(100);
    for(int i=0; i<100; i++) {
		if(prime[i]==true)
			cout << i << " "; 
	}
	cout << endl;

}	
