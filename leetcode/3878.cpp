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
#include <cstdint>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  auto countGoodSubarrays(std::vector<int>& nums) -> std::int64_t {
    std::int64_t ans = 0;

    // OR groups: (or_value, leftmost_index) ordered by non-decreasing OR value.
    // All subarrays [left..right] sharing the same OR are contiguous in
    // left-space.
    std::vector<std::pair<int, int>> groups;

    // Monotone decreasing stack of (value, index): answers
    // "rightmost index <= right with value > orVal".
    std::vector<std::pair<int, int>> mono;

    std::unordered_map<int, int> lastSeen;

    // Binary search on the monotone stack: values are decreasing, so elements
    // exceeding orVal form a prefix — we want the rightmost such index.
    auto rightmostExceeding = [&](int orVal) -> int {
      int low = 0;
      int high = static_cast<int>(mono.size()) - 1;
      int result = -1;
      while (low <= high) {
        int mid = low + ((high - low) / 2);
        if (mono[static_cast<std::size_t>(mid)].first > orVal) {
          result = mono[static_cast<std::size_t>(mid)].second;
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return result;
    };

    for (int right = 0; right < static_cast<int>(nums.size()); right++) {
      // Rebuild OR groups by prepending nums[right]; merge groups with equal
      // OR.
      std::vector<std::pair<int, int>> next = {
          {nums[static_cast<std::size_t>(right)], right}};
      for (auto [orVal, left] : groups) {
        int merged = static_cast<int>(
            static_cast<unsigned int>(orVal) |
            static_cast<unsigned int>(nums[static_cast<std::size_t>(right)]));
        if (merged != next.back().first) {
          next.emplace_back(merged, left);
        } else {
          next.back().second = left;
        }
      }
      groups = std::move(next);

      lastSeen[nums[static_cast<std::size_t>(right)]] = right;
      while (!mono.empty() &&
             mono.back().first <= nums[static_cast<std::size_t>(right)]) {
        mono.pop_back();
      }
      mono.emplace_back(nums[static_cast<std::size_t>(right)], right);

      // For each OR group (orVal, [leftBound..rightBound]), count lefts where:
      //   (1) orVal in [left..right]  →  left <= lastSeen[orVal]
      //   (2) no element > orVal in [left..right]  →  left >
      //   rightmostExceeding(orVal)
      for (int idx = 0; idx < static_cast<int>(groups.size()); idx++) {
        auto [orVal, leftBound] = groups[static_cast<std::size_t>(idx)];

        int rightBound = right;
        if (idx > 0) {
          rightBound = groups[static_cast<std::size_t>(idx - 1)].second - 1;
        }

        if (!lastSeen.contains(orVal)) {
          continue;
        }

        int low = std::max(leftBound, rightmostExceeding(orVal) + 1);
        int high = std::min(rightBound, lastSeen[orVal]);
        if (low <= high) {
          ans += high - low + 1;
        }
      }
    }

    return ans;
  }
};