// Find all factors of the product of a give list of primes, (2, 3, 7) -> 1 2 3 6 7 14 21 42
#include "power_set.h"

using namespace std;

int main(int argc, char* argv[]) {
	vector<int> vec = {2, 3, 7};
	vector<int> products;
	
	products = factors(vec);
	print_vec(products);
	products = factors2(vec);
	print_vec(products);

	vec.push_back(1);
	products = factors(vec);
	print_vec(products);
	products = factors2(vec);
	print_vec(products);
}
