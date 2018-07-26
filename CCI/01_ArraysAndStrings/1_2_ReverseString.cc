// Q. Implement a function void reverse(char *str) in C or C++ which reverses 
// a null-terminated string.
// Q+. reverse string 

// Solution: Be careful for the null character

#include <iostream>
#include <string>

using namespace std;

// O(n)
const char* reverse(const char *str) {	// return is void since this is same as swap
	
	string str_rev;
	if(str)		// Skip null 
	{
		int cnt=0;
		while(*str) {
			str++;
			cnt++;
		}
		str--;	// set one char back, since str points to null
		
		for(int i=0; i<cnt; i++) 
			str_rev+=*str--;

	return str_rev.c_str();
	}
}

// Better O(n): but n is 1/2 of the string length, by swaping
string reverse(string str) {
	int length = str.size();
	int last = length-1;
	
	for(int i=0; i<length/2; i++) {
		char c = str[i];
		str[i] = str[last-i];
		str[last-i] = c;
	}
	return str;
}

int main()
{
	string input;
	cin >> input;

	cout << reverse(input.c_str()) << endl;
	cout << reverse(input) << input.size() << endl;

	return 0;
}
