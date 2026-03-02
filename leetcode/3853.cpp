#include <string>
#include <unordered_map>

class Solution {
  std::unordered_map<char, std::size_t> pos;

public:
  std::string mergeCharacters(std::string s, int k) {
    std::string result;
    for (const auto &ch : s) {
      if (pos.count(ch) == 0) {
        pos[ch] = result.size();
        result.push_back(ch);
      } else {
        if (result.size() - pos[ch] <= k) {
          continue;
        } else {
          pos[ch] = result.size();
          result.push_back(ch);
        }
      }
    }

    return result;
  }
};
