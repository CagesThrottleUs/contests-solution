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
#include <limits>
#include <vector>

constexpr double HALF = 2.0;

class Solution {
 public:
  // NOLINTNEXTLINE(misc-no-recursion)
  auto findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
      -> double {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    std::size_t left{0};
    std::size_t right{nums1.size()};

    const auto total_size = nums1.size() + nums2.size();

    while (left <= right) {
      auto mid = left + ((right - left) / 2);

      auto part_a_end = mid;
      auto part_b_end = ((total_size + 1) / 2) - part_a_end;

      auto max_a_left = part_a_end == 0 ? std::numeric_limits<int>::min()
                                        : nums1[part_a_end - 1];
      auto min_a_right = part_a_end == nums1.size()
                             ? std::numeric_limits<int>::max()
                             : nums1[part_a_end];
      auto max_b_left = part_b_end == 0 ? std::numeric_limits<int>::min()
                                        : nums2[part_b_end - 1];
      auto min_b_right = part_b_end == nums2.size()
                             ? std::numeric_limits<int>::max()
                             : nums2[part_b_end];

      if (max_a_left <= min_b_right and max_b_left <= min_a_right) {
        if ((total_size & 1ULL) == 1) {
          return std::max(max_a_left, max_b_left);
        }
        return (std::max(max_a_left, max_b_left) +
                std::min(min_a_right, min_b_right)) /
               HALF;
      }

      if (max_a_left > min_b_right) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};
