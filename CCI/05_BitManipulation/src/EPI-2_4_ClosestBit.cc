#include <iostream>

using namespace std;

// Swapping the first two consecutive bits that differs, 1s is nor 0 or 64
unsigned long closest_int_same_bits(unsigned long x) {
	for(int i=0; i<63; i++) {
		if( ((x>>i) & 1) ^ ((x >> (i+1)) &1)) { // if they are different
			x ^= (1UL << i) | (1UL << (i+1));	// swap bit-i and bit-(i+1)
			return x;
		}
	}
	return x;
}
			
int main()
{
	unsigned long x;
	x=0xFFFF;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", closest = " << closest_int_same_bits(x) << endl;
	x=0b1011100;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", closest = " << closest_int_same_bits(x) << endl;
}

