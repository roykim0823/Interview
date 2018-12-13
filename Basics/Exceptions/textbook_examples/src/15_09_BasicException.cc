// Using an exception
#include <iostream>

using namespace std;

double hmean(double a, double b);

int main()
{
	double x, y, z;

	cout << "Enter two numbers: ";
	while(cin>> x >> y)
	{
		try {
			z = hmean(x, y);
		}
		catch (const char *s) { 	// Start of exception Hanlder
			cout << s << endl;
			cout << "Enter a new pair of numbers: ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye!" << endl;
	return 0;
}

double hmean(double a, double b) {
	if (a==-b)
		throw "bad hmean() argements: a = -b not allowed";
	return 2.0 * a * b / (a+b);
}
