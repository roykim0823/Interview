// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include "prime.h"
#include <cassert>
#include <cmath>
#include <deque>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	/*
  if (argc == 2) {
    int n = atoi(argv[1]);
    cout << "n = " << n << endl;
    vector<int> primes = generate_primes_from_1_to_n(n);
    for (size_t i = 0; i < primes.size(); ++i) {
		  cout << primes[i] << " ";
      for (int j = 2; j < primes[i]; ++j) {
        assert(primes[i] % j);
      }
    }
	cout << endl;
  } else {
    default_random_engine gen((random_device())());
    for (int times = 0; times < 100; ++times) {
      uniform_int_distribution<int> dis(2, 100000);
      int n = dis(gen);
      cout << "n = " << n << endl;
      vector<int> primes = generate_primes_from_1_to_n(n);
      for (size_t i = 0; i < primes.size(); ++i) {
        for (int j = 2; j < primes[i]; ++j) {
          assert(primes[i] % j);
        }
      }
    }
  }
     */
  cout << "printPrimeList (1..100)" << endl;
  printPrimeList(listPrime(100));
  return 0;
}
