#include <iostream>
#include <string>
#include <vector>

using namespace std;

int foo(int a) {
	int result = 0;
	//while (a >>= 1 && result<10) {
	while (result<10) {
		cout << a << endl;
		a>>=1;	// it fills '1' 
		result+=1;
	}
	return result;
}

int main()
{
	foo(-256);
	//cout << foo(-16) << endl;
}
