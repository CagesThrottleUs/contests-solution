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
#include <vector>

class Solution {
 public:
  auto longestArithmetic(std::vector<int>& nums) -> int {
    std::size_t arr_size = nums.size();
    if (arr_size <= 2) {
      return static_cast<int>(arr_size);
    }

    // left[i]: length of arithmetic subarray ending at i
    // with difference d = (nums[i] - nums[i-1])
    std::vector<int> left(arr_size, 1);
    for (std::size_t i = 1; i < arr_size; ++i) {
      if (i > 1 && nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        left[i] = left[i - 1] + 1;
      } else {
        left[i] = 2;
      }
    }

    // right[i]: length of arithmetic subarray starting at i
    // with difference d = (nums[i+1] - nums[i])
    std::vector<int> right(arr_size, 1);
    for (std::size_t i = arr_size - 2; i < arr_size; --i) {
      if (i < arr_size - 2 &&
          nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
        right[i] = right[i + 1] + 1;
      } else {
        right[i] = 2;
      }
    }

    int ans = 0;
    for (std::size_t i = 0; i < arr_size; ++i) {
      // 1. Change nums[i] to extend sequence from the left
      if (i > 0) {
        ans = std::max(ans, left[i - 1] + 1);
      }

      // 2. Change nums[i] to extend sequence from the right
      if (i < arr_size - 1) {
        ans = std::max(ans, right[i + 1] + 1);
      }

      // 3. Bridge case: Change nums[i] to connect left and right parts
      if (i > 0 && i < arr_size - 1) {
        std::int64_t diffSum = static_cast<std::int64_t>(nums[i + 1]) -
                               static_cast<std::int64_t>(nums[i - 1]);
        if (diffSum % 2 == 0) {
          std::int64_t diff = diffSum / 2;
          int current = 1;  // The modified element at index i

          // Check if left part matches difference d
          if (i >= 2 && nums[i - 1] - nums[i - 2] == diff) {
            current += left[i - 1];
          } else {
            current += 1;  // Only the element at nums[i-1]
          }

          // Check if right part matches difference d
          if (i <= arr_size - 3 && nums[i + 2] - nums[i + 1] == diff) {
            current += right[i + 1];
          } else {
            current += 1;  // Only the element at nums[i+1]
          }
          ans = std::max(ans, current);
        }
      }
    }

    return ans;
  }
};