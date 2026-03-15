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

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <vector>

class Solution {
 public:
  auto gcdSum(std::vector<int>& nums) -> std::int64_t {
    auto max_num = nums[0];
    for (std::size_t i{1}; i < nums.size(); i++) {
      max_num = std::max(max_num, nums[i]);
      nums[i] = std::gcd(nums[i], max_num);
    }
    std::ranges::sort(nums);

    std::int64_t sum{0};

    std::size_t start{0};
    std::size_t end{nums.size() - 1};

    while (start < end) {
      sum += std::gcd(nums[start], nums[end]);
      start++;
      end--;
    }

    return sum;
  }
};