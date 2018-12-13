#include <iostream>
using namespace std;

int main() {
	cout << "Before try" << endl;
	try {
		cout << "Inside try" << endl;
		if( x < 0 ) {
			throw x;
			cout << "After throw (Never executed)" << endl;
		}
	}
	catch (int x) {
		cout << "Exception Caught" << endl;
	}

	cout << "After catch (Will be executed) " << endl;
	return 0;
}
