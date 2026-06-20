#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

class Solution {
 public:
  static auto threeSum(std::vector<std::int32_t>& nums)
      -> std::vector<std::vector<std::int32_t>> {
    std::ranges::sort(nums);

    std::int32_t target = 0;
    std::vector<std::vector<std::int32_t>> ans;

    for (std::size_t i{0}; i < nums.size(); i++) {
      if (i > 0 && nums.at(i) == nums.at(i - 1)) {
        continue;
      }
      two_sum(i + 1, nums, ans, target - nums.at(i), nums.at(i));
    }

    return ans;
  }

 private:
  static void two_sum(std::size_t start, const std::vector<std::int32_t>& nums,
                      std::vector<std::vector<std::int32_t>>& ans,
                      std::int32_t target, std::int32_t first) {
    std::size_t end = nums.size() - 1;

    while (start < end) {
      std::int32_t sum = nums.at(start) + nums.at(end);
      if (sum > target) {
        {
          end--;
        }
      } else if (sum < target) {
        {
          start++;
        }
      } else {
        ans.push_back({first, nums.at(start), nums.at(end)});
        update_index(nums, start, end);
      }
    }
  }

  static void update_index(const std::vector<std::int32_t>& nums,
                           std::size_t& start, std::size_t& end) {
    std::int32_t _val = nums.at(start);
    while (start < end && _val == nums.at(start)) {
      start++;
    }

    _val = nums.at(end);
    while (start < end && _val == nums.at(end)) {
      end--;
    }
  }
};