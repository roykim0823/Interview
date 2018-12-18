#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <random>

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

int main(int argc, char* argv[])
{
	vector<int> set = {1, 2, 3, 4, 5};
	cout << "Solution 1: iterative" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	generate_power_set(set);
	cout << "Solution 2: recursion" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	generate_power_set2(set);
 
 	// extensive tests
  	vector<int> S;
  	if (argc >= 2) {
    	for (int i = 1; i < argc; ++i) {
     		 S.emplace_back(atoi(argv[i]));
    	}
  	} else {
    	default_random_engine gen((random_device())());
   		uniform_int_distribution<int> dis(1, 10);
    	S.resize(dis(gen));
    	for (size_t i = 0; i < S.size(); ++i) {
      		S[i] = i;
    	}
  	}
  	generate_power_set(S);
	return 0;
}

