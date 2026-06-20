#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

class Solution {
 public:
  static auto maxSubArray(std::vector<std::int32_t>& nums) -> std::int32_t {
    std::int32_t max_sum{std::numeric_limits<std::int32_t>::min()};
    std::int32_t sum{0};

    for (const auto& num : nums) {
      sum += num;
      max_sum = std::max(max_sum, sum);
      sum = std::max(sum, 0);
    }

    return max_sum;
  }
};