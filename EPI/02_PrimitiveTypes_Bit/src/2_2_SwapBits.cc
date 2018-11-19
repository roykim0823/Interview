// Swap ith and jth bit of 64-bit integer
#include <iostream>

using namespace std;

long swap_bits(unsigned long x, const int &i, const int &j) {
	// Nothing to swap if the values of index i and index j are same
	if( ((x >> i) & 1) != ((x >> j) &1) )	// but without "if" is simpler
		x ^= (1L << i) | (1L << j);		// xor 0->1, 1->0
	return x;
}

int main()
{
	unsigned long x;
	int i, j;
	x=0xFFFF;
	i=0;
	j=16;
	cout << std::hex << x << std::dec<< i << j <<", swap = " << std::hex << swap_bits(x, i, j) << endl;
	j=1;
	cout << std::hex << x << std::dec<< i << j <<", swap = " << std::hex << swap_bits(x, i, j) << endl;
}

