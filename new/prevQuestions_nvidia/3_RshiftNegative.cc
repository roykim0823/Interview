#include <iostream>
#include <string>
#include <vector>

using namespace std;

int foo(int a) {
	int result = 0;
	while (a >>= 1)
		result+=1;
	return result;
}

int main()
{
	cout << foo(-16) << endl;
}
