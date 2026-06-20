#include <algorithm>
#include <cstdint>
#include <limits>
#include <vector>

class Solution {
 public:
  static auto maxProduct(std::vector<std::int32_t>& nums) -> std::int32_t {
    std::int32_t max_till_now{1};
    std::int32_t min_till_now{1};
    std::int32_t largest_product{std::numeric_limits<std::int32_t>::min()};

    for (const auto& num : nums) {
      auto min_prod = min_till_now * num;
      auto max_prod = max_till_now * num;

      auto temp_max = std::max({num, min_prod, max_prod});
      auto temp_min = std::min({num, min_prod, max_prod});

      max_till_now = temp_max;
      min_till_now = temp_min;

      largest_product = std::max(largest_product, max_till_now);
    }

    return largest_product;
  }
};