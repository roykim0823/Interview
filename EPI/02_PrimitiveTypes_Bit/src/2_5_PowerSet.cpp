#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <random>
#include "power_set.h"

using namespace std;

int main(int argc, char* argv[])
{
	vector<int> set = {1, 2, 3, 4};
	cout << "Solution 1: iterative" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	vector<vector<int> > power_sets;
	power_sets = generate_power_set(set);
	for(auto iter = power_sets.begin(); iter != power_sets.end(); ++iter) {
		print_vec(*iter);
	}
	cout << "Alternative..." << endl;
	power_sets = generate_power_set2(set);
	for(auto iter = power_sets.begin(); iter != power_sets.end(); ++iter) {
		print_vec(*iter);
	}
	
	cout << "Solution 2: recursion" << endl;
	cout << "Set size = " << set.size() << endl;;
	cout << "# sets = " << (1<<set.size()) << endl;;
	generate_power_setR(set);

 
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
      		S[i] = i+1;
    	}
  	}
  	power_sets = generate_power_set(S);
	for(auto iter = power_sets.begin(); iter != power_sets.end(); ++iter) {
		print_vec(*iter);
	}
	return 0;
}

