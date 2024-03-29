// Same as Maximum rectangle in a histogram

#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "Largest_rectangle_under_skyline.h"

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

// O(n^2) implementation checks answer
int check_answer(const vector<int>& A) {
  int max = -1;
  for (int i = 0; i < A.size(); ++i) {
    int left = i - 1, right = i + 1;
    while (left >= 0 && A[left] >= A[i]) {
      --left;
    }
    while (right < A.size() && A[right] >= A[i]) {
      ++right;
    }
    int area = (right - left - 1) * A[i];
    if (area > max) {
      max = area;
    }
  }
  cout << max << endl;
  return max;
}

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 10; ++times) {
    vector<int> A;
    int n;
    if (argc == 2) {
      n = atoi(argv[1]);
    } else {
      uniform_int_distribution<int> dis(1, 1000);
      n = dis(gen);
    }
    while (n--) {
      uniform_int_distribution<int> dis(0, 999);
      A.emplace_back(dis(gen));
    }
    int area = calculate_largest_rectangle(A);
    cout << area << endl;
    assert(check_answer(A) == area);
  }
  return 0;
}
