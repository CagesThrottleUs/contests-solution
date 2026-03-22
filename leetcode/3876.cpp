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
#include <functional>
#include <set>
#include <vector>
class Solution {
 public:
  auto uniformArray(std::vector<int>& nums1) -> bool {
    std::set<int, std::greater<>> evens;
    std::set<int> odds;
    for (const auto& num : nums1) {
      if ((num & 1) == 0) {  // NOLINT(hicpp-signed-bitwise)
        evens.insert(num);
      } else {
        odds.insert(num);
      }
    }

    if (evens.empty() || evens.size() == nums1.size()) {
      return true;
    }

    for (const auto& num : evens) {
      if ((num & 1) == 0) {  // NOLINT(hicpp-signed-bitwise)
        auto itr = odds.lower_bound(num);
        if (itr == odds.begin()) {
          return false;
        }
        // odds.insert(num - *odds.begin());
      }
    }

    return true;
  }
};