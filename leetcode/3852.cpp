#include <cstddef>
#include <map>
#include <vector>

class Solution {
  std::map<int, std::size_t> frequency;

public:
  std::vector<int> minDistinctFreqPair(std::vector<int> &nums) {
    frequency.clear();

    for (const auto &num : nums) {
      frequency[num]++;
    }

    std::vector<int> result;
    bool first{true};
    for (const auto &[num, freq] : frequency) {
      if (first) {
        result.push_back(num);
        first = false;
      } else if (freq != frequency[result.back()]){
        result.push_back(num);
        break;
      }
    }

    if (result.size() == 1) {
      return {-1, -1};
    }

    return result;
  }
};
