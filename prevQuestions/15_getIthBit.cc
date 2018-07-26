#include <iostream>

using namespace std;

int getBit(int num, int i) {
	int mask = 1 << i;	// set the ith bit to 1
	if( (num & mask) != 0)
		return 1;
	else
		return 0;
}

int main() 
{
    unsigned index = 0;
	cout << "0xFFFE at " << index << " => " << getBit(0xFFFE, index) << endl;
    index=1;
	cout << "0xFFFE at " << index << " => " << getBit(0xFFFE, index) << endl;
    index=15;
	cout << "0xFFFE at " << index << " => " << getBit(0xFFFE, index) << endl;
    index=16;
	cout << "0xFFFE at " << index << " => " << getBit(0xFFFE, index) << endl;
    index=31;
	cout << "0xFFFE at " << index << " => " << getBit(0xFFFE, index) << endl;
    index=31;
	cout << "0xFFFFFFFE at " << index << " => " << getBit(0xFFFFFFFE, index) << endl;

}
