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
  static auto trap(std::vector<std::int32_t>& height) -> std::int32_t {
    std::vector<std::int32_t> left_max(height.size(), 0);
    for (std::size_t i{1}; i < height.size(); i++) {
      left_max[i] = std::max(left_max[i - 1], height[i - 1]);
    }

    std::vector<std::int32_t> right_max(height.size(), 0);
    for (std::size_t i{height.size() - 2}; i < height.size(); i--) {
      right_max[i] = std::max(right_max[i + 1], height[i + 1]);
    }

    std::int32_t trapped_water{0};
    for (std::size_t i{0}; i < height.size(); i++) {
      auto min_height = std::min(left_max[i], right_max[i]);
      trapped_water += std::max(0, min_height - height[i]);
    }

    return trapped_water;
  }
};