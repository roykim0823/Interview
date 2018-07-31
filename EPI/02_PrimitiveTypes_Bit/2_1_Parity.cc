// Compute the parity of a very large number of 64-bit nonnegative integers
#include <iostream>
using namespace std;

// O(n): n is the position of MSB bit plus 1
short parity1(unsigned long x) {
	short result=0;
	while(x) {
		result ^= (x & 1);
		x >>= 1;
	}
	return result;
}

// O(n): n is the the number of 1s
short parity2(unsigned long x) {
	short result=0;
	while(x) {
		result ^= 1;
		// Clear the right most 1
		x = x & (x-1);	// 01100 & 01011 -> remove the second 1
		// x & !(x-1) -> extract the lowest set bit of x
		// x ^ (x>>1) -> gray code for x
	}
	return result;
}

// O(1): using lookup table
/*
int precomputed_parity[2^16]; // Have all the 16-bit parity values
short parity3(const unsigned long &x) {
	return procomputed_parity[x>>48] ^ precomputed_parity[(x>>32) & 0xFFFF] ^
		precomputed_parity[(x>>16) & 0xFFFF] ^ precomputed_parity[x & 0xFFFF];
}
*/

int main()
{
	unsigned long x;
	x=0xFFFF;
	cout << std::hex << x << ", parity1 = " << parity1(x) << endl;
	cout << std::hex << x << ", parity2 = " << parity2(x) << endl;
	x=0xFFFE;
	cout << std::hex << x << ", parity1 = " << parity1(x) << endl;
	cout << std::hex << x << ", parity2 = " << parity2(x) << endl;
}
