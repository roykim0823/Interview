#include <algorithm>
#include <string>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"

using std::string;

// Two step reverse words
// 1. reverse the entire string
// 2. reverse each string
// ex) "ram is costly"
//     1. "yltsoc si mar"
//     2. "costly is ram"

void ReverseWords(string* s) {
  // First, reverses the whole string.
  reverse(begin(*s), end(*s));

  size_t start = 0, finish;
  while ((finish = s->find(" ", start)) != string::npos) {
    // Reverses each word in the string.
    reverse(begin(*s) + start, begin(*s) + finish);
    start = finish + 1;
  }
  // Reverses the last word.
  reverse(begin(*s) + start, end(*s));
}

void ReverseWords_ref(string& s) {
  // First, reverses the whole string.
  reverse(s.begin(), s.end());

  size_t start = 0, finish;
  while ((finish = s.find(" ", start)) != string::npos) {
    // Reverses each word in the string.
    reverse(s.begin() + start, s.begin() + finish);
    start = finish + 1;
  }
  // Reverses the last word.
  reverse(s.begin() + start, s.end());
}

string ReverseWordsWrapper(TimedExecutor& executor, string s) {
  string s_copy = s;

  // executor.Run([&] { ReverseWords(&s_copy); });
  executor.Run([&] { ReverseWords_ref(s_copy); });

  return s_copy;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "s"};
  return GenericTestMain(args, "reverse_words.cc", "reverse_words.tsv",
                         &ReverseWordsWrapper, DefaultComparator{},
                         param_names);
}
