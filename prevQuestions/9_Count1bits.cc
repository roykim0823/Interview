#include <iostream>

using namespace std;

int countOnes_ver1(unsigned num) {
	int cnt=0;

	int iter=0;
	while(num) {
    	if( (num & 1) != 0)
			cnt++;
		num >>= 1;
		iter++;
	}
	cout << "v1_iterations= " << iter << " ";

	return cnt;
}

int countOnes_ver2(unsigned num) {
	int cnt=0;

	int iter=0;
	while(num) {
		cnt++;
		num = num & (num-1);	// remove the right most 1
		iter++;
	}
	cout << "v2_iterations= " << iter << " ";

	return cnt;
}

int main() 
{
	unsigned num = 0xff;
	cout << "0xff -> " << countOnes_ver1(num) << endl;
	num = 0xefff;
	cout << "0xefff -> " << countOnes_ver1(num) << endl;
	num = 0xa5a5;
	cout << "0xa5a5 -> " << countOnes_ver1(num) << endl;
	num = 0x80000000;
	cout << "0x80000000 -> " << countOnes_ver1(num) << endl;
	
	num = 0xff;
	cout << "0xff -> " << countOnes_ver2(num) << endl;
	num = 0xefff;
	cout << "0xefff -> " << countOnes_ver2(num) << endl;
	num = 0xa5a5;
	cout << "0xa5a5 -> " << countOnes_ver2(num) << endl;
	num = 0x80000000;
	cout << "0x80000000 -> " << countOnes_ver2(num) << endl;

}
