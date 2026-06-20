#include <algorithm>
#include <cstdint>
#include <ranges>
#include <vector>

class Solution {
 public:
  static void nextPermutation(std::vector<std::int32_t>& nums) {
    // find range from reverse begin to reverse end for sorted
    auto last_in_sorted =
        std::ranges::is_sorted_until(std::views::reverse(nums));

    if (last_in_sorted != nums.rend()) {
      // find upper bound in rev begin to last_in_sorted
      auto good_itr =
          std::upper_bound(nums.rbegin(), last_in_sorted, *last_in_sorted);
      std::iter_swap(good_itr, last_in_sorted);
    }

    std::reverse(nums.rbegin(), last_in_sorted);
  }
};