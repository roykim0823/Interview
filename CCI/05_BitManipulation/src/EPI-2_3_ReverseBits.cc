#include <iostream>

using namespace std;

// O(n): n is bit width of x
unsigned long reverse_bits1(unsigned long x) {
	unsigned long reversed=0;
	int i=63;
	while(i--) {
		reversed |= (x & 1);
		x >>= 1; 
		reversed <<=1;
	}
	return reversed;
}

// O(n): 2/n, 32 iterations in all cases
unsigned long reverse_bits2(unsigned long x) {
	int i=63, j=0;
	while(i>j) {
	 	if( ((x >>i) & 1) != ((x >> j) &1)) { 	// skip bits are same
			x^= (1L << i) | (1L << j); 	// swap bits if there are different
			//cout << x << endl;
		}
		i--;j++;
	}
	return x;
}

// O(1): with a lookup table
/*
unsigned long reverse_bits3(unsigned long x) {
	return precomputed_reverse[(x >> 48) & 0xFFFF] |
		precomputed_reverse[(x >> 32) & 0xFFFF] << 16 |
		precomputed_reverse[(x >> 16) & 0xFFFF] << 32 |
		precomputed_reverse[x & 0xFFFF] << 48;
}
*/

int main()
{
	unsigned long x;
	x=0xFFFF;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = " << reverse_bits1(x) << endl;
	x=0xFFF0;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = " << reverse_bits1(x) << endl;
	x=0xFFFF;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = " << reverse_bits2(x) << endl;
	x=0xFFF0;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = " << reverse_bits2(x) << endl;
	x=0x0000000080000000;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = " << reverse_bits2(x) << endl;
}

