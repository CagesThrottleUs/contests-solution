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
#include <vector>

class Solution {
  auto is_valid(const std::vector<int>& sorted, std::size_t window_size,
                const std::vector<int>& nums) -> bool {
    for (std::size_t i = 0; i < nums.size(); i += window_size) {
      bool found = false;
      for (std::size_t rot = 0; rot < window_size && !found; rot++) {
        bool match = true;
        for (std::size_t j = 0; j < window_size && match; j++) {
          if (nums[i + j] != sorted[i + ((rot + j) % window_size)]) {
            match = false;
          }
        }
        if (match) {
          found = true;
        }
      }
      if (!found) {
        return false;
      }
    }
    return true;
  }

 public:
  auto sortableIntegers(std::vector<int>& nums) -> int {
    const auto size = nums.size();

    auto sorted(nums);
    std::ranges::sort(sorted);

    int ans = 0;
    for (std::size_t i = 1; i <= size; i++) {
      if (size % i == 0) {
        if (is_valid(sorted, i, nums)) {
          ans += static_cast<int>(i);
        }
      }
    }

    return ans;
  }
};