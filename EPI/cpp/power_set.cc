#include <cmath>
#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

// One to One relationship bewteen the 2^|S| bit array of length |S|
// and the set of all subsets of S
// O(|S|*2^|S|) time, O(1) space
vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
  vector<vector<int>> power_set;
  for (int subset_idx = 0; subset_idx < (1 << input_set.size()); ++subset_idx) {
    int bit_array = subset_idx;
    vector<int> subset;
    while (bit_array) {
      int idx = log2(bit_array & ~(bit_array-1));  // log2(the right most set bit)
      subset.emplace_back(input_set[idx]);
      bit_array &= bit_array - 1;  // clear the right most '1' in bit_array
    }
    power_set.emplace_back(subset);
  }
  return power_set;
}

// clang-format off
int main(int argc, char* argv[]) {
  std::vector<std::string> args {argv + 1, argv + argc};
  std::vector<std::string> param_names {"input_set"};
  GenericTestMain(args, "power_set.cc", "power_set.tsv", &GeneratePowerSet, &UnorderedComparator<vector<vector<int>>>, param_names);
}
// clang-format on
