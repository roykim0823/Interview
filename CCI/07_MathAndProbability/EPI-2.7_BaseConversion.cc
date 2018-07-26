#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;

string convertBase(const string &s, const int &b1, const int &b2) {
	bool neg=s[0]=='-';
	int x=0;

	for (int i=neg; i<s.size(); ++i) {
		x = x*b1;
		if(isdigit(s[i]))
			x += s[i] - '0';
		else
			x += s[i] - 'A' + 10;
	}

	string ans;
	while(x) {
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
	string num1="-ABCD", num2="1234";
	cout << num1 << " -> " << convertBase(num1, 16, 10) << endl;
	cout << num2 << " -> " << convertBase(num2, 10, 16) << endl;
}

