#include <string>

class Solution {
  bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  std::string trimTrailingVowels(std::string s) {
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
      if (is_vowel(*it)) {
        s.pop_back();
      } else {
        break;
      }
    }
    return s;
  }
};