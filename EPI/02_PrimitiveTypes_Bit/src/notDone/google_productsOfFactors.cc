// Find all factors of the product of a give list of primes, (2, 3, 7) -> 1 2 3 6 7 14 21 42
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

void f(int a[], int k) // k = size of the array a
{
	int n = 1<<k;	// n=2^k;
	for(int i=0; i<n; i++) {
		int product=1;
		for(int j=0; j<k; j++)
			if(i & (1<<j)) product *=a[j];
		// for loop can be
		// if(i&1) product *=a[0]
		// if(i&2) product *=a[1]
		// if(i&4) product *=a[2]
		// But this is not flexible, what if a's length is 4
		cout << product << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	int a[3] = {2, 3, 7};

	f(a, 3);
}
