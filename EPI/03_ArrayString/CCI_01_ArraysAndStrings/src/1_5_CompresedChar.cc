// Q. Implement a method to perform basic string compression using the counts of repeated characters.
// e.g., aabccccaaa -> a2b1c4a3, If the "compressed" string would not become smaller than the original string
// you method should return the original string

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
            
string to_string(int);
string to_string2(int);

void compress(string &str) {	
	string temp;
	temp.reserve(str.size() << 1); 	// to reduce # memory move
	
	char prev=str[0];
    int cnt=1;
	int idx=0;

	for (int i=1; i<str.size(); i++)  {
		if(str[i] == prev)	// Found repeated char  
			cnt++;
		else {          	// Insert char count, and update last char
			temp.append(prev+to_string2(cnt));	
			cnt=1;
			prev=str[i];
		}
	}
	// Add last element
    temp.append(prev+to_string2(cnt));
	temp.shrink_to_fit();

	if(temp.size() < str.size())
		str=temp;
}

int main()
{
	string str;//ex) str = "aabcccccaaad";
	cin >> str;
    compress(str);
	cout << str << endl;
	return 0;
}

string to_string2(int number)
{
	ostringstream convert;
	convert << number;
	return convert.str();
}

string to_string(int number)
{
	string numberString;
	char ones_char; int ones = 0;
	while (true) {
		// each digit at a time
		ones = number % 10;
		switch(ones) {
			case 0: ones_char = '0';break;
			case 1: ones_char = '1';break;
			case 2: ones_char = '2';break;
			case 3: ones_char = '3';break;
			case 4: ones_char = '4';break;
			case 5: ones_char = '5';break;
			case 6: ones_char = '6';break;
			case 7: ones_char = '7';break;
			case 8: ones_char = '8';break;
			case 9: ones_char = '9';break;
			default: 
				cout << "Error" << endl;
				break;
		}
		number -= ones;
		numberString = ones_char+numberString;
		if(number==0) 
			break;
		// remove each digit value
		number = number / 10;
	}
	return numberString;
}

