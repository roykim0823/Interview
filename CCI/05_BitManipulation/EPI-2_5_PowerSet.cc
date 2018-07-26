#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// One to One relationship between the 2^|S| bit arrays of length |S| and the set of all subsets of S
template <typename T>
void generate_power_set(const vector<T> &S) {
	for(int i=0; i< ( 1<< S.size()); ++i) {	// 1<<S.size() = 2^S.size()
		int x=i;
		while (x) {
			int tar = log2( x & ~(x-1));  // log2(the right most set bit)
			cout << S[tar];
			if( x &= x-1)   	// x= x with the right most '1' is cleared
				cout << ',';
		}
		cout << endl;
	}
}

int main()
{
	vector<int> set;
	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);
	//set.push_back(5);
	generate_power_set(set);
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
}

