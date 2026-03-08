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
#include <limits>
#include <vector>

class Solution {
 public:
  auto smallestBalancedIndex(std::vector<int>& nums) -> int {
    std::size_t size = nums.size();
    std::vector<std::int64_t> prefix_sum(size, 0);
    std::vector<std::int64_t> suffix_prod(size, 1);

    for (std::size_t i = 1; i < size; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }

    // Suffix product in int64_t; if it would overflow, it can't equal
    // prefix_sum (which is at most n*10^9). Use -1 as sentinel (prefix_sum is
    // always >= 0).
    std::int64_t prod = 1;
    for (std::size_t j = size; j > 0; j--) {
      std::size_t idx = j - 1;
      suffix_prod[idx] = (prod >= 0) ? prod : -1;
      if (prod >= 0 && prod <= std::numeric_limits<std::int64_t>::max() /
                                   static_cast<std::int64_t>(nums[idx])) {
        prod *= static_cast<std::int64_t>(nums[idx]);
      } else {
        prod = -1;
      }
    }

    for (std::size_t i = 0; i < size; i++) {
      if (prefix_sum[i] == suffix_prod[i]) {
        return static_cast<int>(i);
      }
    }
    return -1;
  }
};