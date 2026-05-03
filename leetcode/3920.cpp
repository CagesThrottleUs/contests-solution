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

struct Element {
  std::int32_t value;
  std::int32_t deletions;
};

auto custom_comparator(const Element& lhs, const Element& rhs) -> bool {
  if (lhs.value == rhs.value) {
    return lhs.deletions > rhs.deletions;
  }
  return lhs.value < rhs.value;
}

class Solution {
 public:
  static auto maxFixedPoints(std::vector<std::int32_t>& nums) -> std::int32_t {
    std::vector<Element> valid_pairs;
    for (std::size_t i = 0; i < nums.size(); i++) {
      std::int32_t value = nums[i];
      std::int32_t deletions = static_cast<std::int32_t>(i) - value;

      if (value >= 0 and deletions >= 0) {
        valid_pairs.push_back({.value = value, .deletions = deletions});
      }
    }

    std::ranges::sort(valid_pairs, custom_comparator);

    std::vector<std::int32_t> longest_non_dec_subseq;

    for (const auto& pair : valid_pairs) {
      auto itr =
          std::ranges::upper_bound(longest_non_dec_subseq, pair.deletions);

      if (itr == longest_non_dec_subseq.end()) {
        longest_non_dec_subseq.push_back(pair.deletions);
      } else {
        *itr = pair.deletions;
      }
    }

    return static_cast<std::int32_t>(longest_non_dec_subseq.size());
  }
};