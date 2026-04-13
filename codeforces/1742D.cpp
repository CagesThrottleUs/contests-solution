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
#include <iostream>
#include <numeric>
#include <vector>

constexpr std::size_t MAX_VAL = 1000;

void solve() {
  std::uint32_t tests{};
  std::cin >> tests;

  std::vector<std::vector<std::size_t>> gcd_table(MAX_VAL + 1,
                                                  std::vector<std::size_t>());

  for (std::size_t i{1}; i <= MAX_VAL; i++) {
    for (std::size_t j{1}; j <= MAX_VAL; j++) {
      if (std::gcd(i, j) == 1) {
        gcd_table[i].push_back(j);
      }
    }
  }

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::size_t> last(MAX_VAL + 1, 0);

    for (std::size_t i{0}; i < size; i++) {
      std::size_t num{};
      std::cin >> num;
      last[num] = i + 1;
    }

    // For each value v in [1, 1000], store the last (rightmost) index.
    // Values are bounded by 1000, so only 1000 distinct values exist.
    // For any co-prime pair (v1, v2), the optimal i+j uses last[v1]+last[v2].

    // Check all O(1000^2) value pairs — only 1000 distinct values possible
    std::int64_t max_ans = -1;
    for (std::size_t first = 1; first < MAX_VAL; first++) {
      if (last[first] == 0) {
        continue;
      }
      for (const auto& second : gcd_table[first]) {
        if (last[second] == 0) {
          continue;
        }
        auto candidate = static_cast<std::int64_t>(last[first]) +
                         static_cast<std::int64_t>(last[second]);
        max_ans = std::max(max_ans, candidate);
      }
    }

    std::cout << max_ans << "\n";
  }
}