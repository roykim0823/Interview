#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

// Solution 1: Iterative
// One to One relationship between the 2^|S| bit arrays of length |S| 
// and the set of all subsets of S
// Time = O(|S| * 2^|S|)
template <typename T>
void generate_power_set(const vector<T> &S) {
	for(int i=0; i< ( 1<< S.size()); ++i) {		// 1<<S.size() = 2^S.size()
		int x=i;
		while (x) {
			int tar = log2( x & ~(x-1));  		// log2(the right most set bit)
			cout << S[tar];
			if( x &= x-1)   					// x= x with the right most '1' is cleared
				cout << ',';
		}
		cout << endl;
	}
}

// Solution 2: Recursion
// Time = O(|S| * 2^|S|), Space = O(|S|) which is the maximum of stack depth
template<typename T>
void generate_power_set_helper(const vector<T> &S, int idx, vector<T> &res) {
	if(res.empty() == false) {
		// Print the subset
		copy(res.cbegin(), res.cend()-1, ostream_iterator<T>(cout, ", "));
		cout << res.back();
	}
	cout << endl;

	for(int i=idx; i<(int)S.size(); i++) {
		res.emplace_back(S[i]);
		generate_power_set_helper(S, i+1, res);
		res.pop_back();
	}
}

template<typename T>
void generate_power_set2(const vector<T> &S) {
	vector<T> res;
	generate_power_set_helper(S, 0, res);
}

int main()
{
	vector<int> set;
	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);
	set.push_back(5);
	cout << "Solution 1: iterative" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	generate_power_set(set);
	cout << "Solution 2: recursion" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	generate_power_set2(set);
	return 0;
}

