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
#include <array>
#include <cstddef>
#include <cstdlib>
#include <limits>
#include <vector>

class Solution {
 public:
  auto minAbsoluteDifference(std::vector<int>& nums) -> int {
    std::array<std::vector<int>, 2> indices;

    for (std::size_t i{0}; i < nums.size(); i++) {
      if (nums[i] == 0) {
        continue;
      }
      indices.at(static_cast<std::size_t>(nums[i] - 1))
          .push_back(static_cast<int>(i));
    }

    int min_diff{std::numeric_limits<int>::max()};

    for (int idx_1 : indices.at(0)) {
      for (int idx_2 : indices.at(1)) {
        min_diff = std::min(min_diff, std::abs(idx_1 - idx_2));
      }
    }

    if (min_diff == std::numeric_limits<int>::max()) {
      return -1;
    }

    return min_diff;
  }
};