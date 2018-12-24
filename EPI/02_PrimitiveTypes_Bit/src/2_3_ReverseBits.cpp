#include "reverse_bits.h"
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	unsigned long x;
	x=0xFFFF;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = "; 
	cout.width(16);
	cout.fill('0');
	cout << std::hex << reverse_bits1(x) << endl;
	
	x=0xFFF0;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = ";
	cout.width(16);
	cout.fill('0');
	cout << std::hex << reverse_bits1(x) << endl;
	
	x=0xFFFF;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = ";
	cout.width(16);
	cout.fill('0');
	cout << reverse_bits2(x) << endl;
	
	x=0xFFF0;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = ";
	cout.width(16);
	cout.fill('0');
	cout << reverse_bits3(x) << endl;
	
	x=0x0000000080000000;
	cout.width(16);
	cout.fill('0');
	cout << std::hex<< x << ", reversed = ";
	cout.width(16);
	cout.fill('0');
	cout << reverse_bits3(x) << endl;
  
  // tests
  create_precomputed_table();
  if (argc == 2) {
    long x = atoi(argv[1]);
    cout << "sizeof(x) = " << sizeof(x) << endl;
    cout << "x = " << x << ", reverse x = " << reverse_bits(x) << endl;
    cout << reverse_x(x, 63) << endl;
    assert(reverse_bits(x) == reverse_x(x, 63));
  } else {
    default_random_engine gen((random_device())());
    for (int times = 0; times < 1000; ++times) {
      uniform_int_distribution<long> dis(0, numeric_limits<long>::max());
      long x = dis(gen);
      cout << "x = " << x << ", reverse x = " << reverse_bits(x) << endl;
      assert(reverse_bits(x) == reverse_x(x, 63));
    }
  }
  return 0;
}
