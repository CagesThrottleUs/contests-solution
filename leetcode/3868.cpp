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

#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <vector>

constexpr double HALF_COST = 0.5;

class Solution {
 public:
  auto minCost(std::vector<int>& nums1, std::vector<int>& nums2) -> int {
    std::unordered_map<int, int> freq_diff;
    for (std::size_t i{0}; i < nums1.size(); i++) {
      freq_diff[nums1[i]]++;
      freq_diff[nums2[i]]--;
    }

    double probable_cost{0};
    int sum{0};

    for (const auto& [num, diff] : freq_diff) {
      if ((diff & 1) == 1) {  // NOLINT(hicpp-signed-bitwise)
        return -1;
      }
      sum += diff;
      auto contributing = std::abs(diff) / 2;
      probable_cost += contributing * HALF_COST;
    }

    if (sum != 0) {
      return -1;
    }
    return static_cast<int>(std::floor(probable_cost));
  }
};