// Base Conversion
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

// number string base b1 -> base b2 (2<=base<=16)
string convertBase(const string &s, const int &b1, const int &b2) {
	// Check if the number is negative
	bool neg=false;	// default 
	if(s[0] == '-')
		neg=true;

	int x=0;
	size_t i= (neg == true? 1:0);	// calculate start index of the number
	for (; i<s.size(); ++i) {
		x = x*b1;
		if(isdigit(s[i]))
			x += s[i] - '0';
		else
			x += s[i] - 'A' + 10;
	}

	string ans;
	while(x) { 	// digits on base b2 in reverse order
		int r = x % b2;
		ans.push_back(r>=10 ? 'A' + r-10 : '0' + r);
		x /= b2;
	}

	if(ans.empty()) 
		ans.push_back('0');
	if(neg) 
		ans.push_back('-');
	
	reverse(ans.begin(), ans.end());
	return ans;
}
	
int main()
{
	string num1="-ABCD", num2="1234", num3="-43981", num4="4D2";
	cout << num1 << " -> " << convertBase(num1, 16, 10) << endl;
	cout << num3 << " -> " << convertBase(num3, 10, 16) << endl;
	cout << endl;
	cout << num2 << " -> " << convertBase(num2, 10, 16) << endl;
	cout << num4 << " -> " << convertBase(num4, 16, 10) << endl;
}

