#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  static auto majorityElement(std::vector<std::int32_t>& nums)
      -> std::vector<std::int32_t> {
    std::unordered_map<std::int32_t, std::size_t> freq;

    for (const auto& num : nums) {
      freq[num]++;
    }

    auto target = nums.size() / 3;

    std::vector<std::int32_t> ans;

    for (const auto& [key, val] : freq) {
      if (val > target) {
        ans.push_back(key);
      }
    }

    return ans;
  }
};