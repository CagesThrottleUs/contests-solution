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
#include <string>
#include <vector>

class Solution {
 public:
  auto minCost(const std::string& str, int encCost, int flatCost)
      -> std::int64_t {
    const std::size_t n = str.size();
    if (n == 0) {
      return 0;
    }

    std::vector<std::int64_t> sum(n + 1, 0);
    for (std::size_t i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + (str[i] == '1' ? 1 : 0);
    }

    std::size_t num_levels = 0;
    for (std::size_t val = n; val % 2 == 0 && val > 0; val /= 2) {
      ++num_levels;
    }
    if (num_levels == 0) {
      const std::int64_t cnt1 = sum[n] - sum[0];
      if (cnt1 == 0) {
        return static_cast<std::int64_t>(flatCost);
      }
      return static_cast<std::int64_t>(n) * cnt1 *
             static_cast<std::int64_t>(encCost);
    }

    std::vector<std::vector<std::int64_t>> memo(num_levels + 1);
    for (std::size_t k = 0; k <= num_levels; ++k) {
      memo[k].resize(std::size_t{1} << k);
    }

    for (std::size_t k = num_levels;; --k) {
      const std::size_t seg_len = n >> k;
      const std::size_t num_seg = std::size_t{1} << k;
      for (std::size_t i = 0; i < num_seg; ++i) {
        const std::size_t start = i * seg_len;
        const std::size_t end = start + seg_len - 1;
        const std::int64_t cnt1 = sum[end + 1] - sum[start];
        std::int64_t cost = (cnt1 == 0)
                                ? static_cast<std::int64_t>(flatCost)
                                : static_cast<std::int64_t>(seg_len) * cnt1 *
                                      static_cast<std::int64_t>(encCost);
        if (k < num_levels && (seg_len % 2) == 0) {
          const std::int64_t split_cost =
              memo[k + 1][2 * i] + memo[k + 1][(2 * i) + 1];
          cost = std::min(cost, split_cost);
        }
        memo[k][i] = cost;
      }
      if (k == 0) {
        break;
      }
    }
    return memo[0][0];
  }
};