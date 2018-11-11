// Find all factors of a give int. Order doesn't matter ex) 20 -> 1 2 4 5 10 20
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <deque>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

// Naive version: O(n)
void factors(int n)
{
    cout << "factors=  ";
	for(int i=1; i<=n; i++)  {	// i=0 -> Floating point exception
		if(n%i==0)
			cout << i << " ";
	}
	cout << endl;             
}

// O(n/i), i is the second largest factor
void factors3(int n) {
    cout << "factors3= ";
	for(int i=1; i<=n/i; i++)  {	// i=0 -> Floating point exception
		if(n%i==0) {
			cout << i << " ";
			if(i!=n/i)
				cout << n/i << " ";
			
			//n/=i;
		}
	}
	cout << endl;   
}

int main(int argc, char* argv[]) {
	int n;
  
  	if (argc == 2) {
    	n = atoi(argv[1]);
  	} else
  		n=20;
    cout << "n = " << n << endl;
  	factors(n);
	factors3(n);
}