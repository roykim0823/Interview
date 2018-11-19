#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>	// for reverse
#include <stdexcept> 	// for throw invalid_argument

using namespace std;


// Integer to String
// 1. for positive integer x, divide x by 10 iteratively, and record the remainder till we get to 0
//    It yields the rsult from the LSB, and needs to be reverse!
// 2. for negative integer x, calculate -x (positive) and add '-'
string intToString(int x) {
	bool is_negative=false;
	if(x<0) {
		x=-x;
		is_negative=true;
	}

	string s;
	while(x) {
		s.push_back('0' + x % 10);	
		x /= 10;
	}
	if (s.empty())
		s="0";
	if(is_negative) 
		s.push_back('-');
	
	reverse(s.begin(), s.end());	
	return s;
}

int stringToInt(const string &s) {
	bool is_negative= s[0] == '-';
	int x=0;

	for(size_t i=is_negative; i<s.size(); ++i) { 	// is_negative to skip the '-' character
		if(isdigit(s[i])) {
			x = x * 10 + s[i] - '0';
		} else {	// without else invalid argument is ignored
			throw invalid_argument("illegal input");
		}
	}
	return is_negative ? -x: x;
}

int main()
{
	int i=-1234;
	//string s="$-1234";	// Throw exception
	string s="-5678";
	cout << i << " -> " << intToString(i) << endl;
	cout << s << " -> " <<  stringToInt(s) << endl;
}

