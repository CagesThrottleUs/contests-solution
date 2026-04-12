/*
 *   MIT License
 *
 *   Copyright (c) 2026 CagesThrottleUs
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <cstddef>
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  static auto subarraySum(std::vector<int>& nums, std::int32_t subarr_sum)
      -> std::uint32_t {
    std::unordered_map<std::int32_t, std::uint32_t> prefix_sum_to_count;
    prefix_sum_to_count.reserve(nums.size());
    prefix_sum_to_count[0] = 1;

    std::int32_t sum{0};

    std::uint32_t count{0};

    for (std::size_t i{0}; i < nums.size(); i++) {
      sum += nums[i];
      count += prefix_sum_to_count[sum - subarr_sum];
      prefix_sum_to_count[sum]++;
    }

    return count;
  }
};