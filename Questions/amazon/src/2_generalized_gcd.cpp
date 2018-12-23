#include <iostream>
#include "gcd.h"

using namespace std;

/* The GCD of three or more numbers equals the product of the prime factors common
   to all the numbers, but it can be also calculated by repeatedly taking the GCD of
   pairs of numbers.
   ex) gcd(a, b, c) 
   		= gcd(a, gcd(b, c))
		= gcd(gdc(a, b), c)
		= gcd(gdc(a, c), b)
*/

int generalizedGCD(int num, int* arr) 
{
	int result = arr[0];
	for(int i=1; i<num; i++) 
		result = gcd(result, arr[i]);

	return result;
}

int main() {
	int input1[5] = {2, 4, 6, 8, 10};
	int num1=5;

	cout << generalizedGCD(num1, input1) << endl;

	cout << "Extended Euclidean Algorithm:" << endl;
	int x, y;
	int a = 35, b = 15;
	int g = gcdExtended(a, b, x, y);
	cout << "gcd( " << a << ", " << b << ") = " << g << endl;

    a = 30; b=20;
	g = gcdExtended(a, b, x, y);
	cout << "gcd( " << a << ", " << b << ") = " << g << endl;
	
	return 0;
}
