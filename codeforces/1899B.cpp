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
#include <iostream>
#include <limits>
#include <vector>

void solve() {
  int tests{};
  std::cin >> tests;

  while ((tests--) != 0) {
    std::size_t size{};
    std::cin >> size;

    std::vector<std::size_t> prefix_sums;
    prefix_sums.reserve(size + 1);
    prefix_sums.push_back(0);

    std::size_t sum{0};
    for (std::size_t i{1}; i <= size; i++) {
      std::size_t num{};
      std::cin >> num;
      sum += num;
      prefix_sums.push_back(sum);
    }

    std::size_t ans{0};
    for (std::size_t i{1}; i <= size; i++) {
      if (size % i != 0) {
        continue;
      }

      // std::cout << "I: " << i << "\n";

      std::size_t max_sum{0};
      std::size_t min_sum{std::numeric_limits<std::size_t>::max()};

      for (std::size_t j{i}; j <= size; j += i) {
        max_sum = std::max(max_sum, prefix_sums[j] - prefix_sums[j - i]);
        min_sum = std::min(min_sum, prefix_sums[j] - prefix_sums[j - i]);
      }

      // std::cout << "MAX_SUM: " << max_sum << " MIN_SUM: " << min_sum << "\n";
      // std::cout << "I: " << i << "\n";

      ans = std::max(ans, max_sum - min_sum);
    }

    std::cout << ans << "\n";
  }
}